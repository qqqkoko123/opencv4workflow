/****************************************************************************
** Meta object code from reading C++ file 'frmFlatness.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmFlatness.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmFlatness.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmFlatness_t {
    QByteArrayData data[12];
    char stringdata0[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmFlatness_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmFlatness_t qt_meta_stringdata_frmFlatness = {
    {
QT_MOC_LITERAL(0, 0, 11), // "frmFlatness"
QT_MOC_LITERAL(1, 12, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(4, 56, 25), // "on_btnLinkPointsX_clicked"
QT_MOC_LITERAL(5, 82, 28), // "on_btnDelLinkPointsX_clicked"
QT_MOC_LITERAL(6, 111, 25), // "on_btnLinkPointsY_clicked"
QT_MOC_LITERAL(7, 137, 28), // "on_btnDelLinkPointsY_clicked"
QT_MOC_LITERAL(8, 166, 25), // "on_btnLinkPointsZ_clicked"
QT_MOC_LITERAL(9, 192, 28), // "on_btnDelLinkPointsZ_clicked"
QT_MOC_LITERAL(10, 221, 25), // "on_btnLink3DPoint_clicked"
QT_MOC_LITERAL(11, 247, 28) // "on_btnDelLink3DPoint_clicked"

    },
    "frmFlatness\0onButtonCloseClicked\0\0"
    "on_btnExecute_clicked\0on_btnLinkPointsX_clicked\0"
    "on_btnDelLinkPointsX_clicked\0"
    "on_btnLinkPointsY_clicked\0"
    "on_btnDelLinkPointsY_clicked\0"
    "on_btnLinkPointsZ_clicked\0"
    "on_btnDelLinkPointsZ_clicked\0"
    "on_btnLink3DPoint_clicked\0"
    "on_btnDelLink3DPoint_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmFlatness[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

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
    QMetaType::Void,

       0        // eod
};

void frmFlatness::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmFlatness *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonCloseClicked(); break;
        case 1: _t->on_btnExecute_clicked(); break;
        case 2: _t->on_btnLinkPointsX_clicked(); break;
        case 3: _t->on_btnDelLinkPointsX_clicked(); break;
        case 4: _t->on_btnLinkPointsY_clicked(); break;
        case 5: _t->on_btnDelLinkPointsY_clicked(); break;
        case 6: _t->on_btnLinkPointsZ_clicked(); break;
        case 7: _t->on_btnDelLinkPointsZ_clicked(); break;
        case 8: _t->on_btnLink3DPoint_clicked(); break;
        case 9: _t->on_btnDelLink3DPoint_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject frmFlatness::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmFlatness.data,
    qt_meta_data_frmFlatness,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmFlatness::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmFlatness::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmFlatness.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmFlatness::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
