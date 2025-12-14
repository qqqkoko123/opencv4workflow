/****************************************************************************
** Meta object code from reading C++ file 'savelog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../savelog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'savelog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SaveLog_t {
    QByteArrayData data[25];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SaveLog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SaveLog_t qt_meta_stringdata_SaveLog = {
    {
QT_MOC_LITERAL(0, 0, 7), // "SaveLog"
QT_MOC_LITERAL(1, 8, 4), // "send"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 7), // "content"
QT_MOC_LITERAL(4, 22, 5), // "start"
QT_MOC_LITERAL(5, 28, 4), // "stop"
QT_MOC_LITERAL(6, 33, 5), // "clear"
QT_MOC_LITERAL(7, 39, 4), // "save"
QT_MOC_LITERAL(8, 44, 9), // "setMaxRow"
QT_MOC_LITERAL(9, 54, 6), // "maxRow"
QT_MOC_LITERAL(10, 61, 10), // "setMaxSize"
QT_MOC_LITERAL(11, 72, 7), // "maxSize"
QT_MOC_LITERAL(12, 80, 13), // "setListenPort"
QT_MOC_LITERAL(13, 94, 10), // "listenPort"
QT_MOC_LITERAL(14, 105, 8), // "setToNet"
QT_MOC_LITERAL(15, 114, 5), // "toNet"
QT_MOC_LITERAL(16, 120, 13), // "setUseContext"
QT_MOC_LITERAL(17, 134, 10), // "useContext"
QT_MOC_LITERAL(18, 145, 7), // "setPath"
QT_MOC_LITERAL(19, 153, 4), // "path"
QT_MOC_LITERAL(20, 158, 7), // "setName"
QT_MOC_LITERAL(21, 166, 4), // "name"
QT_MOC_LITERAL(22, 171, 10), // "setMsgType"
QT_MOC_LITERAL(23, 182, 7), // "MsgType"
QT_MOC_LITERAL(24, 190, 7) // "msgType"

    },
    "SaveLog\0send\0\0content\0start\0stop\0clear\0"
    "save\0setMaxRow\0maxRow\0setMaxSize\0"
    "maxSize\0setListenPort\0listenPort\0"
    "setToNet\0toNet\0setUseContext\0useContext\0"
    "setPath\0path\0setName\0name\0setMsgType\0"
    "MsgType\0msgType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SaveLog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   82,    2, 0x0a /* Public */,
       5,    0,   83,    2, 0x0a /* Public */,
       6,    0,   84,    2, 0x0a /* Public */,
       7,    1,   85,    2, 0x0a /* Public */,
       8,    1,   88,    2, 0x0a /* Public */,
      10,    1,   91,    2, 0x0a /* Public */,
      12,    1,   94,    2, 0x0a /* Public */,
      14,    1,   97,    2, 0x0a /* Public */,
      16,    1,  100,    2, 0x0a /* Public */,
      18,    1,  103,    2, 0x0a /* Public */,
      20,    1,  106,    2, 0x0a /* Public */,
      22,    1,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, 0x80000000 | 23,   24,

       0        // eod
};

void SaveLog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SaveLog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->start(); break;
        case 2: _t->stop(); break;
        case 3: _t->clear(); break;
        case 4: _t->save((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setMaxRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setMaxSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setListenPort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setToNet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setUseContext((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setPath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->setName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->setMsgType((*reinterpret_cast< const MsgType(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SaveLog::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SaveLog::send)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SaveLog::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SaveLog.data,
    qt_meta_data_SaveLog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SaveLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SaveLog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SaveLog.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SaveLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void SaveLog::send(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_SendLog_t {
    QByteArrayData data[9];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SendLog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SendLog_t qt_meta_stringdata_SendLog = {
    {
QT_MOC_LITERAL(0, 0, 7), // "SendLog"
QT_MOC_LITERAL(1, 8, 13), // "newConnection"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 13), // "setListenPort"
QT_MOC_LITERAL(4, 37, 10), // "listenPort"
QT_MOC_LITERAL(5, 48, 5), // "start"
QT_MOC_LITERAL(6, 54, 4), // "stop"
QT_MOC_LITERAL(7, 59, 4), // "send"
QT_MOC_LITERAL(8, 64, 7) // "content"

    },
    "SendLog\0newConnection\0\0setListenPort\0"
    "listenPort\0start\0stop\0send\0content"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SendLog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    1,   40,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void SendLog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SendLog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newConnection(); break;
        case 1: _t->setListenPort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->start(); break;
        case 3: _t->stop(); break;
        case 4: _t->send((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SendLog::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SendLog.data,
    qt_meta_data_SendLog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SendLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SendLog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SendLog.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SendLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
