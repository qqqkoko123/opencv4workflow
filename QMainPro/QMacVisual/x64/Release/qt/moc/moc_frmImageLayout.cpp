/****************************************************************************
** Meta object code from reading C++ file 'frmImageLayout.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmImageLayout.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmImageLayout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmImageLayout_t {
    QByteArrayData data[11];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmImageLayout_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmImageLayout_t qt_meta_stringdata_frmImageLayout = {
    {
QT_MOC_LITERAL(0, 0, 14), // "frmImageLayout"
QT_MOC_LITERAL(1, 15, 10), // "sig_Image1"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "sig_Image2"
QT_MOC_LITERAL(4, 38, 10), // "sig_Image3"
QT_MOC_LITERAL(5, 49, 10), // "sig_Image4"
QT_MOC_LITERAL(6, 60, 11), // "sig_Image6A"
QT_MOC_LITERAL(7, 72, 11), // "sig_Image6B"
QT_MOC_LITERAL(8, 84, 10), // "sig_Image9"
QT_MOC_LITERAL(9, 95, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(10, 116, 10) // "slot_Image"

    },
    "frmImageLayout\0sig_Image1\0\0sig_Image2\0"
    "sig_Image3\0sig_Image4\0sig_Image6A\0"
    "sig_Image6B\0sig_Image9\0onButtonCloseClicked\0"
    "slot_Image"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmImageLayout[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    0,   64,    2, 0x06 /* Public */,
       8,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   66,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void frmImageLayout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmImageLayout *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_Image1(); break;
        case 1: _t->sig_Image2(); break;
        case 2: _t->sig_Image3(); break;
        case 3: _t->sig_Image4(); break;
        case 4: _t->sig_Image6A(); break;
        case 5: _t->sig_Image6B(); break;
        case 6: _t->sig_Image9(); break;
        case 7: _t->onButtonCloseClicked(); break;
        case 8: _t->slot_Image((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmImageLayout::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageLayout::sig_Image1)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmImageLayout::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageLayout::sig_Image2)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (frmImageLayout::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageLayout::sig_Image3)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (frmImageLayout::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageLayout::sig_Image4)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (frmImageLayout::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageLayout::sig_Image6A)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (frmImageLayout::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageLayout::sig_Image6B)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (frmImageLayout::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageLayout::sig_Image9)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmImageLayout::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_frmImageLayout.data,
    qt_meta_data_frmImageLayout,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmImageLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmImageLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmImageLayout.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int frmImageLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void frmImageLayout::sig_Image1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void frmImageLayout::sig_Image2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void frmImageLayout::sig_Image3()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void frmImageLayout::sig_Image4()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void frmImageLayout::sig_Image6A()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void frmImageLayout::sig_Image6B()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void frmImageLayout::sig_Image9()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
