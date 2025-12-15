/****************************************************************************
** Meta object code from reading C++ file 'frmImageSource.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmImageSource.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmImageSource.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmImageSource_t {
    QByteArrayData data[32];
    char stringdata0[585];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmImageSource_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmImageSource_t qt_meta_stringdata_frmImageSource = {
    {
QT_MOC_LITERAL(0, 0, 14), // "frmImageSource"
QT_MOC_LITERAL(1, 15, 21), // "imageCapturedInMemory"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 2), // "id"
QT_MOC_LITERAL(4, 41, 5), // "image"
QT_MOC_LITERAL(5, 47, 20), // "imageBufferAvailable"
QT_MOC_LITERAL(6, 68, 11), // "sig_Message"
QT_MOC_LITERAL(7, 80, 15), // "sig_PathMessage"
QT_MOC_LITERAL(8, 96, 23), // "sig_ShowBlockageWarning"
QT_MOC_LITERAL(9, 120, 23), // "sig_HideBlockageWarning"
QT_MOC_LITERAL(10, 144, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(11, 165, 25), // "on_btnSelectImage_clicked"
QT_MOC_LITERAL(12, 191, 24), // "on_btnSelectPath_clicked"
QT_MOC_LITERAL(13, 216, 29), // "on_btnSelectCalibPath_clicked"
QT_MOC_LITERAL(14, 246, 30), // "on_btnLinkCameraMatrix_clicked"
QT_MOC_LITERAL(15, 277, 33), // "on_btnDelLinkCameraMatrix_cli..."
QT_MOC_LITERAL(16, 311, 28), // "on_btnLinkDistCoeffs_clicked"
QT_MOC_LITERAL(17, 340, 31), // "on_btnDelLinkDistCoeffs_clicked"
QT_MOC_LITERAL(18, 372, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(19, 394, 20), // "on_btnUpdata_clicked"
QT_MOC_LITERAL(20, 415, 34), // "on_comboCamera_currentIndexCh..."
QT_MOC_LITERAL(21, 450, 5), // "index"
QT_MOC_LITERAL(22, 456, 12), // "onRadioClick"
QT_MOC_LITERAL(23, 469, 17), // "onCalibRadioClick"
QT_MOC_LITERAL(24, 487, 10), // "ReadBuffer"
QT_MOC_LITERAL(25, 498, 22), // "m_nBufSizeForSaveImage"
QT_MOC_LITERAL(26, 521, 12), // "m_hDevHandle"
QT_MOC_LITERAL(27, 534, 8), // "cv::Mat&"
QT_MOC_LITERAL(28, 543, 7), // "timeout"
QT_MOC_LITERAL(29, 551, 3), // "key"
QT_MOC_LITERAL(30, 555, 12), // "slot_Message"
QT_MOC_LITERAL(31, 568, 16) // "slot_PathMessage"

    },
    "frmImageSource\0imageCapturedInMemory\0"
    "\0id\0image\0imageBufferAvailable\0"
    "sig_Message\0sig_PathMessage\0"
    "sig_ShowBlockageWarning\0sig_HideBlockageWarning\0"
    "onButtonCloseClicked\0on_btnSelectImage_clicked\0"
    "on_btnSelectPath_clicked\0"
    "on_btnSelectCalibPath_clicked\0"
    "on_btnLinkCameraMatrix_clicked\0"
    "on_btnDelLinkCameraMatrix_clicked\0"
    "on_btnLinkDistCoeffs_clicked\0"
    "on_btnDelLinkDistCoeffs_clicked\0"
    "on_btnExecute_clicked\0on_btnUpdata_clicked\0"
    "on_comboCamera_currentIndexChanged\0"
    "index\0onRadioClick\0onCalibRadioClick\0"
    "ReadBuffer\0m_nBufSizeForSaveImage\0"
    "m_hDevHandle\0cv::Mat&\0timeout\0key\0"
    "slot_Message\0slot_PathMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmImageSource[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  129,    2, 0x06 /* Public */,
       5,    2,  134,    2, 0x06 /* Public */,
       6,    0,  139,    2, 0x06 /* Public */,
       7,    0,  140,    2, 0x06 /* Public */,
       8,    0,  141,    2, 0x06 /* Public */,
       9,    0,  142,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  143,    2, 0x08 /* Private */,
      11,    0,  144,    2, 0x08 /* Private */,
      12,    0,  145,    2, 0x08 /* Private */,
      13,    0,  146,    2, 0x08 /* Private */,
      14,    0,  147,    2, 0x08 /* Private */,
      15,    0,  148,    2, 0x08 /* Private */,
      16,    0,  149,    2, 0x08 /* Private */,
      17,    0,  150,    2, 0x08 /* Private */,
      18,    0,  151,    2, 0x08 /* Private */,
      19,    0,  152,    2, 0x08 /* Private */,
      20,    1,  153,    2, 0x08 /* Private */,
      22,    1,  156,    2, 0x08 /* Private */,
      23,    1,  159,    2, 0x08 /* Private */,
      24,    4,  162,    2, 0x08 /* Private */,
      24,    4,  171,    2, 0x08 /* Private */,
      30,    0,  180,    2, 0x08 /* Private */,
      31,    0,  181,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Int, QMetaType::UInt, QMetaType::VoidStar, 0x80000000 | 27, QMetaType::Int,   25,   26,    4,   28,
    QMetaType::Int, QMetaType::UInt, QMetaType::VoidStar, 0x80000000 | 27, QMetaType::QString,   25,   26,    4,   29,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmImageSource::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmImageSource *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageCapturedInMemory((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2]))); break;
        case 1: _t->imageBufferAvailable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2]))); break;
        case 2: _t->sig_Message(); break;
        case 3: _t->sig_PathMessage(); break;
        case 4: _t->sig_ShowBlockageWarning(); break;
        case 5: _t->sig_HideBlockageWarning(); break;
        case 6: _t->onButtonCloseClicked(); break;
        case 7: _t->on_btnSelectImage_clicked(); break;
        case 8: _t->on_btnSelectPath_clicked(); break;
        case 9: _t->on_btnSelectCalibPath_clicked(); break;
        case 10: _t->on_btnLinkCameraMatrix_clicked(); break;
        case 11: _t->on_btnDelLinkCameraMatrix_clicked(); break;
        case 12: _t->on_btnLinkDistCoeffs_clicked(); break;
        case 13: _t->on_btnDelLinkDistCoeffs_clicked(); break;
        case 14: _t->on_btnExecute_clicked(); break;
        case 15: _t->on_btnUpdata_clicked(); break;
        case 16: _t->on_comboCamera_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->onRadioClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->onCalibRadioClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: { int _r = _t->ReadBuffer((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2])),(*reinterpret_cast< cv::Mat(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 20: { int _r = _t->ReadBuffer((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2])),(*reinterpret_cast< cv::Mat(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 21: _t->slot_Message(); break;
        case 22: _t->slot_PathMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmImageSource::*)(int , const QImage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageSource::imageCapturedInMemory)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmImageSource::*)(int , const QImage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageSource::imageBufferAvailable)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (frmImageSource::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageSource::sig_Message)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (frmImageSource::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageSource::sig_PathMessage)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (frmImageSource::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageSource::sig_ShowBlockageWarning)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (frmImageSource::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageSource::sig_HideBlockageWarning)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmImageSource::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmImageSource.data,
    qt_meta_data_frmImageSource,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmImageSource::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmImageSource::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmImageSource.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmImageSource::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void frmImageSource::imageCapturedInMemory(int _t1, const QImage & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void frmImageSource::imageBufferAvailable(int _t1, const QImage & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void frmImageSource::sig_Message()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void frmImageSource::sig_PathMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void frmImageSource::sig_ShowBlockageWarning()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void frmImageSource::sig_HideBlockageWarning()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
