/****************************************************************************
** Meta object code from reading C++ file 'frmLogin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmLogin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmLogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmLogin_t {
    QByteArrayData data[12];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmLogin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmLogin_t qt_meta_stringdata_frmLogin = {
    {
QT_MOC_LITERAL(0, 0, 8), // "frmLogin"
QT_MOC_LITERAL(1, 9, 15), // "sendLoginSignal"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "sendInStateSignal"
QT_MOC_LITERAL(4, 44, 18), // "sendOutStateSignal"
QT_MOC_LITERAL(5, 63, 9), // "form_load"
QT_MOC_LITERAL(6, 73, 20), // "on_btnLogout_clicked"
QT_MOC_LITERAL(7, 94, 20), // "on_btnLogout_pressed"
QT_MOC_LITERAL(8, 115, 21), // "on_btnLogout_released"
QT_MOC_LITERAL(9, 137, 19), // "on_btnLogin_clicked"
QT_MOC_LITERAL(10, 157, 19), // "on_btnLogin_pressed"
QT_MOC_LITERAL(11, 177, 20) // "on_btnLogin_released"

    },
    "frmLogin\0sendLoginSignal\0\0sendInStateSignal\0"
    "sendOutStateSignal\0form_load\0"
    "on_btnLogout_clicked\0on_btnLogout_pressed\0"
    "on_btnLogout_released\0on_btnLogin_clicked\0"
    "on_btnLogin_pressed\0on_btnLogin_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmLogin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmLogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmLogin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendLoginSignal(); break;
        case 1: _t->sendInStateSignal(); break;
        case 2: _t->sendOutStateSignal(); break;
        case 3: _t->form_load(); break;
        case 4: _t->on_btnLogout_clicked(); break;
        case 5: _t->on_btnLogout_pressed(); break;
        case 6: _t->on_btnLogout_released(); break;
        case 7: _t->on_btnLogin_clicked(); break;
        case 8: _t->on_btnLogin_pressed(); break;
        case 9: _t->on_btnLogin_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmLogin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmLogin::sendLoginSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmLogin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmLogin::sendInStateSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (frmLogin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmLogin::sendOutStateSignal)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject frmLogin::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseWindow::staticMetaObject>(),
    qt_meta_stringdata_frmLogin.data,
    qt_meta_data_frmLogin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmLogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmLogin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmLogin.stringdata0))
        return static_cast<void*>(this);
    return BaseWindow::qt_metacast(_clname);
}

int frmLogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void frmLogin::sendLoginSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void frmLogin::sendInStateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void frmLogin::sendOutStateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
