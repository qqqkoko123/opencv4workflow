/****************************************************************************
** Meta object code from reading C++ file 'ObjectListModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../autoMeasure/model/ObjectListModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ObjectListModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ObjectListModel_t {
    QByteArrayData data[30];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ObjectListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ObjectListModel_t qt_meta_stringdata_ObjectListModel = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ObjectListModel"
QT_MOC_LITERAL(1, 16, 15), // "DefaultProperty"
QT_MOC_LITERAL(2, 32, 8), // "children"
QT_MOC_LITERAL(3, 41, 12), // "countChanged"
QT_MOC_LITERAL(4, 54, 0), // ""
QT_MOC_LITERAL(5, 55, 5), // "count"
QT_MOC_LITERAL(6, 61, 15), // "childrenChanged"
QT_MOC_LITERAL(7, 77, 2), // "at"
QT_MOC_LITERAL(8, 80, 5), // "index"
QT_MOC_LITERAL(9, 86, 5), // "first"
QT_MOC_LITERAL(10, 92, 4), // "last"
QT_MOC_LITERAL(11, 97, 10), // "getRawData"
QT_MOC_LITERAL(12, 108, 4), // "size"
QT_MOC_LITERAL(13, 113, 7), // "indexOf"
QT_MOC_LITERAL(14, 121, 6), // "object"
QT_MOC_LITERAL(15, 128, 6), // "append"
QT_MOC_LITERAL(16, 135, 6), // "insert"
QT_MOC_LITERAL(17, 142, 5), // "reset"
QT_MOC_LITERAL(18, 148, 11), // "QObjectList"
QT_MOC_LITERAL(19, 160, 7), // "objects"
QT_MOC_LITERAL(20, 168, 6), // "takeAt"
QT_MOC_LITERAL(21, 175, 4), // "take"
QT_MOC_LITERAL(22, 180, 8), // "removeAt"
QT_MOC_LITERAL(23, 189, 6), // "remove"
QT_MOC_LITERAL(24, 196, 10), // "clearRange"
QT_MOC_LITERAL(25, 207, 11), // "start_index"
QT_MOC_LITERAL(26, 219, 11), // "notifyCount"
QT_MOC_LITERAL(27, 231, 15), // "propertyChanged"
QT_MOC_LITERAL(28, 247, 21), // "notifyPropertyChanged"
QT_MOC_LITERAL(29, 269, 25) // "QQmlListProperty<QObject>"

    },
    "ObjectListModel\0DefaultProperty\0"
    "children\0countChanged\0\0count\0"
    "childrenChanged\0at\0index\0first\0last\0"
    "getRawData\0size\0indexOf\0object\0append\0"
    "insert\0reset\0QObjectList\0objects\0"
    "takeAt\0take\0removeAt\0remove\0clearRange\0"
    "start_index\0notifyCount\0propertyChanged\0"
    "notifyPropertyChanged\0QQmlListProperty<QObject>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ObjectListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
      20,   16, // methods
       2,  164, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags
       3,    1,  116,    4, 0x06 /* Public */,
       6,    0,  119,    4, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,  120,    4, 0x0a /* Public */,
       9,    0,  123,    4, 0x0a /* Public */,
      10,    0,  124,    4, 0x0a /* Public */,
      11,    0,  125,    4, 0x0a /* Public */,
      12,    0,  126,    4, 0x0a /* Public */,
      13,    1,  127,    4, 0x0a /* Public */,
      15,    1,  130,    4, 0x0a /* Public */,
      16,    2,  133,    4, 0x0a /* Public */,
      17,    1,  138,    4, 0x0a /* Public */,
      17,    0,  141,    4, 0x2a /* Public | MethodCloned */,
      20,    1,  142,    4, 0x0a /* Public */,
      21,    1,  145,    4, 0x0a /* Public */,
      22,    1,  148,    4, 0x0a /* Public */,
      23,    1,  151,    4, 0x0a /* Public */,
      24,    2,  154,    4, 0x0a /* Public */,
      26,    0,  159,    4, 0x08 /* Private */,
      27,    0,  160,    4, 0x08 /* Private */,
      28,    1,  161,    4, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::QObjectStar, QMetaType::Int,    8,
    QMetaType::QObjectStar,
    QMetaType::QObjectStar,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Int, QMetaType::QObjectStar,   14,
    QMetaType::Void, QMetaType::QObjectStar,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QObjectStar,    8,   14,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::QObjectStar, QMetaType::Int,    8,
    QMetaType::QObjectStar, QMetaType::QObjectStar,   14,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QObjectStar,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   25,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QObjectStar,   14,

 // properties: name, type, flags
       5, QMetaType::Int, 0x00495001,
       2, 0x80000000 | 29, 0x00495009,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void ObjectListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ObjectListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->countChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->childrenChanged(); break;
        case 2: { QObject* _r = _t->at((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 3: { QObject* _r = _t->first();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 4: { QObject* _r = _t->last();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 5: _t->getRawData(); break;
        case 6: { int _r = _t->size();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->indexOf((*reinterpret_cast< QObject*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->append((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 9: _t->insert((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2]))); break;
        case 10: _t->reset((*reinterpret_cast< QObjectList(*)>(_a[1]))); break;
        case 11: _t->reset(); break;
        case 12: { QObject* _r = _t->takeAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 13: { QObject* _r = _t->take((*reinterpret_cast< QObject*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 14: _t->removeAt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->remove((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 16: _t->clearRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->notifyCount(); break;
        case 18: _t->propertyChanged(); break;
        case 19: _t->notifyPropertyChanged((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ObjectListModel::*)(int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ObjectListModel::countChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ObjectListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ObjectListModel::childrenChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ObjectListModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->size(); break;
        case 1: *reinterpret_cast< QQmlListProperty<QObject>*>(_v) = _t->children(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ObjectListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_ObjectListModel.data,
    qt_meta_data_ObjectListModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ObjectListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ObjectListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ObjectListModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int ObjectListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
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
void ObjectListModel::countChanged(int _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< ObjectListModel *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ObjectListModel::childrenChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
