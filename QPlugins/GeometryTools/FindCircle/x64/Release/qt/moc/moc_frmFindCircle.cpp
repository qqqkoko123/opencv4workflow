/****************************************************************************
** Meta object code from reading C++ file 'frmFindCircle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmFindCircle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmFindCircle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmFindCircle_t {
    QByteArrayData data[13];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmFindCircle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmFindCircle_t qt_meta_stringdata_frmFindCircle = {
    {
QT_MOC_LITERAL(0, 0, 13), // "frmFindCircle"
QT_MOC_LITERAL(1, 14, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(4, 58, 23), // "on_btnLinkImage_clicked"
QT_MOC_LITERAL(5, 82, 26), // "on_btnDelLinkImage_clicked"
QT_MOC_LITERAL(6, 109, 24), // "on_btnLinkFollow_clicked"
QT_MOC_LITERAL(7, 134, 27), // "on_btnDelLinkFollow_clicked"
QT_MOC_LITERAL(8, 162, 20), // "on_btnAddROI_clicked"
QT_MOC_LITERAL(9, 183, 23), // "on_btnDeleteROI_clicked"
QT_MOC_LITERAL(10, 207, 22), // "on_btnRoiColor_clicked"
QT_MOC_LITERAL(11, 230, 27), // "on_spinSegment_valueChanged"
QT_MOC_LITERAL(12, 258, 5) // "value"

    },
    "frmFindCircle\0onButtonCloseClicked\0\0"
    "on_btnExecute_clicked\0on_btnLinkImage_clicked\0"
    "on_btnDelLinkImage_clicked\0"
    "on_btnLinkFollow_clicked\0"
    "on_btnDelLinkFollow_clicked\0"
    "on_btnAddROI_clicked\0on_btnDeleteROI_clicked\0"
    "on_btnRoiColor_clicked\0"
    "on_spinSegment_valueChanged\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmFindCircle[] = {

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
      11,    1,   73,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void frmFindCircle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmFindCircle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonCloseClicked(); break;
        case 1: _t->on_btnExecute_clicked(); break;
        case 2: _t->on_btnLinkImage_clicked(); break;
        case 3: _t->on_btnDelLinkImage_clicked(); break;
        case 4: _t->on_btnLinkFollow_clicked(); break;
        case 5: _t->on_btnDelLinkFollow_clicked(); break;
        case 6: _t->on_btnAddROI_clicked(); break;
        case 7: _t->on_btnDeleteROI_clicked(); break;
        case 8: _t->on_btnRoiColor_clicked(); break;
        case 9: _t->on_spinSegment_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmFindCircle::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmFindCircle.data,
    qt_meta_data_frmFindCircle,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmFindCircle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmFindCircle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmFindCircle.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmFindCircle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
