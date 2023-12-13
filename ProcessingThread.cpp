/************************************************************************/
/* qt-opencv-multithreaded:                                             */
/* A multithreaded OpenCV application using the Qt framework.           */
/*                                                                      */
/* ProcessingThread.cpp                                                 */
/*                                                                      */
/* Nick D'Ademo <nickdademo@gmail.com>                                  */
/*                                                                      */
/* Copyright (c) 2012-2013 Nick D'Ademo                                 */
/*                                                                      */
/* Permission is hereby granted, free of charge, to any person          */
/* obtaining a copy of this software and associated documentation       */
/* files (the "Software"), to deal in the Software without restriction, */
/* including without limitation the rights to use, copy, modify, merge, */
/* publish, distribute, sublicense, and/or sell copies of the Software, */
/* and to permit persons to whom the Software is furnished to do so,    */
/* subject to the following conditions:                                 */
/*                                                                      */
/* The above copyright notice and this permission notice shall be       */
/* included in all copies or substantial portions of the Software.      */
/*                                                                      */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,      */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF   */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND                */
/* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  */
/* BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN   */
/* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN    */
/* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE     */
/* SOFTWARE.                                                            */
/*                                                                      */
/************************************************************************/

#include "ProcessingThread.h"
#include "MainWindow.h"
#include <math.h>
#include <iostream>
//#include <iomanip>
#include <opencv2/aruco.hpp>
#include <opencv2/calib3d.hpp>


using namespace cv;
using namespace std;
using namespace aruco;

ProcessingThread::ProcessingThread(SharedImageBuffer *sharedImageBuffer, int deviceNumber) : QThread(), sharedImageBuffer(sharedImageBuffer)
{
    // Save Device Number
    this->deviceNumber=deviceNumber;
    // Initialize members
    doStop=false;
    sampleNumber=0;
    fpsSum=0;
    fps.clear();
    statsData.averageFPS=0;
    statsData.nFramesProcessed=0;

    // Webcam ArUco calib
    cameraMatrix = (Mat_<double>(3,3) << 6.4509151670288645e+02, 0., 3.3595607517914726e+02, 0., 6.4326487034230729e+02, 2.3680853197408831e+02, 0., 0., 1.);
    distCoeffs = (Mat_<double>(1,5) << -2.5825073187425829e-02, 3.3262700060646667e-02, -9.3844788935797275e-03, 3.0333854776571413e-03, -9.9723801531059572e-02);
    MarkerSizeinMetres = 0.145;

    //Sharpening
    sharpeningKernel = (Mat_<double>(3,3) <<
                            0,  -1,  0,
                        -1,  5, -1,
                        0, -1,  0);

    //Cascade xml
    facecascade_filename_ = "resources/haarcascade_frontalface_default.xml";
    eyecascade_filename_ = "resources/haarcascade_eye.xml";
    cascadeLoadFiles(facecascade_filename_.toStdString().c_str(),
              eyecascade_filename_.toStdString().c_str());

}

void ProcessingThread::run()
{
    while(1)
    {
        ////////////////////////////////
        // Stop thread if doStop=TRUE //
        ////////////////////////////////
        doStopMutex.lock();
        if(doStop)
        {
            doStop=false;
            doStopMutex.unlock();
            break;
        }
        doStopMutex.unlock();
        /////////////////////////////////
        /////////////////////////////////

        // Save processing time
        processingTime=t.elapsed();
        // Start timer (used to calculate processing rate)
        t.start();

        processingMutex.lock();
        // Get frame from queue, store in currentFrame, set ROI
        currentFrame=Mat(sharedImageBuffer->getByDeviceNumber(deviceNumber)->get().clone(), currentROI);

        // Example of how to grab a frame from another stream (where Device Number=1)
        // Note: This requires stream synchronization to be ENABLED (in the Options menu of MainWindow) and frame processing for the stream you are grabbing FROM to be DISABLED.
        /*
        if(sharedImageBuffer->containsImageBufferForDeviceNumber(1))
        {
            // Grab frame from another stream (connected to camera with Device Number=1)
            Mat frameFromAnotherStream = Mat(sharedImageBuffer->getByDeviceNumber(1)->getFrame(), currentROI);
            // Linear blend images together using OpenCV and save the result to currentFrame. Note: beta=1-alpha
            addWeighted(frameFromAnotherStream, 0.5, currentFrame, 0.5, 0.0, currentFrame);
        }
        */

        ////////////////////////////////////
        // PERFORM IMAGE PROCESSING BELOW //
        ////////////////////////////////////
        // Grayscale conversion (in-place operation)
        if(imgProcFlags.grayscaleOn && (currentFrame.channels() == 3 || currentFrame.channels() == 4))
            cvtColor(currentFrame, currentFrame, COLOR_BGR2GRAY);

        // Smooth (in-place operations)
        if(imgProcFlags.smoothOn)
        {
            switch(imgProcSettings.smoothType)
            {
                // BLUR
                case 0:
                    blur(currentFrame, currentFrame,
                         Size(imgProcSettings.smoothParam1, imgProcSettings.smoothParam2));
                    break;
                // GAUSSIAN
                case 1:
                    GaussianBlur(currentFrame, currentFrame,
                                 Size(imgProcSettings.smoothParam1, imgProcSettings.smoothParam2),
                                 imgProcSettings.smoothParam3, imgProcSettings.smoothParam4);
                    break;
                // MEDIAN
                case 2:
                    medianBlur(currentFrame, currentFrame,
                               imgProcSettings.smoothParam1);
                    break;
            }
        }

        //Sharpening
        if(imgProcFlags.sharpeningOn)
        {
                    filter2D(currentFrame, currentFrame, -1 , sharpeningKernel , Point(-1, -1), 0, BORDER_DEFAULT);
        }

        // Dilate
        if(imgProcFlags.dilateOn)
        {
            dilate(currentFrame, currentFrame,
                   Mat(), Point(-1, -1), imgProcSettings.dilateNumberOfIterations);
        }
        // Erode
        if(imgProcFlags.erodeOn)
        {
            erode(currentFrame, currentFrame,
                  Mat(), Point(-1, -1), imgProcSettings.erodeNumberOfIterations);
        }
        // Flip
        if(imgProcFlags.flipOn)
        {
            flip(currentFrame, currentFrame,
                 imgProcSettings.flipCode);
        }
        // Canny edge detection
        if(imgProcFlags.cannyOn)
        {
            Canny(currentFrame, currentFrame,
                  imgProcSettings.cannyThreshold1, imgProcSettings.cannyThreshold2,
                  imgProcSettings.cannyApertureSize, imgProcSettings.cannyL2gradient);
        }

        if(imgProcFlags.ArucoOn)
        {
            //Aru tag detection
            t_aruco = (double) getTickCount();
            detectMarkers(currentFrame,dictionary,corners,ids);
        }
qDebug() << "eyeDetectionOn " << imgProcFlags.eyeDetectionOn;
        if(imgProcFlags.faceDetectionOn || imgProcFlags.eyeDetectionOn) //Face detection
        {
            cv::Mat grey_image;
            cv::cvtColor(currentFrame, grey_image, cv::COLOR_BGRA2GRAY);
            cv::equalizeHist(grey_image, grey_image);

            // Calculate the camera size and set the size to 1/8 of screen height
            faceCascade.detectMultiScale(grey_image, faces, 1.1, 2,  0|cv::CASCADE_SCALE_IMAGE,
                                         cv::Size(currentFrame.cols/8, currentFrame.rows/8)); // Minimum size of obj

 //           qDebug() << "face" << faces.size();
        }

        if(imgProcFlags.eyeDetectionOn)
        {
            for( size_t i = 0; i < faces.size(); i++)
            {
                faceROI = currentFrame( faces[i] );

                //-- In each face, detect eyes
                eyeCascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30) );
qDebug() << "haar eyes detect" << eyes.size();
            }
        }

        //Aruco 3D Pose
        if(imgProcFlags.ArucoOn)
        {
            //Aruco 3D Pose
            if(ids.size() > 0)  // if any markers detected
            {
                    drawDetectedMarkers(currentFrame,corners,ids);

                    // 3D pose
                    vector<Vec3d> rvecs, tvecs;
                    estimatePoseSingleMarkers(corners,MarkerSizeinMetres,cameraMatrix,distCoeffs,rvecs,tvecs);

                    t_aruco = (double) getTickCount() - t_aruco;
                    cout << "detection time = " << (t_aruco*1000./cv::getTickFrequency()) << " ms" << endl;
                    for(unsigned int i = 0; i < ids.size(); i++)
                    {
                        drawAxis(currentFrame, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], 2*MarkerSizeinMetres);

                        /** rvecs, tvecs legend
    rvecs[i][0] about x-axis     (face up/down)           (up-positive, down-negative)                  (up=~pi/2     straight=+-pi     down=~-pi/2)
    rvecs[i][1] about z-axis     (upright/upside down)    (cntrclockwise-positive, clockwise-negative)  (upright=0    upside down=+-pi)
    rvecs[i][2] about y-axis     (face left/right)        (left-positive, right-negative)               (left=~pi/2   straight=0        right=~-pi/2)
    tvecs[i][0] axis merah  (x)  (left/right of center)   (left-positive, right-negative)
    tvecs[i][1] axis ijo    (y)  (above/below center)     (below-positive, above-negative)
    tvecs[i][2] axis biru   (z)  (distance from camera)   (far-large, near-small)
*/
                    }
            }
        }

        //Haar cascade face detection draw
        if(imgProcFlags.faceDetectionOn)
        {
            for( size_t i = 0; i < faces.size(); i++)
            {
                    cv::rectangle(currentFrame, faces[i], cv::Scalar( 255, 0, 255 ));

                    cv::Point center( faces[i].x + faces[i].width*0.5,
                                     faces[i].y + faces[i].height*0.5);

            }
        }

        //Haar cascade face detection draw
        if(imgProcFlags.eyeDetectionOn)
        {
            for( size_t i = 0; i < faces.size(); i++)
            {
                    faceROI = currentFrame( faces[i] );

                    //-- In each face, detect eyes
                    eyeCascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30) );

                    for( size_t j = 0; j < eyes.size(); j++)
                    {
                        cv::Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5,
                                         faces[i].y + eyes[j].y + eyes[j].height*0.5 );
                        int radius = cvRound( (eyes[j].width + eyes[j].height) *0.25);
                        circle( currentFrame, center, radius, cv::Scalar( 255, 0, 0 ), 4, 8, 0);
                    }
                     qDebug() << "draw eyes";
            }
        }


        ////////////////////////////////////
        // PERFORM IMAGE PROCESSING ABOVE //
        ////////////////////////////////////

        // Convert Mat to QImage
        frame=MatToQImage(currentFrame);
        processingMutex.unlock();

        // Inform GUI thread of new frame (QImage)
        emit newFrame(frame);

        // Update statistics
        updateFPS(processingTime);
        statsData.nFramesProcessed++;
        // Inform GUI of updated statistics
        emit updateStatisticsInGUI(statsData);
        emit updateFaceDetected(faces.size());
    }
    qDebug() << "Stopping processing thread...";
}

void ProcessingThread::updateFPS(int timeElapsed)
{
    // Add instantaneous FPS value to queue
    if(timeElapsed>0)
    {
        fps.enqueue((int)1000/timeElapsed);
        // Increment sample number
        sampleNumber++;
    }

    // Maximum size of queue is DEFAULT_PROCESSING_FPS_STAT_QUEUE_LENGTH
    if(fps.size()>PROCESSING_FPS_STAT_QUEUE_LENGTH)
        fps.dequeue();

    // Update FPS value every DEFAULT_PROCESSING_FPS_STAT_QUEUE_LENGTH samples
    if((fps.size()==PROCESSING_FPS_STAT_QUEUE_LENGTH)&&(sampleNumber==PROCESSING_FPS_STAT_QUEUE_LENGTH))
    {
        // Empty queue and store sum
        while(!fps.empty())
            fpsSum+=fps.dequeue();
        // Calculate average FPS
        statsData.averageFPS=fpsSum/PROCESSING_FPS_STAT_QUEUE_LENGTH;
        // Reset sum
        fpsSum=0;
        // Reset sample number
        sampleNumber=0;
    }
}

void ProcessingThread::stop()
{
    QMutexLocker locker(&doStopMutex);
    doStop=true;
}

void ProcessingThread::updateImageProcessingFlags(struct ImageProcessingFlags imgProcFlags)
{
    QMutexLocker locker(&processingMutex);
    this->imgProcFlags.grayscaleOn=imgProcFlags.grayscaleOn;
    this->imgProcFlags.smoothOn=imgProcFlags.smoothOn;
    this->imgProcFlags.dilateOn=imgProcFlags.dilateOn;
    this->imgProcFlags.erodeOn=imgProcFlags.erodeOn;
    this->imgProcFlags.flipOn=imgProcFlags.flipOn;
    this->imgProcFlags.cannyOn=imgProcFlags.cannyOn;
    this->imgProcFlags.ArucoOn=imgProcFlags.ArucoOn;
    this->imgProcFlags.sharpeningOn=imgProcFlags.sharpeningOn;
    this->imgProcFlags.faceDetectionOn=imgProcFlags.faceDetectionOn;
    this->imgProcFlags.eyeDetectionOn=imgProcFlags.eyeDetectionOn;

}

void ProcessingThread::updateImageProcessingSettings(struct ImageProcessingSettings imgProcSettings)
{
    QMutexLocker locker(&processingMutex);
    this->imgProcSettings.smoothType=imgProcSettings.smoothType;
    this->imgProcSettings.smoothParam1=imgProcSettings.smoothParam1;
    this->imgProcSettings.smoothParam2=imgProcSettings.smoothParam2;
    this->imgProcSettings.smoothParam3=imgProcSettings.smoothParam3;
    this->imgProcSettings.smoothParam4=imgProcSettings.smoothParam4;
    this->imgProcSettings.dilateNumberOfIterations=imgProcSettings.dilateNumberOfIterations;
    this->imgProcSettings.erodeNumberOfIterations=imgProcSettings.erodeNumberOfIterations;
    this->imgProcSettings.flipCode=imgProcSettings.flipCode;
    this->imgProcSettings.cannyThreshold1=imgProcSettings.cannyThreshold1;
    this->imgProcSettings.cannyThreshold2=imgProcSettings.cannyThreshold2;
    this->imgProcSettings.cannyApertureSize=imgProcSettings.cannyApertureSize;
    this->imgProcSettings.cannyL2gradient=imgProcSettings.cannyL2gradient;
}

void ProcessingThread::setROI(QRect roi)
{
    QMutexLocker locker(&processingMutex);
    currentROI.x = roi.x();
    currentROI.y = roi.y();
    currentROI.width = roi.width();
    currentROI.height = roi.height();
}

QRect ProcessingThread::getCurrentROI()
{
    return QRect(currentROI.x, currentROI.y, currentROI.width, currentROI.height);
}

void ProcessingThread::cascadeLoadFiles(cv::String faceCascadeFilename,
                             cv::String eyeCascadeFilename)
{
    // TODO: Add in a try catch statement here
    if( !faceCascade.load( faceCascadeFilename ) )
    {
        std::cout << "Error Loading" << faceCascadeFilename << std::endl;
    }

    if( !eyeCascade.load( eyeCascadeFilename ) )
    {
        std::cout << "Error Loading" << eyeCascadeFilename << std::endl;
    }
}
