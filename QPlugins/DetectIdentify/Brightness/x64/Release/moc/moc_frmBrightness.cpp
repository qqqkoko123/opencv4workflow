/****************************************************************************
** Meta object code from reading C++ file 'frmBrightness.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../frmBrightness.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmBrightness.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmBrightness_t {
    QByteArrayData data[8];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmBrightness_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmBrightness_t qt_meta_stringdata_frmBrightness = {
    {
QT_MOC_LITERAL(0, 0, 13), // "frmBrightness"
QT_MOC_LITERAL(1, 14, 19), // "sig_BrightnessValue"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 7), // "InfoVal"
QT_MOC_LITERAL(4, 43, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(5, 64, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(6, 86, 23), // "on_btnLinkImage_clicked"
QT_MOC_LITERAL(7, 110, 26) // "on_btnDelLinkImage_clicked"

    },
    "frmBrightness\0sig_BrightnessValue\0\0"
    "InfoVal\0onButtonCloseClicked\0"
    "on_btnExecute_clicked\0on_btnLinkImage_clicked\0"
    "on_btnDelLinkImage_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmBrightness[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmBrightness::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmBrightness *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_BrightnessValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->onButtonCloseClicked(); break;
        case 2: _t->on_btnExecute_clicked(); break;
        case 3: _t->on_btnLinkImage_clicked(); break;
        case 4: _t->on_btnDelLinkImage_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmBrightness::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmBrightness::sig_BrightnessValue)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmBrightness::staticMetaObject = { {
    &Toolnterface::staticMetaObject,
    qt_meta_stringdata_frmBrightness.data,
    qt_meta_data_frmBrightness,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmBrightness::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmBrightness::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmBrightness.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmBrightness::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void frmBrightness::sig_BrightnessValue(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
