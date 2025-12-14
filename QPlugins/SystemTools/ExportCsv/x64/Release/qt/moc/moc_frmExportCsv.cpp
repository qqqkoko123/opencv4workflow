/****************************************************************************
** Meta object code from reading C++ file 'frmExportCsv.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmExportCsv.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmExportCsv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmExportCsv_t {
    QByteArrayData data[14];
    char stringdata0[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmExportCsv_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmExportCsv_t qt_meta_stringdata_frmExportCsv = {
    {
QT_MOC_LITERAL(0, 0, 12), // "frmExportCsv"
QT_MOC_LITERAL(1, 13, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 10), // "timerEvent"
QT_MOC_LITERAL(4, 46, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(5, 68, 25), // "on_btnStoragePath_clicked"
QT_MOC_LITERAL(6, 94, 24), // "on_btnAddContent_clicked"
QT_MOC_LITERAL(7, 119, 27), // "on_btnDeleteContent_clicked"
QT_MOC_LITERAL(8, 147, 19), // "on_btnWrite_clicked"
QT_MOC_LITERAL(9, 167, 20), // "on_btnMoveUp_clicked"
QT_MOC_LITERAL(10, 188, 22), // "on_btnMoveDown_clicked"
QT_MOC_LITERAL(11, 211, 24), // "slot_CurrentIndexChanged"
QT_MOC_LITERAL(12, 236, 18), // "slot_DoubleClicked"
QT_MOC_LITERAL(13, 255, 35) // "on_comboTypeBuf_currentIndexC..."

    },
    "frmExportCsv\0onButtonCloseClicked\0\0"
    "timerEvent\0on_btnExecute_clicked\0"
    "on_btnStoragePath_clicked\0"
    "on_btnAddContent_clicked\0"
    "on_btnDeleteContent_clicked\0"
    "on_btnWrite_clicked\0on_btnMoveUp_clicked\0"
    "on_btnMoveDown_clicked\0slot_CurrentIndexChanged\0"
    "slot_DoubleClicked\0"
    "on_comboTypeBuf_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmExportCsv[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    1,   83,    2, 0x08 /* Private */,
      12,    2,   86,    2, 0x08 /* Private */,
      13,    1,   91,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void frmExportCsv::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmExportCsv *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonCloseClicked(); break;
        case 1: _t->timerEvent(); break;
        case 2: _t->on_btnExecute_clicked(); break;
        case 3: _t->on_btnStoragePath_clicked(); break;
        case 4: _t->on_btnAddContent_clicked(); break;
        case 5: _t->on_btnDeleteContent_clicked(); break;
        case 6: _t->on_btnWrite_clicked(); break;
        case 7: _t->on_btnMoveUp_clicked(); break;
        case 8: _t->on_btnMoveDown_clicked(); break;
        case 9: _t->slot_CurrentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->slot_DoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->on_comboTypeBuf_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmExportCsv::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmExportCsv.data,
    qt_meta_data_frmExportCsv,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmExportCsv::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmExportCsv::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmExportCsv.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmExportCsv::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
