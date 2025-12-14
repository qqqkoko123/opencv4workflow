/****************************************************************************
** Meta object code from reading C++ file 'frmCameraSetUp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../frmCameraSetUp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmCameraSetUp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmCameraSetUp_t {
    QByteArrayData data[51];
    char stringdata0[682];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmCameraSetUp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmCameraSetUp_t qt_meta_stringdata_frmCameraSetUp = {
    {
QT_MOC_LITERAL(0, 0, 14), // "frmCameraSetUp"
QT_MOC_LITERAL(1, 15, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 23), // "on_btnAddCamera_clicked"
QT_MOC_LITERAL(4, 61, 26), // "on_btnSearchCamera_clicked"
QT_MOC_LITERAL(5, 88, 10), // "IPIntToStr"
QT_MOC_LITERAL(6, 99, 8), // "uint32_t"
QT_MOC_LITERAL(7, 108, 5), // "ipInt"
QT_MOC_LITERAL(8, 114, 21), // "on_btnConnect_clicked"
QT_MOC_LITERAL(9, 136, 15), // "connectHikVison"
QT_MOC_LITERAL(10, 152, 11), // "startCamera"
QT_MOC_LITERAL(11, 164, 10), // "stopCamera"
QT_MOC_LITERAL(12, 175, 11), // "closeCamera"
QT_MOC_LITERAL(13, 187, 11), // "softTrigger"
QT_MOC_LITERAL(14, 199, 10), // "ReadBuffer"
QT_MOC_LITERAL(15, 210, 8), // "cv::Mat&"
QT_MOC_LITERAL(16, 219, 5), // "image"
QT_MOC_LITERAL(17, 225, 9), // "getHeight"
QT_MOC_LITERAL(18, 235, 8), // "getWidth"
QT_MOC_LITERAL(19, 244, 15), // "getExposureTime"
QT_MOC_LITERAL(20, 260, 9), // "setHeight"
QT_MOC_LITERAL(21, 270, 6), // "height"
QT_MOC_LITERAL(22, 277, 8), // "setWidth"
QT_MOC_LITERAL(23, 286, 5), // "width"
QT_MOC_LITERAL(24, 292, 10), // "setOffsetX"
QT_MOC_LITERAL(25, 303, 7), // "offsetX"
QT_MOC_LITERAL(26, 311, 10), // "setOffsetY"
QT_MOC_LITERAL(27, 322, 7), // "offsetY"
QT_MOC_LITERAL(28, 330, 14), // "setTriggerMode"
QT_MOC_LITERAL(29, 345, 14), // "TriggerModeNum"
QT_MOC_LITERAL(30, 360, 16), // "setTriggerSource"
QT_MOC_LITERAL(31, 377, 16), // "TriggerSourceNum"
QT_MOC_LITERAL(32, 394, 18), // "setFrameRateEnable"
QT_MOC_LITERAL(33, 413, 4), // "comm"
QT_MOC_LITERAL(34, 418, 16), // "setHeartBeatTime"
QT_MOC_LITERAL(35, 435, 4), // "time"
QT_MOC_LITERAL(36, 440, 15), // "setExposureTime"
QT_MOC_LITERAL(37, 456, 15), // "ExposureTimeNum"
QT_MOC_LITERAL(38, 472, 15), // "setExposureAuto"
QT_MOC_LITERAL(39, 488, 16), // "exposureAutoFlag"
QT_MOC_LITERAL(40, 505, 11), // "setGainAuto"
QT_MOC_LITERAL(41, 517, 12), // "gainAutoFlag"
QT_MOC_LITERAL(42, 530, 11), // "clearBuffer"
QT_MOC_LITERAL(43, 542, 24), // "on_btnDisconnect_clicked"
QT_MOC_LITERAL(44, 567, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(45, 586, 11), // "slot_MoveUp"
QT_MOC_LITERAL(46, 598, 13), // "slot_MoveDown"
QT_MOC_LITERAL(47, 612, 15), // "slot_DeleteName"
QT_MOC_LITERAL(48, 628, 18), // "slot_DoubleClicked"
QT_MOC_LITERAL(49, 647, 17), // "InitCameraConnect"
QT_MOC_LITERAL(50, 665, 16) // "camera_key_value"

    },
    "frmCameraSetUp\0onButtonCloseClicked\0"
    "\0on_btnAddCamera_clicked\0"
    "on_btnSearchCamera_clicked\0IPIntToStr\0"
    "uint32_t\0ipInt\0on_btnConnect_clicked\0"
    "connectHikVison\0startCamera\0stopCamera\0"
    "closeCamera\0softTrigger\0ReadBuffer\0"
    "cv::Mat&\0image\0getHeight\0getWidth\0"
    "getExposureTime\0setHeight\0height\0"
    "setWidth\0width\0setOffsetX\0offsetX\0"
    "setOffsetY\0offsetY\0setTriggerMode\0"
    "TriggerModeNum\0setTriggerSource\0"
    "TriggerSourceNum\0setFrameRateEnable\0"
    "comm\0setHeartBeatTime\0time\0setExposureTime\0"
    "ExposureTimeNum\0setExposureAuto\0"
    "exposureAutoFlag\0setGainAuto\0gainAutoFlag\0"
    "clearBuffer\0on_btnDisconnect_clicked\0"
    "on_btnSave_clicked\0slot_MoveUp\0"
    "slot_MoveDown\0slot_DeleteName\0"
    "slot_DoubleClicked\0InitCameraConnect\0"
    "camera_key_value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmCameraSetUp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  179,    2, 0x08 /* Private */,
       3,    0,  180,    2, 0x08 /* Private */,
       4,    0,  181,    2, 0x08 /* Private */,
       5,    1,  182,    2, 0x08 /* Private */,
       8,    0,  185,    2, 0x08 /* Private */,
       9,    0,  186,    2, 0x08 /* Private */,
      10,    0,  187,    2, 0x08 /* Private */,
      11,    0,  188,    2, 0x08 /* Private */,
      12,    0,  189,    2, 0x08 /* Private */,
      13,    0,  190,    2, 0x08 /* Private */,
      14,    1,  191,    2, 0x08 /* Private */,
      17,    0,  194,    2, 0x08 /* Private */,
      18,    0,  195,    2, 0x08 /* Private */,
      19,    0,  196,    2, 0x08 /* Private */,
      20,    1,  197,    2, 0x08 /* Private */,
      22,    1,  200,    2, 0x08 /* Private */,
      24,    1,  203,    2, 0x08 /* Private */,
      26,    1,  206,    2, 0x08 /* Private */,
      28,    1,  209,    2, 0x08 /* Private */,
      30,    1,  212,    2, 0x08 /* Private */,
      32,    1,  215,    2, 0x08 /* Private */,
      34,    1,  218,    2, 0x08 /* Private */,
      36,    1,  221,    2, 0x08 /* Private */,
      38,    1,  224,    2, 0x08 /* Private */,
      40,    1,  227,    2, 0x08 /* Private */,
      42,    0,  230,    2, 0x08 /* Private */,
      43,    0,  231,    2, 0x08 /* Private */,
      44,    0,  232,    2, 0x08 /* Private */,
      45,    0,  233,    2, 0x08 /* Private */,
      46,    0,  234,    2, 0x08 /* Private */,
      47,    0,  235,    2, 0x08 /* Private */,
      48,    2,  236,    2, 0x08 /* Private */,
      49,    1,  241,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int, 0x80000000 | 15,   16,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Float,
    QMetaType::Int, QMetaType::UInt,   21,
    QMetaType::Int, QMetaType::UInt,   23,
    QMetaType::Int, QMetaType::UInt,   25,
    QMetaType::Int, QMetaType::UInt,   27,
    QMetaType::Int, QMetaType::UInt,   29,
    QMetaType::Int, QMetaType::UInt,   31,
    QMetaType::Int, QMetaType::Bool,   33,
    QMetaType::Int, QMetaType::UInt,   35,
    QMetaType::Int, QMetaType::Float,   37,
    QMetaType::Int, QMetaType::Bool,   39,
    QMetaType::Int, QMetaType::Bool,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,   50,

       0        // eod
};

void frmCameraSetUp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmCameraSetUp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonCloseClicked(); break;
        case 1: _t->on_btnAddCamera_clicked(); break;
        case 2: _t->on_btnSearchCamera_clicked(); break;
        case 3: { QString _r = _t->IPIntToStr((*reinterpret_cast< uint32_t(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->on_btnConnect_clicked(); break;
        case 5: _t->connectHikVison(); break;
        case 6: { int _r = _t->startCamera();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->stopCamera();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->closeCamera();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->softTrigger();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->ReadBuffer((*reinterpret_cast< cv::Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->getHeight();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->getWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: { float _r = _t->getExposureTime();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 14: { int _r = _t->setHeight((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: { int _r = _t->setWidth((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: { int _r = _t->setOffsetX((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 17: { int _r = _t->setOffsetY((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 18: { int _r = _t->setTriggerMode((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 19: { int _r = _t->setTriggerSource((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 20: { int _r = _t->setFrameRateEnable((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 21: { int _r = _t->setHeartBeatTime((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 22: { int _r = _t->setExposureTime((*reinterpret_cast< float(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 23: { int _r = _t->setExposureAuto((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 24: { int _r = _t->setGainAuto((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->clearBuffer(); break;
        case 26: _t->on_btnDisconnect_clicked(); break;
        case 27: _t->on_btnSave_clicked(); break;
        case 28: _t->slot_MoveUp(); break;
        case 29: _t->slot_MoveDown(); break;
        case 30: _t->slot_DeleteName(); break;
        case 31: _t->slot_DoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 32: _t->InitCameraConnect((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmCameraSetUp::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_frmCameraSetUp.data,
    qt_meta_data_frmCameraSetUp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmCameraSetUp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmCameraSetUp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmCameraSetUp.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int frmCameraSetUp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 33;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
