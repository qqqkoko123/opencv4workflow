/****************************************************************************
** Meta object code from reading C++ file 'frmSelectShape.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmSelectShape.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmSelectShape.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmSelectShape_t {
    QByteArrayData data[13];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmSelectShape_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmSelectShape_t qt_meta_stringdata_frmSelectShape = {
    {
QT_MOC_LITERAL(0, 0, 14), // "frmSelectShape"
QT_MOC_LITERAL(1, 15, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(4, 59, 23), // "on_btnLinkImage_clicked"
QT_MOC_LITERAL(5, 83, 26), // "on_btnDelLinkImage_clicked"
QT_MOC_LITERAL(6, 110, 21), // "on_btnAddType_clicked"
QT_MOC_LITERAL(7, 132, 24), // "on_btnDeleteType_clicked"
QT_MOC_LITERAL(8, 157, 18), // "slot_DoubleClicked"
QT_MOC_LITERAL(9, 176, 20), // "on_btnAddROI_clicked"
QT_MOC_LITERAL(10, 197, 23), // "on_btnDeleteROI_clicked"
QT_MOC_LITERAL(11, 221, 22), // "on_btnRoiColor_clicked"
QT_MOC_LITERAL(12, 244, 16) // "slotCModeChanged"

    },
    "frmSelectShape\0onButtonCloseClicked\0"
    "\0on_btnExecute_clicked\0on_btnLinkImage_clicked\0"
    "on_btnDelLinkImage_clicked\0"
    "on_btnAddType_clicked\0on_btnDeleteType_clicked\0"
    "slot_DoubleClicked\0on_btnAddROI_clicked\0"
    "on_btnDeleteROI_clicked\0on_btnRoiColor_clicked\0"
    "slotCModeChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmSelectShape[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    2,   75,    2, 0x08 /* Private */,
       9,    0,   80,    2, 0x08 /* Private */,
      10,    0,   81,    2, 0x08 /* Private */,
      11,    0,   82,    2, 0x08 /* Private */,
      12,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void frmSelectShape::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmSelectShape *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonCloseClicked(); break;
        case 1: _t->on_btnExecute_clicked(); break;
        case 2: _t->on_btnLinkImage_clicked(); break;
        case 3: _t->on_btnDelLinkImage_clicked(); break;
        case 4: _t->on_btnAddType_clicked(); break;
        case 5: _t->on_btnDeleteType_clicked(); break;
        case 6: _t->slot_DoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->on_btnAddROI_clicked(); break;
        case 8: _t->on_btnDeleteROI_clicked(); break;
        case 9: _t->on_btnRoiColor_clicked(); break;
        case 10: _t->slotCModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmSelectShape::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmSelectShape.data,
    qt_meta_data_frmSelectShape,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmSelectShape::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmSelectShape::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmSelectShape.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmSelectShape::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
