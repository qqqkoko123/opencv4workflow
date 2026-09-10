/****************************************************************************
** Meta object code from reading C++ file 'QToolBase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../QToolBase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QToolBase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QToolBase_t {
    QByteArrayData data[10];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QToolBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QToolBase_t qt_meta_stringdata_QToolBase = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QToolBase"
QT_MOC_LITERAL(1, 10, 8), // "sig_Info"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 6), // "strMsg"
QT_MOC_LITERAL(4, 27, 8), // "sig_Warn"
QT_MOC_LITERAL(5, 36, 9), // "sig_Error"
QT_MOC_LITERAL(6, 46, 18), // "sig_SetGlobalValue"
QT_MOC_LITERAL(7, 65, 6), // "strVar"
QT_MOC_LITERAL(8, 72, 5), // "value"
QT_MOC_LITERAL(9, 78, 9) // "flowIndex"

    },
    "QToolBase\0sig_Info\0\0strMsg\0sig_Warn\0"
    "sig_Error\0sig_SetGlobalValue\0strVar\0"
    "value\0flowIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QToolBase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    1,   40,    2, 0x06 /* Public */,
       6,    3,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    7,    8,    9,

       0        // eod
};

void QToolBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QToolBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_Info((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sig_Warn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->sig_Error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: { QString _r = _t->sig_SetGlobalValue((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QToolBase::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QToolBase::sig_Info)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QToolBase::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QToolBase::sig_Warn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QToolBase::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QToolBase::sig_Error)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = QString (QToolBase::*)(const QString , const QString , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QToolBase::sig_SetGlobalValue)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QToolBase::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QToolBase.data,
    qt_meta_data_QToolBase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QToolBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QToolBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QToolBase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QToolBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QToolBase::sig_Info(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QToolBase::sig_Warn(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QToolBase::sig_Error(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
QString QToolBase::sig_SetGlobalValue(const QString _t1, const QString _t2, const int _t3)
{
    QString _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
