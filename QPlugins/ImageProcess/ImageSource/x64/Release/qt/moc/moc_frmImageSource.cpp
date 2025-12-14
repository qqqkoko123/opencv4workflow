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
    QByteArrayData data[29];
    char stringdata0[539];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmImageSource_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmImageSource_t qt_meta_stringdata_frmImageSource = {
    {
QT_MOC_LITERAL(0, 0, 14), // "frmImageSource"
QT_MOC_LITERAL(1, 15, 11), // "sig_Message"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "sig_PathMessage"
QT_MOC_LITERAL(4, 44, 23), // "sig_ShowBlockageWarning"
QT_MOC_LITERAL(5, 68, 23), // "sig_HideBlockageWarning"
QT_MOC_LITERAL(6, 92, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(7, 113, 25), // "on_btnSelectImage_clicked"
QT_MOC_LITERAL(8, 139, 24), // "on_btnSelectPath_clicked"
QT_MOC_LITERAL(9, 164, 29), // "on_btnSelectCalibPath_clicked"
QT_MOC_LITERAL(10, 194, 30), // "on_btnLinkCameraMatrix_clicked"
QT_MOC_LITERAL(11, 225, 33), // "on_btnDelLinkCameraMatrix_cli..."
QT_MOC_LITERAL(12, 259, 28), // "on_btnLinkDistCoeffs_clicked"
QT_MOC_LITERAL(13, 288, 31), // "on_btnDelLinkDistCoeffs_clicked"
QT_MOC_LITERAL(14, 320, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(15, 342, 20), // "on_btnUpdata_clicked"
QT_MOC_LITERAL(16, 363, 34), // "on_comboCamera_currentIndexCh..."
QT_MOC_LITERAL(17, 398, 5), // "index"
QT_MOC_LITERAL(18, 404, 12), // "onRadioClick"
QT_MOC_LITERAL(19, 417, 17), // "onCalibRadioClick"
QT_MOC_LITERAL(20, 435, 10), // "ReadBuffer"
QT_MOC_LITERAL(21, 446, 22), // "m_nBufSizeForSaveImage"
QT_MOC_LITERAL(22, 469, 12), // "m_hDevHandle"
QT_MOC_LITERAL(23, 482, 8), // "cv::Mat&"
QT_MOC_LITERAL(24, 491, 5), // "image"
QT_MOC_LITERAL(25, 497, 7), // "timeout"
QT_MOC_LITERAL(26, 505, 3), // "key"
QT_MOC_LITERAL(27, 509, 12), // "slot_Message"
QT_MOC_LITERAL(28, 522, 16) // "slot_PathMessage"

    },
    "frmImageSource\0sig_Message\0\0sig_PathMessage\0"
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
    "m_hDevHandle\0cv::Mat&\0image\0timeout\0"
    "key\0slot_Message\0slot_PathMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmImageSource[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x06 /* Public */,
       3,    0,  120,    2, 0x06 /* Public */,
       4,    0,  121,    2, 0x06 /* Public */,
       5,    0,  122,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  123,    2, 0x08 /* Private */,
       7,    0,  124,    2, 0x08 /* Private */,
       8,    0,  125,    2, 0x08 /* Private */,
       9,    0,  126,    2, 0x08 /* Private */,
      10,    0,  127,    2, 0x08 /* Private */,
      11,    0,  128,    2, 0x08 /* Private */,
      12,    0,  129,    2, 0x08 /* Private */,
      13,    0,  130,    2, 0x08 /* Private */,
      14,    0,  131,    2, 0x08 /* Private */,
      15,    0,  132,    2, 0x08 /* Private */,
      16,    1,  133,    2, 0x08 /* Private */,
      18,    1,  136,    2, 0x08 /* Private */,
      19,    1,  139,    2, 0x08 /* Private */,
      20,    4,  142,    2, 0x08 /* Private */,
      20,    4,  151,    2, 0x08 /* Private */,
      27,    0,  160,    2, 0x08 /* Private */,
      28,    0,  161,    2, 0x08 /* Private */,

 // signals: parameters
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
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Int, QMetaType::UInt, QMetaType::VoidStar, 0x80000000 | 23, QMetaType::Int,   21,   22,   24,   25,
    QMetaType::Int, QMetaType::UInt, QMetaType::VoidStar, 0x80000000 | 23, QMetaType::QString,   21,   22,   24,   26,
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
        case 0: _t->sig_Message(); break;
        case 1: _t->sig_PathMessage(); break;
        case 2: _t->sig_ShowBlockageWarning(); break;
        case 3: _t->sig_HideBlockageWarning(); break;
        case 4: _t->onButtonCloseClicked(); break;
        case 5: _t->on_btnSelectImage_clicked(); break;
        case 6: _t->on_btnSelectPath_clicked(); break;
        case 7: _t->on_btnSelectCalibPath_clicked(); break;
        case 8: _t->on_btnLinkCameraMatrix_clicked(); break;
        case 9: _t->on_btnDelLinkCameraMatrix_clicked(); break;
        case 10: _t->on_btnLinkDistCoeffs_clicked(); break;
        case 11: _t->on_btnDelLinkDistCoeffs_clicked(); break;
        case 12: _t->on_btnExecute_clicked(); break;
        case 13: _t->on_btnUpdata_clicked(); break;
        case 14: _t->on_comboCamera_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->onRadioClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->onCalibRadioClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: { int _r = _t->ReadBuffer((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2])),(*reinterpret_cast< cv::Mat(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 18: { int _r = _t->ReadBuffer((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2])),(*reinterpret_cast< cv::Mat(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->slot_Message(); break;
        case 20: _t->slot_PathMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmImageSource::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageSource::sig_Message)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmImageSource::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageSource::sig_PathMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (frmImageSource::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageSource::sig_ShowBlockageWarning)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (frmImageSource::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageSource::sig_HideBlockageWarning)) {
                *result = 3;
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
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void frmImageSource::sig_Message()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void frmImageSource::sig_PathMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void frmImageSource::sig_ShowBlockageWarning()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void frmImageSource::sig_HideBlockageWarning()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
