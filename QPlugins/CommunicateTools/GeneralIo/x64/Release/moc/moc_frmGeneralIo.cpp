/****************************************************************************
** Meta object code from reading C++ file 'frmGeneralIo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../frmGeneralIo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmGeneralIo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmGeneralIo_t {
    QByteArrayData data[5];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmGeneralIo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmGeneralIo_t qt_meta_stringdata_frmGeneralIo = {
    {
QT_MOC_LITERAL(0, 0, 12), // "frmGeneralIo"
QT_MOC_LITERAL(1, 13, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(4, 57, 20) // "on_btnUpdata_clicked"

    },
    "frmGeneralIo\0onButtonCloseClicked\0\0"
    "on_btnExecute_clicked\0on_btnUpdata_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmGeneralIo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmGeneralIo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmGeneralIo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonCloseClicked(); break;
        case 1: _t->on_btnExecute_clicked(); break;
        case 2: _t->on_btnUpdata_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject frmGeneralIo::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmGeneralIo.data,
    qt_meta_data_frmGeneralIo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmGeneralIo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmGeneralIo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmGeneralIo.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmGeneralIo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
