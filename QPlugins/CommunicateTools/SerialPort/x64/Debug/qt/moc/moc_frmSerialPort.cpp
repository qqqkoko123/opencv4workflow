/****************************************************************************
** Meta object code from reading C++ file 'frmSerialPort.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmSerialPort.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmSerialPort.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmSerialPort_t {
    QByteArrayData data[18];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmSerialPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmSerialPort_t qt_meta_stringdata_frmSerialPort = {
    {
QT_MOC_LITERAL(0, 0, 13), // "frmSerialPort"
QT_MOC_LITERAL(1, 14, 11), // "sig_SendMsg"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "sig_SMsg"
QT_MOC_LITERAL(4, 36, 11), // "sig_ReadMsg"
QT_MOC_LITERAL(5, 48, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(6, 69, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(7, 91, 20), // "on_btnUpdata_clicked"
QT_MOC_LITERAL(8, 112, 25), // "on_btnLinkContent_clicked"
QT_MOC_LITERAL(9, 138, 28), // "on_btnDelLinkContent_clicked"
QT_MOC_LITERAL(10, 167, 22), // "on_btnComClear_clicked"
QT_MOC_LITERAL(11, 190, 36), // "on_comboCommName_currentIndex..."
QT_MOC_LITERAL(12, 227, 5), // "index"
QT_MOC_LITERAL(13, 233, 13), // "slot_ReadData"
QT_MOC_LITERAL(14, 247, 12), // "slot_SendMsg"
QT_MOC_LITERAL(15, 260, 9), // "slot_SMsg"
QT_MOC_LITERAL(16, 270, 12), // "slot_ReadMsg"
QT_MOC_LITERAL(17, 283, 10) // "timerEvent"

    },
    "frmSerialPort\0sig_SendMsg\0\0sig_SMsg\0"
    "sig_ReadMsg\0onButtonCloseClicked\0"
    "on_btnExecute_clicked\0on_btnUpdata_clicked\0"
    "on_btnLinkContent_clicked\0"
    "on_btnDelLinkContent_clicked\0"
    "on_btnComClear_clicked\0"
    "on_comboCommName_currentIndexChanged\0"
    "index\0slot_ReadData\0slot_SendMsg\0"
    "slot_SMsg\0slot_ReadMsg\0timerEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmSerialPort[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       3,    1,   92,    2, 0x06 /* Public */,
       4,    0,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   96,    2, 0x08 /* Private */,
       6,    0,   97,    2, 0x08 /* Private */,
       7,    0,   98,    2, 0x08 /* Private */,
       8,    0,   99,    2, 0x08 /* Private */,
       9,    0,  100,    2, 0x08 /* Private */,
      10,    0,  101,    2, 0x08 /* Private */,
      11,    1,  102,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    1,  106,    2, 0x08 /* Private */,
      15,    1,  109,    2, 0x08 /* Private */,
      16,    0,  112,    2, 0x08 /* Private */,
      17,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmSerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmSerialPort *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_SendMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sig_SMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sig_ReadMsg(); break;
        case 3: _t->onButtonCloseClicked(); break;
        case 4: _t->on_btnExecute_clicked(); break;
        case 5: _t->on_btnUpdata_clicked(); break;
        case 6: _t->on_btnLinkContent_clicked(); break;
        case 7: _t->on_btnDelLinkContent_clicked(); break;
        case 8: _t->on_btnComClear_clicked(); break;
        case 9: _t->on_comboCommName_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->slot_ReadData(); break;
        case 11: _t->slot_SendMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->slot_SMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->slot_ReadMsg(); break;
        case 14: _t->timerEvent(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmSerialPort::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmSerialPort::sig_SendMsg)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmSerialPort::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmSerialPort::sig_SMsg)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (frmSerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmSerialPort::sig_ReadMsg)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmSerialPort::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmSerialPort.data,
    qt_meta_data_frmSerialPort,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmSerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmSerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmSerialPort.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmSerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void frmSerialPort::sig_SendMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void frmSerialPort::sig_SMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void frmSerialPort::sig_ReadMsg()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
