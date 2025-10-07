/****************************************************************************
** Meta object code from reading C++ file 'frmCameraSetUp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmCameraSetUp.h"
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
    QByteArrayData data[53];
    char stringdata0[694];
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
QT_MOC_LITERAL(10, 152, 4), // "type"
QT_MOC_LITERAL(11, 157, 11), // "startCamera"
QT_MOC_LITERAL(12, 169, 6), // "handle"
QT_MOC_LITERAL(13, 176, 10), // "stopCamera"
QT_MOC_LITERAL(14, 187, 11), // "closeCamera"
QT_MOC_LITERAL(15, 199, 11), // "softTrigger"
QT_MOC_LITERAL(16, 211, 10), // "ReadBuffer"
QT_MOC_LITERAL(17, 222, 8), // "cv::Mat&"
QT_MOC_LITERAL(18, 231, 5), // "image"
QT_MOC_LITERAL(19, 237, 9), // "getHeight"
QT_MOC_LITERAL(20, 247, 8), // "getWidth"
QT_MOC_LITERAL(21, 256, 15), // "getExposureTime"
QT_MOC_LITERAL(22, 272, 9), // "setHeight"
QT_MOC_LITERAL(23, 282, 6), // "height"
QT_MOC_LITERAL(24, 289, 8), // "setWidth"
QT_MOC_LITERAL(25, 298, 5), // "width"
QT_MOC_LITERAL(26, 304, 10), // "setOffsetX"
QT_MOC_LITERAL(27, 315, 7), // "offsetX"
QT_MOC_LITERAL(28, 323, 10), // "setOffsetY"
QT_MOC_LITERAL(29, 334, 7), // "offsetY"
QT_MOC_LITERAL(30, 342, 14), // "setTriggerMode"
QT_MOC_LITERAL(31, 357, 14), // "TriggerModeNum"
QT_MOC_LITERAL(32, 372, 16), // "setTriggerSource"
QT_MOC_LITERAL(33, 389, 16), // "TriggerSourceNum"
QT_MOC_LITERAL(34, 406, 18), // "setFrameRateEnable"
QT_MOC_LITERAL(35, 425, 4), // "comm"
QT_MOC_LITERAL(36, 430, 16), // "setHeartBeatTime"
QT_MOC_LITERAL(37, 447, 4), // "time"
QT_MOC_LITERAL(38, 452, 15), // "setExposureTime"
QT_MOC_LITERAL(39, 468, 15), // "ExposureTimeNum"
QT_MOC_LITERAL(40, 484, 15), // "setExposureAuto"
QT_MOC_LITERAL(41, 500, 16), // "exposureAutoFlag"
QT_MOC_LITERAL(42, 517, 11), // "setGainAuto"
QT_MOC_LITERAL(43, 529, 12), // "gainAutoFlag"
QT_MOC_LITERAL(44, 542, 11), // "clearBuffer"
QT_MOC_LITERAL(45, 554, 24), // "on_btnDisconnect_clicked"
QT_MOC_LITERAL(46, 579, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(47, 598, 11), // "slot_MoveUp"
QT_MOC_LITERAL(48, 610, 13), // "slot_MoveDown"
QT_MOC_LITERAL(49, 624, 15), // "slot_DeleteName"
QT_MOC_LITERAL(50, 640, 18), // "slot_DoubleClicked"
QT_MOC_LITERAL(51, 659, 17), // "InitCameraConnect"
QT_MOC_LITERAL(52, 677, 16) // "camera_key_value"

    },
    "frmCameraSetUp\0onButtonCloseClicked\0"
    "\0on_btnAddCamera_clicked\0"
    "on_btnSearchCamera_clicked\0IPIntToStr\0"
    "uint32_t\0ipInt\0on_btnConnect_clicked\0"
    "connectHikVison\0type\0startCamera\0"
    "handle\0stopCamera\0closeCamera\0softTrigger\0"
    "ReadBuffer\0cv::Mat&\0image\0getHeight\0"
    "getWidth\0getExposureTime\0setHeight\0"
    "height\0setWidth\0width\0setOffsetX\0"
    "offsetX\0setOffsetY\0offsetY\0setTriggerMode\0"
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
       9,    1,  186,    2, 0x08 /* Private */,
      11,    1,  189,    2, 0x08 /* Private */,
      13,    1,  192,    2, 0x08 /* Private */,
      14,    1,  195,    2, 0x08 /* Private */,
      15,    1,  198,    2, 0x08 /* Private */,
      16,    2,  201,    2, 0x08 /* Private */,
      19,    1,  206,    2, 0x08 /* Private */,
      20,    1,  209,    2, 0x08 /* Private */,
      21,    1,  212,    2, 0x08 /* Private */,
      22,    2,  215,    2, 0x08 /* Private */,
      24,    2,  220,    2, 0x08 /* Private */,
      26,    2,  225,    2, 0x08 /* Private */,
      28,    2,  230,    2, 0x08 /* Private */,
      30,    2,  235,    2, 0x08 /* Private */,
      32,    2,  240,    2, 0x08 /* Private */,
      34,    2,  245,    2, 0x08 /* Private */,
      36,    2,  250,    2, 0x08 /* Private */,
      38,    2,  255,    2, 0x08 /* Private */,
      40,    2,  260,    2, 0x08 /* Private */,
      42,    2,  265,    2, 0x08 /* Private */,
      44,    0,  270,    2, 0x08 /* Private */,
      45,    0,  271,    2, 0x08 /* Private */,
      46,    0,  272,    2, 0x08 /* Private */,
      47,    0,  273,    2, 0x08 /* Private */,
      48,    0,  274,    2, 0x08 /* Private */,
      49,    0,  275,    2, 0x08 /* Private */,
      50,    2,  276,    2, 0x08 /* Private */,
      51,    1,  281,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Int, QMetaType::VoidStar,   12,
    QMetaType::Int, QMetaType::VoidStar,   12,
    QMetaType::Int, QMetaType::VoidStar,   12,
    QMetaType::Int, QMetaType::VoidStar,   12,
    QMetaType::Int, QMetaType::VoidStar, 0x80000000 | 17,   12,   18,
    QMetaType::Int, QMetaType::VoidStar,   12,
    QMetaType::Int, QMetaType::VoidStar,   12,
    QMetaType::Float, QMetaType::VoidStar,   12,
    QMetaType::Int, QMetaType::VoidStar, QMetaType::UInt,   12,   23,
    QMetaType::Int, QMetaType::VoidStar, QMetaType::UInt,   12,   25,
    QMetaType::Int, QMetaType::VoidStar, QMetaType::UInt,   12,   27,
    QMetaType::Int, QMetaType::VoidStar, QMetaType::UInt,   12,   29,
    QMetaType::Int, QMetaType::VoidStar, QMetaType::UInt,   12,   31,
    QMetaType::Int, QMetaType::VoidStar, QMetaType::UInt,   12,   33,
    QMetaType::Int, QMetaType::VoidStar, QMetaType::Bool,   12,   35,
    QMetaType::Int, QMetaType::VoidStar, QMetaType::UInt,   12,   37,
    QMetaType::Int, QMetaType::VoidStar, QMetaType::Float,   12,   39,
    QMetaType::Int, QMetaType::VoidStar, QMetaType::Bool,   12,   41,
    QMetaType::Int, QMetaType::VoidStar, QMetaType::Bool,   12,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,   52,

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
        case 5: _t->connectHikVison((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: { int _r = _t->startCamera((*reinterpret_cast< void*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->stopCamera((*reinterpret_cast< void*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->closeCamera((*reinterpret_cast< void*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->softTrigger((*reinterpret_cast< void*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->ReadBuffer((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->getHeight((*reinterpret_cast< void*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->getWidth((*reinterpret_cast< void*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: { float _r = _t->getExposureTime((*reinterpret_cast< void*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 14: { int _r = _t->setHeight((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: { int _r = _t->setWidth((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: { int _r = _t->setOffsetX((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 17: { int _r = _t->setOffsetY((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 18: { int _r = _t->setTriggerMode((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 19: { int _r = _t->setTriggerSource((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 20: { int _r = _t->setFrameRateEnable((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 21: { int _r = _t->setHeartBeatTime((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 22: { int _r = _t->setExposureTime((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 23: { int _r = _t->setExposureAuto((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 24: { int _r = _t->setGainAuto((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
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
