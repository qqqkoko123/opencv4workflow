/****************************************************************************
** Meta object code from reading C++ file 'CvBaseService.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../autoMeasure/service/CvBaseService.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CvBaseService.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CvBaseService_t {
    QByteArrayData data[15];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CvBaseService_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CvBaseService_t qt_meta_stringdata_CvBaseService = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CvBaseService"
QT_MOC_LITERAL(1, 14, 11), // "nameChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "name"
QT_MOC_LITERAL(4, 32, 15), // "repoLinkChanged"
QT_MOC_LITERAL(5, 48, 8), // "repoLink"
QT_MOC_LITERAL(6, 57, 17), // "iconSourceChanged"
QT_MOC_LITERAL(7, 75, 10), // "iconSource"
QT_MOC_LITERAL(8, 86, 15), // "isActiveChanged"
QT_MOC_LITERAL(9, 102, 8), // "isActive"
QT_MOC_LITERAL(10, 111, 7), // "setName"
QT_MOC_LITERAL(11, 119, 5), // "value"
QT_MOC_LITERAL(12, 125, 11), // "setRepoLink"
QT_MOC_LITERAL(13, 137, 13), // "setIconSource"
QT_MOC_LITERAL(14, 151, 11) // "setIsActive"

    },
    "CvBaseService\0nameChanged\0\0name\0"
    "repoLinkChanged\0repoLink\0iconSourceChanged\0"
    "iconSource\0isActiveChanged\0isActive\0"
    "setName\0value\0setRepoLink\0setIconSource\0"
    "setIsActive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CvBaseService[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       4,   78, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,
       8,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   66,    2, 0x0a /* Public */,
      12,    1,   69,    2, 0x0a /* Public */,
      13,    1,   72,    2, 0x0a /* Public */,
      14,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Bool,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Bool,   11,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::QString, 0x00495103,
       7, QMetaType::QString, 0x00495103,
       9, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void CvBaseService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CvBaseService *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->repoLinkChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->iconSourceChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->isActiveChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setRepoLink((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setIconSource((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setIsActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CvBaseService::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CvBaseService::nameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CvBaseService::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CvBaseService::repoLinkChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CvBaseService::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CvBaseService::iconSourceChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CvBaseService::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CvBaseService::isActiveChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CvBaseService *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getName(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getRepoLink(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getIconSource(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->getIsActive(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CvBaseService *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setRepoLink(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setIconSource(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setIsActive(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CvBaseService::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CvBaseService.data,
    qt_meta_data_CvBaseService,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CvBaseService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CvBaseService::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CvBaseService.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CvBaseService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CvBaseService::nameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CvBaseService::repoLinkChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CvBaseService::iconSourceChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CvBaseService::isActiveChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
