/****************************************************************************
** Meta object code from reading C++ file 'frmRegister.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmRegister.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmRegister.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmRegister_t {
    QByteArrayData data[14];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmRegister_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmRegister_t qt_meta_stringdata_frmRegister = {
    {
QT_MOC_LITERAL(0, 0, 11), // "frmRegister"
QT_MOC_LITERAL(1, 12, 12), // "form_statues"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 24), // "on_btnCmdCheckID_clicked"
QT_MOC_LITERAL(4, 51, 24), // "on_btnCmdCheckID_pressed"
QT_MOC_LITERAL(5, 76, 25), // "on_btnCmdCheckID_released"
QT_MOC_LITERAL(6, 102, 6), // "GetKey"
QT_MOC_LITERAL(7, 109, 3), // "str"
QT_MOC_LITERAL(8, 113, 7), // "getWMIC"
QT_MOC_LITERAL(9, 121, 3), // "cmd"
QT_MOC_LITERAL(10, 125, 18), // "getCpuSerialNumber"
QT_MOC_LITERAL(11, 144, 26), // "getMotherboardSerialNumber"
QT_MOC_LITERAL(12, 171, 19), // "getBIOSSerialNumber"
QT_MOC_LITERAL(13, 191, 19) // "getDiskSerialNumber"

    },
    "frmRegister\0form_statues\0\0"
    "on_btnCmdCheckID_clicked\0"
    "on_btnCmdCheckID_pressed\0"
    "on_btnCmdCheckID_released\0GetKey\0str\0"
    "getWMIC\0cmd\0getCpuSerialNumber\0"
    "getMotherboardSerialNumber\0"
    "getBIOSSerialNumber\0getDiskSerialNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmRegister[] = {

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
       6,    1,   68,    2, 0x08 /* Private */,
       8,    1,   71,    2, 0x08 /* Private */,
      10,    0,   74,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,    7,
    QMetaType::QString, QMetaType::QString,    9,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,

       0        // eod
};

void frmRegister::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmRegister *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->form_statues(); break;
        case 1: _t->on_btnCmdCheckID_clicked(); break;
        case 2: _t->on_btnCmdCheckID_pressed(); break;
        case 3: _t->on_btnCmdCheckID_released(); break;
        case 4: { QString _r = _t->GetKey((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getWMIC((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getCpuSerialNumber();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->getMotherboardSerialNumber();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->getBIOSSerialNumber();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->getDiskSerialNumber();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmRegister::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_frmRegister.data,
    qt_meta_data_frmRegister,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmRegister::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmRegister::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmRegister.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int frmRegister::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
