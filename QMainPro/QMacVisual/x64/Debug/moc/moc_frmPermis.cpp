/****************************************************************************
** Meta object code from reading C++ file 'frmPermis.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../frmPermis.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmPermis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmPermis_t {
    QByteArrayData data[11];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmPermis_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmPermis_t qt_meta_stringdata_frmPermis = {
    {
QT_MOC_LITERAL(0, 0, 9), // "frmPermis"
QT_MOC_LITERAL(1, 10, 17), // "on_btnAdd_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 17), // "on_btnAdd_pressed"
QT_MOC_LITERAL(4, 47, 18), // "on_btnAdd_released"
QT_MOC_LITERAL(5, 66, 20), // "on_btnDelete_clicked"
QT_MOC_LITERAL(6, 87, 20), // "on_btnDelete_pressed"
QT_MOC_LITERAL(7, 108, 21), // "on_btnDelete_released"
QT_MOC_LITERAL(8, 130, 19), // "on_btnQuery_clicked"
QT_MOC_LITERAL(9, 150, 19), // "on_btnQuery_pressed"
QT_MOC_LITERAL(10, 170, 20) // "on_btnQuery_released"

    },
    "frmPermis\0on_btnAdd_clicked\0\0"
    "on_btnAdd_pressed\0on_btnAdd_released\0"
    "on_btnDelete_clicked\0on_btnDelete_pressed\0"
    "on_btnDelete_released\0on_btnQuery_clicked\0"
    "on_btnQuery_pressed\0on_btnQuery_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmPermis[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmPermis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmPermis *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnAdd_clicked(); break;
        case 1: _t->on_btnAdd_pressed(); break;
        case 2: _t->on_btnAdd_released(); break;
        case 3: _t->on_btnDelete_clicked(); break;
        case 4: _t->on_btnDelete_pressed(); break;
        case 5: _t->on_btnDelete_released(); break;
        case 6: _t->on_btnQuery_clicked(); break;
        case 7: _t->on_btnQuery_pressed(); break;
        case 8: _t->on_btnQuery_released(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject frmPermis::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseWindow::staticMetaObject>(),
    qt_meta_stringdata_frmPermis.data,
    qt_meta_data_frmPermis,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmPermis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmPermis::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmPermis.stringdata0))
        return static_cast<void*>(this);
    return BaseWindow::qt_metacast(_clname);
}

int frmPermis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
