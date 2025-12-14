/****************************************************************************
** Meta object code from reading C++ file 'frmLogicGoto.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmLogicGoto.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmLogicGoto.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmLogicGoto_t {
    QByteArrayData data[11];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmLogicGoto_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmLogicGoto_t qt_meta_stringdata_frmLogicGoto = {
    {
QT_MOC_LITERAL(0, 0, 12), // "frmLogicGoto"
QT_MOC_LITERAL(1, 13, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(4, 57, 22), // "on_btnLinkBool_clicked"
QT_MOC_LITERAL(5, 80, 25), // "on_btnDelLinkBool_clicked"
QT_MOC_LITERAL(6, 106, 23), // "on_btnLinkRegex_clicked"
QT_MOC_LITERAL(7, 130, 26), // "on_btnDelLinkRegex_clicked"
QT_MOC_LITERAL(8, 157, 32), // "on_comboType_currentIndexChanged"
QT_MOC_LITERAL(9, 190, 5), // "index"
QT_MOC_LITERAL(10, 196, 20) // "on_btnUpdata_clicked"

    },
    "frmLogicGoto\0onButtonCloseClicked\0\0"
    "on_btnExecute_clicked\0on_btnLinkBool_clicked\0"
    "on_btnDelLinkBool_clicked\0"
    "on_btnLinkRegex_clicked\0"
    "on_btnDelLinkRegex_clicked\0"
    "on_comboType_currentIndexChanged\0index\0"
    "on_btnUpdata_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmLogicGoto[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

       0        // eod
};

void frmLogicGoto::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmLogicGoto *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonCloseClicked(); break;
        case 1: _t->on_btnExecute_clicked(); break;
        case 2: _t->on_btnLinkBool_clicked(); break;
        case 3: _t->on_btnDelLinkBool_clicked(); break;
        case 4: _t->on_btnLinkRegex_clicked(); break;
        case 5: _t->on_btnDelLinkRegex_clicked(); break;
        case 6: _t->on_comboType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_btnUpdata_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmLogicGoto::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmLogicGoto.data,
    qt_meta_data_frmLogicGoto,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmLogicGoto::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmLogicGoto::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmLogicGoto.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmLogicGoto::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
