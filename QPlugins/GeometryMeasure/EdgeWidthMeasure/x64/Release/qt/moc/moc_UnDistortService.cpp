/****************************************************************************
** Meta object code from reading C++ file 'UnDistortService.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../autoMeasure/service/UnDistortService.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UnDistortService.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UnDistortService_t {
    QByteArrayData data[16];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UnDistortService_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UnDistortService_t qt_meta_stringdata_UnDistortService = {
    {
QT_MOC_LITERAL(0, 0, 16), // "UnDistortService"
QT_MOC_LITERAL(1, 17, 16), // "cornerRowChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 9), // "cornerRow"
QT_MOC_LITERAL(4, 45, 16), // "cornerColChanged"
QT_MOC_LITERAL(5, 62, 9), // "cornerCol"
QT_MOC_LITERAL(6, 72, 12), // "setCornerRow"
QT_MOC_LITERAL(7, 85, 5), // "value"
QT_MOC_LITERAL(8, 91, 12), // "setCornerCol"
QT_MOC_LITERAL(9, 104, 9), // "calibrate"
QT_MOC_LITERAL(10, 114, 15), // "insertImagePath"
QT_MOC_LITERAL(11, 130, 4), // "path"
QT_MOC_LITERAL(12, 135, 15), // "deleteImagePath"
QT_MOC_LITERAL(13, 151, 16), // "isExistImagePath"
QT_MOC_LITERAL(14, 168, 14), // "clearImagePath"
QT_MOC_LITERAL(15, 183, 12) // "getImagePath"

    },
    "UnDistortService\0cornerRowChanged\0\0"
    "cornerRow\0cornerColChanged\0cornerCol\0"
    "setCornerRow\0value\0setCornerCol\0"
    "calibrate\0insertImagePath\0path\0"
    "deleteImagePath\0isExistImagePath\0"
    "clearImagePath\0getImagePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UnDistortService[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       2,   88, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   70,    2, 0x0a /* Public */,
       8,    1,   73,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       9,    0,   76,    2, 0x02 /* Public */,
      10,    1,   77,    2, 0x02 /* Public */,
      12,    1,   80,    2, 0x02 /* Public */,
      13,    1,   83,    2, 0x02 /* Public */,
      14,    0,   86,    2, 0x02 /* Public */,
      15,    0,   87,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Bool, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::QVariantList,

 // properties: name, type, flags
       3, QMetaType::Bool, 0x00495103,
       5, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void UnDistortService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UnDistortService *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cornerRowChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->cornerColChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setCornerRow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setCornerCol((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->calibrate(); break;
        case 5: _t->insertImagePath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->deleteImagePath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: { bool _r = _t->isExistImagePath((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->clearImagePath(); break;
        case 9: { QVariantList _r = _t->getImagePath();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UnDistortService::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UnDistortService::cornerRowChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UnDistortService::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UnDistortService::cornerColChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<UnDistortService *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getCornerRow(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->getCornerCol(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<UnDistortService *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCornerRow(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setCornerCol(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject UnDistortService::staticMetaObject = { {
    QMetaObject::SuperData::link<CvBaseService::staticMetaObject>(),
    qt_meta_stringdata_UnDistortService.data,
    qt_meta_data_UnDistortService,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UnDistortService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UnDistortService::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UnDistortService.stringdata0))
        return static_cast<void*>(this);
    return CvBaseService::qt_metacast(_clname);
}

int UnDistortService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CvBaseService::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void UnDistortService::cornerRowChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UnDistortService::cornerColChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
