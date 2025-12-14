/****************************************************************************
** Meta object code from reading C++ file 'frmLog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmLog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmLog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrmLog_t {
    QByteArrayData data[16];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrmLog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrmLog_t qt_meta_stringdata_FrmLog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "FrmLog"
QT_MOC_LITERAL(1, 7, 16), // "sig_Message_Info"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "index"
QT_MOC_LITERAL(4, 31, 4), // "item"
QT_MOC_LITERAL(5, 36, 16), // "sig_Message_Warn"
QT_MOC_LITERAL(6, 53, 17), // "sig_Message_Error"
QT_MOC_LITERAL(7, 71, 14), // "slot_InfoClick"
QT_MOC_LITERAL(8, 86, 14), // "slot_WarnClick"
QT_MOC_LITERAL(9, 101, 15), // "slot_ErrorClick"
QT_MOC_LITERAL(10, 117, 12), // "slot_Message"
QT_MOC_LITERAL(11, 130, 6), // "strMsg"
QT_MOC_LITERAL(12, 137, 17), // "slot_Message_Info"
QT_MOC_LITERAL(13, 155, 17), // "slot_Message_Warn"
QT_MOC_LITERAL(14, 173, 18), // "slot_Message_Error"
QT_MOC_LITERAL(15, 192, 10) // "timerEvent"

    },
    "FrmLog\0sig_Message_Info\0\0index\0item\0"
    "sig_Message_Warn\0sig_Message_Error\0"
    "slot_InfoClick\0slot_WarnClick\0"
    "slot_ErrorClick\0slot_Message\0strMsg\0"
    "slot_Message_Info\0slot_Message_Warn\0"
    "slot_Message_Error\0timerEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrmLog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    2,   74,    2, 0x06 /* Public */,
       6,    2,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    1,   87,    2, 0x0a /* Public */,
      12,    1,   90,    2, 0x0a /* Public */,
      13,    1,   93,    2, 0x0a /* Public */,
      14,    1,   96,    2, 0x0a /* Public */,
      15,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Bool, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Bool, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Bool, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void FrmLog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrmLog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->sig_Message_Info((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->sig_Message_Warn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->sig_Message_Error((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->slot_InfoClick(); break;
        case 4: _t->slot_WarnClick(); break;
        case 5: _t->slot_ErrorClick(); break;
        case 6: _t->slot_Message((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->slot_Message_Info((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->slot_Message_Warn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->slot_Message_Error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->timerEvent(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = bool (FrmLog::*)(int , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrmLog::sig_Message_Info)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = bool (FrmLog::*)(int , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrmLog::sig_Message_Warn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = bool (FrmLog::*)(int , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrmLog::sig_Message_Error)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrmLog::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FrmLog.data,
    qt_meta_data_FrmLog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrmLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrmLog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrmLog.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FrmLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
bool FrmLog::sig_Message_Info(int _t1, const QString _t2)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
bool FrmLog::sig_Message_Warn(int _t1, const QString _t2)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
bool FrmLog::sig_Message_Error(int _t1, const QString _t2)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
