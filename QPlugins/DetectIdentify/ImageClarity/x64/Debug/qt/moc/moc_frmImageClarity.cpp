/****************************************************************************
** Meta object code from reading C++ file 'frmImageClarity.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmImageClarity.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmImageClarity.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmImageClarity_t {
    QByteArrayData data[9];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmImageClarity_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmImageClarity_t qt_meta_stringdata_frmImageClarity = {
    {
QT_MOC_LITERAL(0, 0, 15), // "frmImageClarity"
QT_MOC_LITERAL(1, 16, 15), // "sig_PathMessage"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "sig_ClarityValue"
QT_MOC_LITERAL(4, 50, 7), // "InfoVal"
QT_MOC_LITERAL(5, 58, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(6, 79, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(7, 101, 24), // "on_btnSelectPath_clicked"
QT_MOC_LITERAL(8, 126, 16) // "slot_PathMessage"

    },
    "frmImageClarity\0sig_PathMessage\0\0"
    "sig_ClarityValue\0InfoVal\0onButtonCloseClicked\0"
    "on_btnExecute_clicked\0on_btnSelectPath_clicked\0"
    "slot_PathMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmImageClarity[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmImageClarity::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmImageClarity *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_PathMessage(); break;
        case 1: _t->sig_ClarityValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onButtonCloseClicked(); break;
        case 3: _t->on_btnExecute_clicked(); break;
        case 4: _t->on_btnSelectPath_clicked(); break;
        case 5: _t->slot_PathMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmImageClarity::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageClarity::sig_PathMessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmImageClarity::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageClarity::sig_ClarityValue)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmImageClarity::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmImageClarity.data,
    qt_meta_data_frmImageClarity,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmImageClarity::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmImageClarity::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmImageClarity.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmImageClarity::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void frmImageClarity::sig_PathMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void frmImageClarity::sig_ClarityValue(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
