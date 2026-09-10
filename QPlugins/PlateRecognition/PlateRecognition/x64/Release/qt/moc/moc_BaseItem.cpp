/****************************************************************************
** Meta object code from reading C++ file 'BaseItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../BaseItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BaseItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BaseItem_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaseItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaseItem_t qt_meta_stringdata_BaseItem = {
    {
QT_MOC_LITERAL(0, 0, 8) // "BaseItem"

    },
    "BaseItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void BaseItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject BaseItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BaseItem.data,
    qt_meta_data_BaseItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BaseItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BaseItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItemGroup"))
        return static_cast< QGraphicsItemGroup*>(this);
    return QObject::qt_metacast(_clname);
}

int BaseItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_DrawItem_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawItem_t qt_meta_stringdata_DrawItem = {
    {
QT_MOC_LITERAL(0, 0, 8) // "DrawItem"

    },
    "DrawItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DrawItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DrawItem::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseItem::staticMetaObject>(),
    qt_meta_stringdata_DrawItem.data,
    qt_meta_data_DrawItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawItem.stringdata0))
        return static_cast<void*>(this);
    return BaseItem::qt_metacast(_clname);
}

int DrawItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_RectangleItem_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RectangleItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RectangleItem_t qt_meta_stringdata_RectangleItem = {
    {
QT_MOC_LITERAL(0, 0, 13) // "RectangleItem"

    },
    "RectangleItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RectangleItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void RectangleItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject RectangleItem::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseItem::staticMetaObject>(),
    qt_meta_stringdata_RectangleItem.data,
    qt_meta_data_RectangleItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RectangleItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RectangleItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RectangleItem.stringdata0))
        return static_cast<void*>(this);
    return BaseItem::qt_metacast(_clname);
}

int RectangleItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_RectangleRItem_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RectangleRItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RectangleRItem_t qt_meta_stringdata_RectangleRItem = {
    {
QT_MOC_LITERAL(0, 0, 14) // "RectangleRItem"

    },
    "RectangleRItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RectangleRItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void RectangleRItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject RectangleRItem::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseItem::staticMetaObject>(),
    qt_meta_stringdata_RectangleRItem.data,
    qt_meta_data_RectangleRItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RectangleRItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RectangleRItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RectangleRItem.stringdata0))
        return static_cast<void*>(this);
    return BaseItem::qt_metacast(_clname);
}

int RectangleRItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_PolygonItem_t {
    QByteArrayData data[7];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PolygonItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PolygonItem_t qt_meta_stringdata_PolygonItem = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PolygonItem"
QT_MOC_LITERAL(1, 12, 9), // "pushPoint"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 1), // "p"
QT_MOC_LITERAL(4, 25, 14), // "QList<QPointF>"
QT_MOC_LITERAL(5, 40, 4), // "list"
QT_MOC_LITERAL(6, 45, 8) // "isCenter"

    },
    "PolygonItem\0pushPoint\0\0p\0QList<QPointF>\0"
    "list\0isCenter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PolygonItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF, 0x80000000 | 4, QMetaType::Bool,    3,    5,    6,

       0        // eod
};

void PolygonItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PolygonItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pushPoint((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QList<QPointF>(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QPointF> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PolygonItem::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseItem::staticMetaObject>(),
    qt_meta_stringdata_PolygonItem.data,
    qt_meta_data_PolygonItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PolygonItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PolygonItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PolygonItem.stringdata0))
        return static_cast<void*>(this);
    return BaseItem::qt_metacast(_clname);
}

int PolygonItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_EllipseItem_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EllipseItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EllipseItem_t qt_meta_stringdata_EllipseItem = {
    {
QT_MOC_LITERAL(0, 0, 11) // "EllipseItem"

    },
    "EllipseItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EllipseItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void EllipseItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject EllipseItem::staticMetaObject = { {
    QMetaObject::SuperData::link<RectangleRItem::staticMetaObject>(),
    qt_meta_stringdata_EllipseItem.data,
    qt_meta_data_EllipseItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EllipseItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EllipseItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EllipseItem.stringdata0))
        return static_cast<void*>(this);
    return RectangleRItem::qt_metacast(_clname);
}

int EllipseItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RectangleRItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_CircleItem_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CircleItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CircleItem_t qt_meta_stringdata_CircleItem = {
    {
QT_MOC_LITERAL(0, 0, 10) // "CircleItem"

    },
    "CircleItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CircleItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CircleItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CircleItem::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseItem::staticMetaObject>(),
    qt_meta_stringdata_CircleItem.data,
    qt_meta_data_CircleItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CircleItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CircleItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CircleItem.stringdata0))
        return static_cast<void*>(this);
    return BaseItem::qt_metacast(_clname);
}

int CircleItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ConcentricCircleItem_t {
    QByteArrayData data[1];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConcentricCircleItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConcentricCircleItem_t qt_meta_stringdata_ConcentricCircleItem = {
    {
QT_MOC_LITERAL(0, 0, 20) // "ConcentricCircleItem"

    },
    "ConcentricCircleItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConcentricCircleItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ConcentricCircleItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ConcentricCircleItem::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseItem::staticMetaObject>(),
    qt_meta_stringdata_ConcentricCircleItem.data,
    qt_meta_data_ConcentricCircleItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ConcentricCircleItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConcentricCircleItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConcentricCircleItem.stringdata0))
        return static_cast<void*>(this);
    return BaseItem::qt_metacast(_clname);
}

int ConcentricCircleItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_LineItem_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LineItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LineItem_t qt_meta_stringdata_LineItem = {
    {
QT_MOC_LITERAL(0, 0, 8) // "LineItem"

    },
    "LineItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void LineItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject LineItem::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseItem::staticMetaObject>(),
    qt_meta_stringdata_LineItem.data,
    qt_meta_data_LineItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LineItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LineItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LineItem.stringdata0))
        return static_cast<void*>(this);
    return BaseItem::qt_metacast(_clname);
}

int LineItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Caliper_t {
    QByteArrayData data[1];
    char stringdata0[8];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Caliper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Caliper_t qt_meta_stringdata_Caliper = {
    {
QT_MOC_LITERAL(0, 0, 7) // "Caliper"

    },
    "Caliper"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Caliper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Caliper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Caliper::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseItem::staticMetaObject>(),
    qt_meta_stringdata_Caliper.data,
    qt_meta_data_Caliper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Caliper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Caliper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Caliper.stringdata0))
        return static_cast<void*>(this);
    return BaseItem::qt_metacast(_clname);
}

int Caliper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseItem::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
