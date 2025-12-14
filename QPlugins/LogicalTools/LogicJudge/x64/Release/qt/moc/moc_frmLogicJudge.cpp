/****************************************************************************
** Meta object code from reading C++ file 'frmLogicJudge.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmLogicJudge.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmLogicJudge.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmLogicJudge_t {
    QByteArrayData data[10];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmLogicJudge_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmLogicJudge_t qt_meta_stringdata_frmLogicJudge = {
    {
QT_MOC_LITERAL(0, 0, 13), // "frmLogicJudge"
QT_MOC_LITERAL(1, 14, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(4, 58, 22), // "on_btnLinkBool_clicked"
QT_MOC_LITERAL(5, 81, 25), // "on_btnDelLinkBool_clicked"
QT_MOC_LITERAL(6, 107, 23), // "on_btnLinkRegex_clicked"
QT_MOC_LITERAL(7, 131, 26), // "on_btnDelLinkRegex_clicked"
QT_MOC_LITERAL(8, 158, 32), // "on_comboType_currentIndexChanged"
QT_MOC_LITERAL(9, 191, 5) // "index"

    },
    "frmLogicJudge\0onButtonCloseClicked\0\0"
    "on_btnExecute_clicked\0on_btnLinkBool_clicked\0"
    "on_btnDelLinkBool_clicked\0"
    "on_btnLinkRegex_clicked\0"
    "on_btnDelLinkRegex_clicked\0"
    "on_comboType_currentIndexChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmLogicJudge[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void frmLogicJudge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmLogicJudge *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonCloseClicked(); break;
        case 1: _t->on_btnExecute_clicked(); break;
        case 2: _t->on_btnLinkBool_clicked(); break;
        case 3: _t->on_btnDelLinkBool_clicked(); break;
        case 4: _t->on_btnLinkRegex_clicked(); break;
        case 5: _t->on_btnDelLinkRegex_clicked(); break;
        case 6: _t->on_comboType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmLogicJudge::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmLogicJudge.data,
    qt_meta_data_frmLogicJudge,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmLogicJudge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmLogicJudge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmLogicJudge.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmLogicJudge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
