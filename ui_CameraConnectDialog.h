/********************************************************************************
** Form generated from reading UI file 'CameraConnectDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERACONNECTDIALOG_H
#define UI_CAMERACONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraConnectDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QLineEdit *deviceNumberEdit;
    QSpacerItem *horizontalSpacer_1;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QLineEdit *resWEdit;
    QLabel *label_13;
    QLineEdit *resHEdit;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *imageBufferSizeEdit;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *dropFrameCheckBox;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QComboBox *capturePrioComboBox;
    QComboBox *processingPrioComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLineEdit *tabLabelEdit;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *enableFrameProcessingCheckBox;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *resetToDefaultsPushButton;
    QDialogButtonBox *okCancelBox;

    void setupUi(QDialog *CameraConnectDialog)
    {
        if (CameraConnectDialog->objectName().isEmpty())
            CameraConnectDialog->setObjectName(QString::fromUtf8("CameraConnectDialog"));
        CameraConnectDialog->resize(410, 371);
        layoutWidget = new QWidget(CameraConnectDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 391, 351));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_1 = new QLabel(layoutWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label_1->setFont(font);

        verticalLayout_3->addWidget(label_1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        label_9->setFont(font1);

        horizontalLayout_2->addWidget(label_9);

        deviceNumberEdit = new QLineEdit(layoutWidget);
        deviceNumberEdit->setObjectName(QString::fromUtf8("deviceNumberEdit"));
        deviceNumberEdit->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deviceNumberEdit->sizePolicy().hasHeightForWidth());
        deviceNumberEdit->setSizePolicy(sizePolicy);
        deviceNumberEdit->setMinimumSize(QSize(50, 0));
        deviceNumberEdit->setMaximumSize(QSize(50, 16777215));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        deviceNumberEdit->setFont(font2);

        horizontalLayout_2->addWidget(deviceNumberEdit);

        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_1);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);

        horizontalLayout_8->addWidget(label_11);

        resWEdit = new QLineEdit(layoutWidget);
        resWEdit->setObjectName(QString::fromUtf8("resWEdit"));
        resWEdit->setEnabled(true);
        sizePolicy.setHeightForWidth(resWEdit->sizePolicy().hasHeightForWidth());
        resWEdit->setSizePolicy(sizePolicy);
        resWEdit->setMinimumSize(QSize(50, 0));
        resWEdit->setMaximumSize(QSize(50, 16777215));
        resWEdit->setFont(font2);

        horizontalLayout_8->addWidget(resWEdit);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);

        horizontalLayout_8->addWidget(label_13);

        resHEdit = new QLineEdit(layoutWidget);
        resHEdit->setObjectName(QString::fromUtf8("resHEdit"));
        resHEdit->setEnabled(true);
        sizePolicy.setHeightForWidth(resHEdit->sizePolicy().hasHeightForWidth());
        resHEdit->setSizePolicy(sizePolicy);
        resHEdit->setMinimumSize(QSize(50, 0));
        resHEdit->setMaximumSize(QSize(50, 16777215));
        resHEdit->setFont(font2);

        horizontalLayout_8->addWidget(resHEdit);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        horizontalLayout_8->addWidget(label_12);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_8);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        imageBufferSizeEdit = new QLineEdit(layoutWidget);
        imageBufferSizeEdit->setObjectName(QString::fromUtf8("imageBufferSizeEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(imageBufferSizeEdit->sizePolicy().hasHeightForWidth());
        imageBufferSizeEdit->setSizePolicy(sizePolicy1);
        imageBufferSizeEdit->setMinimumSize(QSize(50, 0));
        imageBufferSizeEdit->setMaximumSize(QSize(50, 16777215));
        QFont font3;
        font3.setPointSize(9);
        imageBufferSizeEdit->setFont(font3);

        horizontalLayout->addWidget(imageBufferSizeEdit);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        dropFrameCheckBox = new QCheckBox(layoutWidget);
        dropFrameCheckBox->setObjectName(QString::fromUtf8("dropFrameCheckBox"));
        dropFrameCheckBox->setFont(font3);

        verticalLayout_3->addWidget(dropFrameCheckBox);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        verticalLayout_3->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        verticalLayout->addWidget(label_7);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        capturePrioComboBox = new QComboBox(layoutWidget);
        capturePrioComboBox->setObjectName(QString::fromUtf8("capturePrioComboBox"));
        capturePrioComboBox->setFont(font3);

        verticalLayout_2->addWidget(capturePrioComboBox);

        processingPrioComboBox = new QComboBox(layoutWidget);
        processingPrioComboBox->setObjectName(QString::fromUtf8("processingPrioComboBox"));
        processingPrioComboBox->setFont(font3);

        verticalLayout_2->addWidget(processingPrioComboBox);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        horizontalLayout_5->addWidget(label_8);

        tabLabelEdit = new QLineEdit(layoutWidget);
        tabLabelEdit->setObjectName(QString::fromUtf8("tabLabelEdit"));
        tabLabelEdit->setFont(font3);

        horizontalLayout_5->addWidget(tabLabelEdit);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        enableFrameProcessingCheckBox = new QCheckBox(layoutWidget);
        enableFrameProcessingCheckBox->setObjectName(QString::fromUtf8("enableFrameProcessingCheckBox"));
        QFont font4;
        font4.setPointSize(10);
        enableFrameProcessingCheckBox->setFont(font4);

        horizontalLayout_7->addWidget(enableFrameProcessingCheckBox);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_4->addLayout(verticalLayout_3);

        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        resetToDefaultsPushButton = new QPushButton(layoutWidget);
        resetToDefaultsPushButton->setObjectName(QString::fromUtf8("resetToDefaultsPushButton"));

        horizontalLayout_4->addWidget(resetToDefaultsPushButton);

        okCancelBox = new QDialogButtonBox(layoutWidget);
        okCancelBox->setObjectName(QString::fromUtf8("okCancelBox"));
        okCancelBox->setOrientation(Qt::Horizontal);
        okCancelBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_4->addWidget(okCancelBox);


        verticalLayout_4->addLayout(horizontalLayout_4);


        retranslateUi(CameraConnectDialog);
        QObject::connect(okCancelBox, SIGNAL(accepted()), CameraConnectDialog, SLOT(accept()));
        QObject::connect(okCancelBox, SIGNAL(rejected()), CameraConnectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CameraConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *CameraConnectDialog)
    {
        CameraConnectDialog->setWindowTitle(QApplication::translate("CameraConnectDialog", "Connect to Camera", nullptr));
        label_1->setText(QApplication::translate("CameraConnectDialog", "Camera:", nullptr));
        label_9->setText(QApplication::translate("CameraConnectDialog", "Device Number:", nullptr));
        label_11->setText(QApplication::translate("CameraConnectDialog", "Resolution (W x H):", nullptr));
        label_13->setText(QApplication::translate("CameraConnectDialog", "x", nullptr));
        label_12->setText(QApplication::translate("CameraConnectDialog", "[optional]", nullptr));
        label_3->setText(QApplication::translate("CameraConnectDialog", "Image Buffer:", nullptr));
        label_2->setText(QApplication::translate("CameraConnectDialog", "Size (number of images/frames):", nullptr));
        label_4->setText(QApplication::translate("CameraConnectDialog", "[1-999]", nullptr));
        dropFrameCheckBox->setText(QApplication::translate("CameraConnectDialog", "Drop frame if image buffer is full", nullptr));
        label_5->setText(QApplication::translate("CameraConnectDialog", "Thread Priorities:", nullptr));
        label_6->setText(QApplication::translate("CameraConnectDialog", "Capture Thread:", nullptr));
        label_7->setText(QApplication::translate("CameraConnectDialog", "Processing Thread:", nullptr));
        label_8->setText(QApplication::translate("CameraConnectDialog", "Tab Label:", nullptr));
        enableFrameProcessingCheckBox->setText(QApplication::translate("CameraConnectDialog", "Enable frame processing", nullptr));
        resetToDefaultsPushButton->setText(QApplication::translate("CameraConnectDialog", "Reset to Defaults", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraConnectDialog: public Ui_CameraConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERACONNECTDIALOG_H
