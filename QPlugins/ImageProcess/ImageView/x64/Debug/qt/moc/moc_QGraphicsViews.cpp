/****************************************************************************
** Meta object code from reading C++ file 'QGraphicsViews.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../QGraphicsViews.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QGraphicsViews.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGraphicsViews_t {
    QByteArrayData data[14];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGraphicsViews_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGraphicsViews_t qt_meta_stringdata_QGraphicsViews = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QGraphicsViews"
QT_MOC_LITERAL(1, 15, 9), // "DispImage"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "Image"
QT_MOC_LITERAL(4, 32, 9), // "DispPoint"
QT_MOC_LITERAL(5, 42, 17), // "QVector<QPointF>&"
QT_MOC_LITERAL(6, 60, 4), // "list"
QT_MOC_LITERAL(7, 65, 5), // "color"
QT_MOC_LITERAL(8, 71, 8), // "AddItems"
QT_MOC_LITERAL(9, 80, 9), // "BaseItem*"
QT_MOC_LITERAL(10, 90, 4), // "item"
QT_MOC_LITERAL(11, 95, 7), // "SetType"
QT_MOC_LITERAL(12, 103, 7), // "InfoFlg"
QT_MOC_LITERAL(13, 111, 12) // "GrayValueFlg"

    },
    "QGraphicsViews\0DispImage\0\0Image\0"
    "DispPoint\0QVector<QPointF>&\0list\0color\0"
    "AddItems\0BaseItem*\0item\0SetType\0InfoFlg\0"
    "GrayValueFlg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGraphicsViews[] = {

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
       1,    1,   39,    2, 0x0a /* Public */,
       4,    2,   42,    2, 0x0a /* Public */,
       4,    1,   47,    2, 0x2a /* Public | MethodCloned */,
       8,    1,   50,    2, 0x0a /* Public */,
      11,    2,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QColor,    6,    7,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   12,   13,

       0        // eod
};

void QGraphicsViews::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QGraphicsViews *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DispImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->DispPoint((*reinterpret_cast< QVector<QPointF>(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 2: _t->DispPoint((*reinterpret_cast< QVector<QPointF>(*)>(_a[1]))); break;
        case 3: _t->AddItems((*reinterpret_cast< BaseItem*(*)>(_a[1]))); break;
        case 4: _t->SetType((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BaseItem* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGraphicsViews::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_QGraphicsViews.data,
    qt_meta_data_QGraphicsViews,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGraphicsViews::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsViews::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGraphicsViews.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int QGraphicsViews::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
