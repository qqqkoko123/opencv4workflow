/****************************************************************************
** Meta object code from reading C++ file 'headwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../headwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'headwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HeadWidget_t {
    QByteArrayData data[9];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HeadWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HeadWidget_t qt_meta_stringdata_HeadWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HeadWidget"
QT_MOC_LITERAL(1, 11, 12), // "sigMinimized"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 18), // "sigToggleMaximized"
QT_MOC_LITERAL(4, 44, 8), // "sigClose"
QT_MOC_LITERAL(5, 53, 8), // "sigColor"
QT_MOC_LITERAL(6, 62, 3), // "pos"
QT_MOC_LITERAL(7, 66, 12), // "min_maxState"
QT_MOC_LITERAL(8, 79, 9) // "shot_Quit"

    },
    "HeadWidget\0sigMinimized\0\0sigToggleMaximized\0"
    "sigClose\0sigColor\0pos\0min_maxState\0"
    "shot_Quit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HeadWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HeadWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HeadWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigMinimized(); break;
        case 1: _t->sigToggleMaximized(); break;
        case 2: _t->sigClose(); break;
        case 3: _t->sigColor((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->min_maxState(); break;
        case 5: _t->shot_Quit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HeadWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeadWidget::sigMinimized)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HeadWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeadWidget::sigToggleMaximized)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HeadWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeadWidget::sigClose)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (HeadWidget::*)(const QPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeadWidget::sigColor)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HeadWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_HeadWidget.data,
    qt_meta_data_HeadWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HeadWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HeadWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HeadWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HeadWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void HeadWidget::sigMinimized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void HeadWidget::sigToggleMaximized()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HeadWidget::sigClose()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void HeadWidget::sigColor(const QPoint & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
