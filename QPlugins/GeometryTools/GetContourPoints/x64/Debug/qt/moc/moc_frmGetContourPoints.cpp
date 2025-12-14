/****************************************************************************
** Meta object code from reading C++ file 'frmGetContourPoints.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmGetContourPoints.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmGetContourPoints.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmGetContourPoints_t {
    QByteArrayData data[9];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmGetContourPoints_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmGetContourPoints_t qt_meta_stringdata_frmGetContourPoints = {
    {
QT_MOC_LITERAL(0, 0, 19), // "frmGetContourPoints"
QT_MOC_LITERAL(1, 20, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(4, 64, 23), // "on_btnLinkImage_clicked"
QT_MOC_LITERAL(5, 88, 26), // "on_btnDelLinkImage_clicked"
QT_MOC_LITERAL(6, 115, 20), // "on_btnAddROI_clicked"
QT_MOC_LITERAL(7, 136, 23), // "on_btnDeleteROI_clicked"
QT_MOC_LITERAL(8, 160, 22) // "on_btnRoiColor_clicked"

    },
    "frmGetContourPoints\0onButtonCloseClicked\0"
    "\0on_btnExecute_clicked\0on_btnLinkImage_clicked\0"
    "on_btnDelLinkImage_clicked\0"
    "on_btnAddROI_clicked\0on_btnDeleteROI_clicked\0"
    "on_btnRoiColor_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmGetContourPoints[] = {

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
       8,    0,   55,    2, 0x08 /* Private */,

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

void frmGetContourPoints::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmGetContourPoints *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonCloseClicked(); break;
        case 1: _t->on_btnExecute_clicked(); break;
        case 2: _t->on_btnLinkImage_clicked(); break;
        case 3: _t->on_btnDelLinkImage_clicked(); break;
        case 4: _t->on_btnAddROI_clicked(); break;
        case 5: _t->on_btnDeleteROI_clicked(); break;
        case 6: _t->on_btnRoiColor_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject frmGetContourPoints::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmGetContourPoints.data,
    qt_meta_data_frmGetContourPoints,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmGetContourPoints::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmGetContourPoints::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmGetContourPoints.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmGetContourPoints::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
