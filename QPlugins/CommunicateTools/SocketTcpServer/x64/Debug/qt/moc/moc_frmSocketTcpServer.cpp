/****************************************************************************
** Meta object code from reading C++ file 'frmSocketTcpServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmSocketTcpServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmSocketTcpServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmSocketTcpServer_t {
    QByteArrayData data[19];
    char stringdata0[318];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmSocketTcpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmSocketTcpServer_t qt_meta_stringdata_frmSocketTcpServer = {
    {
QT_MOC_LITERAL(0, 0, 18), // "frmSocketTcpServer"
QT_MOC_LITERAL(1, 19, 11), // "sig_SendMsg"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "sig_SMsg"
QT_MOC_LITERAL(4, 41, 11), // "sig_ReadMsg"
QT_MOC_LITERAL(5, 53, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(6, 74, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(7, 96, 20), // "on_btnUpdata_clicked"
QT_MOC_LITERAL(8, 117, 25), // "on_btnLinkContent_clicked"
QT_MOC_LITERAL(9, 143, 28), // "on_btnDelLinkContent_clicked"
QT_MOC_LITERAL(10, 172, 22), // "on_btnTcpClear_clicked"
QT_MOC_LITERAL(11, 195, 36), // "on_comboCommName_currentIndex..."
QT_MOC_LITERAL(12, 232, 5), // "index"
QT_MOC_LITERAL(13, 238, 16), // "acceptConnection"
QT_MOC_LITERAL(14, 255, 15), // "slot_ReadClient"
QT_MOC_LITERAL(15, 271, 12), // "slot_SendMsg"
QT_MOC_LITERAL(16, 284, 9), // "slot_SMsg"
QT_MOC_LITERAL(17, 294, 12), // "slot_ReadMsg"
QT_MOC_LITERAL(18, 307, 10) // "timerEvent"

    },
    "frmSocketTcpServer\0sig_SendMsg\0\0"
    "sig_SMsg\0sig_ReadMsg\0onButtonCloseClicked\0"
    "on_btnExecute_clicked\0on_btnUpdata_clicked\0"
    "on_btnLinkContent_clicked\0"
    "on_btnDelLinkContent_clicked\0"
    "on_btnTcpClear_clicked\0"
    "on_comboCommName_currentIndexChanged\0"
    "index\0acceptConnection\0slot_ReadClient\0"
    "slot_SendMsg\0slot_SMsg\0slot_ReadMsg\0"
    "timerEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmSocketTcpServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       3,    1,   97,    2, 0x06 /* Public */,
       4,    0,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  101,    2, 0x08 /* Private */,
       6,    0,  102,    2, 0x08 /* Private */,
       7,    0,  103,    2, 0x08 /* Private */,
       8,    0,  104,    2, 0x08 /* Private */,
       9,    0,  105,    2, 0x08 /* Private */,
      10,    0,  106,    2, 0x08 /* Private */,
      11,    1,  107,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    1,  112,    2, 0x08 /* Private */,
      16,    1,  115,    2, 0x08 /* Private */,
      17,    0,  118,    2, 0x08 /* Private */,
      18,    0,  119,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmSocketTcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmSocketTcpServer *>(_o);
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
        case 8: _t->on_btnTcpClear_clicked(); break;
        case 9: _t->on_comboCommName_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->acceptConnection(); break;
        case 11: _t->slot_ReadClient(); break;
        case 12: _t->slot_SendMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->slot_SMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->slot_ReadMsg(); break;
        case 15: _t->timerEvent(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmSocketTcpServer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmSocketTcpServer::sig_SendMsg)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmSocketTcpServer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmSocketTcpServer::sig_SMsg)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (frmSocketTcpServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmSocketTcpServer::sig_ReadMsg)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmSocketTcpServer::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmSocketTcpServer.data,
    qt_meta_data_frmSocketTcpServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmSocketTcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmSocketTcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmSocketTcpServer.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmSocketTcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void frmSocketTcpServer::sig_SendMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void frmSocketTcpServer::sig_SMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void frmSocketTcpServer::sig_ReadMsg()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
