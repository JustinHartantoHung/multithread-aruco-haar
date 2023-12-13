/****************************************************************************
** Meta object code from reading C++ file 'ImageProcessingSettingsDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ImageProcessingSettingsDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageProcessingSettingsDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageProcessingSettingsDialog_t {
    QByteArrayData data[15];
    char stringdata0[334];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageProcessingSettingsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageProcessingSettingsDialog_t qt_meta_stringdata_ImageProcessingSettingsDialog = {
    {
QT_MOC_LITERAL(0, 0, 29), // "ImageProcessingSettingsDialog"
QT_MOC_LITERAL(1, 30, 26), // "newImageProcessingSettings"
QT_MOC_LITERAL(2, 57, 0), // ""
QT_MOC_LITERAL(3, 58, 23), // "ImageProcessingSettings"
QT_MOC_LITERAL(4, 82, 10), // "p_settings"
QT_MOC_LITERAL(5, 93, 24), // "resetAllDialogToDefaults"
QT_MOC_LITERAL(6, 118, 30), // "updateStoredSettingsFromDialog"
QT_MOC_LITERAL(7, 149, 27), // "resetSmoothDialogToDefaults"
QT_MOC_LITERAL(8, 177, 27), // "resetDilateDialogToDefaults"
QT_MOC_LITERAL(9, 205, 26), // "resetErodeDialogToDefaults"
QT_MOC_LITERAL(10, 232, 25), // "resetFlipDialogToDefaults"
QT_MOC_LITERAL(11, 258, 26), // "resetCannyDialogToDefaults"
QT_MOC_LITERAL(12, 285, 14), // "validateDialog"
QT_MOC_LITERAL(13, 300, 16), // "smoothTypeChange"
QT_MOC_LITERAL(14, 317, 16) // "QAbstractButton*"

    },
    "ImageProcessingSettingsDialog\0"
    "newImageProcessingSettings\0\0"
    "ImageProcessingSettings\0p_settings\0"
    "resetAllDialogToDefaults\0"
    "updateStoredSettingsFromDialog\0"
    "resetSmoothDialogToDefaults\0"
    "resetDilateDialogToDefaults\0"
    "resetErodeDialogToDefaults\0"
    "resetFlipDialogToDefaults\0"
    "resetCannyDialogToDefaults\0validateDialog\0"
    "smoothTypeChange\0QAbstractButton*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageProcessingSettingsDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,
      12,    0,   74,    2, 0x08 /* Private */,
      13,    1,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,    2,

       0        // eod
};

void ImageProcessingSettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImageProcessingSettingsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newImageProcessingSettings((*reinterpret_cast< ImageProcessingSettings(*)>(_a[1]))); break;
        case 1: _t->resetAllDialogToDefaults(); break;
        case 2: _t->updateStoredSettingsFromDialog(); break;
        case 3: _t->resetSmoothDialogToDefaults(); break;
        case 4: _t->resetDilateDialogToDefaults(); break;
        case 5: _t->resetErodeDialogToDefaults(); break;
        case 6: _t->resetFlipDialogToDefaults(); break;
        case 7: _t->resetCannyDialogToDefaults(); break;
        case 8: _t->validateDialog(); break;
        case 9: _t->smoothTypeChange((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ImageProcessingSettingsDialog::*)(ImageProcessingSettings );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageProcessingSettingsDialog::newImageProcessingSettings)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ImageProcessingSettingsDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_ImageProcessingSettingsDialog.data,
    qt_meta_data_ImageProcessingSettingsDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ImageProcessingSettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageProcessingSettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageProcessingSettingsDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ImageProcessingSettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ImageProcessingSettingsDialog::newImageProcessingSettings(ImageProcessingSettings _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
