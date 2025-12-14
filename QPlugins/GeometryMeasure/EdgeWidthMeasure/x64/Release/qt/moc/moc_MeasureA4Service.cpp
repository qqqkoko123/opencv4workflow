/****************************************************************************
** Meta object code from reading C++ file 'MeasureA4Service.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../autoMeasure/service/MeasureA4Service.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MeasureA4Service.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MeasureA4Service_t {
    QByteArrayData data[12];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeasureA4Service_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeasureA4Service_t qt_meta_stringdata_MeasureA4Service = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MeasureA4Service"
QT_MOC_LITERAL(1, 17, 15), // "refWidthChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 8), // "refWidth"
QT_MOC_LITERAL(4, 43, 16), // "refHeightChanged"
QT_MOC_LITERAL(5, 60, 9), // "refHeight"
QT_MOC_LITERAL(6, 70, 12), // "scaleChanged"
QT_MOC_LITERAL(7, 83, 5), // "scale"
QT_MOC_LITERAL(8, 89, 11), // "setRefWidth"
QT_MOC_LITERAL(9, 101, 5), // "value"
QT_MOC_LITERAL(10, 107, 12), // "setRefHeight"
QT_MOC_LITERAL(11, 120, 8) // "setScale"

    },
    "MeasureA4Service\0refWidthChanged\0\0"
    "refWidth\0refHeightChanged\0refHeight\0"
    "scaleChanged\0scale\0setRefWidth\0value\0"
    "setRefHeight\0setScale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeasureA4Service[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       3,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   53,    2, 0x0a /* Public */,
      10,    1,   56,    2, 0x0a /* Public */,
      11,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00495103,
       5, QMetaType::Int, 0x00495103,
       7, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void MeasureA4Service::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MeasureA4Service *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refWidthChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->refHeightChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->scaleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setRefWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setRefHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setScale((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MeasureA4Service::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeasureA4Service::refWidthChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MeasureA4Service::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeasureA4Service::refHeightChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MeasureA4Service::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeasureA4Service::scaleChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MeasureA4Service *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getRefWidth(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getRefHeight(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getScale(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MeasureA4Service *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRefWidth(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setRefHeight(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setScale(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MeasureA4Service::staticMetaObject = { {
    QMetaObject::SuperData::link<CvBaseService::staticMetaObject>(),
    qt_meta_stringdata_MeasureA4Service.data,
    qt_meta_data_MeasureA4Service,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MeasureA4Service::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeasureA4Service::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MeasureA4Service.stringdata0))
        return static_cast<void*>(this);
    return CvBaseService::qt_metacast(_clname);
}

int MeasureA4Service::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CvBaseService::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MeasureA4Service::refWidthChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MeasureA4Service::refHeightChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MeasureA4Service::scaleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
