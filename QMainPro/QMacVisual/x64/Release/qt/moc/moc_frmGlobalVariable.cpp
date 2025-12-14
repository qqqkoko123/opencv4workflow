/****************************************************************************
** Meta object code from reading C++ file 'frmGlobalVariable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmGlobalVariable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmGlobalVariable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmGlobalVariable_t {
    QByteArrayData data[13];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmGlobalVariable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmGlobalVariable_t qt_meta_stringdata_frmGlobalVariable = {
    {
QT_MOC_LITERAL(0, 0, 17), // "frmGlobalVariable"
QT_MOC_LITERAL(1, 18, 15), // "sig_GlobalValue"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 6), // "strVar"
QT_MOC_LITERAL(4, 42, 5), // "value"
QT_MOC_LITERAL(5, 48, 9), // "flowIndex"
QT_MOC_LITERAL(6, 58, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(7, 79, 17), // "on_btnAdd_clicked"
QT_MOC_LITERAL(8, 97, 20), // "on_btnDelete_clicked"
QT_MOC_LITERAL(9, 118, 20), // "on_btnMoveUp_clicked"
QT_MOC_LITERAL(10, 139, 22), // "on_btnMoveDown_clicked"
QT_MOC_LITERAL(11, 162, 16), // "slot_GlobalValue"
QT_MOC_LITERAL(12, 179, 19) // "slot_SetGlobalValue"

    },
    "frmGlobalVariable\0sig_GlobalValue\0\0"
    "strVar\0value\0flowIndex\0onButtonCloseClicked\0"
    "on_btnAdd_clicked\0on_btnDelete_clicked\0"
    "on_btnMoveUp_clicked\0on_btnMoveDown_clicked\0"
    "slot_GlobalValue\0slot_SetGlobalValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmGlobalVariable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   61,    2, 0x0a /* Public */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,
      11,    3,   66,    2, 0x08 /* Private */,
      12,    3,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    4,    5,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    4,    5,

       0        // eod
};

void frmGlobalVariable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmGlobalVariable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->sig_GlobalValue((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->onButtonCloseClicked(); break;
        case 2: _t->on_btnAdd_clicked(); break;
        case 3: _t->on_btnDelete_clicked(); break;
        case 4: _t->on_btnMoveUp_clicked(); break;
        case 5: _t->on_btnMoveDown_clicked(); break;
        case 6: { QString _r = _t->slot_GlobalValue((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->slot_SetGlobalValue((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = QString (frmGlobalVariable::*)(const QString , const QString , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmGlobalVariable::sig_GlobalValue)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmGlobalVariable::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_frmGlobalVariable.data,
    qt_meta_data_frmGlobalVariable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmGlobalVariable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmGlobalVariable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmGlobalVariable.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int frmGlobalVariable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
QString frmGlobalVariable::sig_GlobalValue(const QString _t1, const QString _t2, const int _t3)
{
    QString _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
