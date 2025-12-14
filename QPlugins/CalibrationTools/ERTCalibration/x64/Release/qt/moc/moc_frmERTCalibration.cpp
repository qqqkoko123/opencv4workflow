/****************************************************************************
** Meta object code from reading C++ file 'frmERTCalibration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmERTCalibration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmERTCalibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmERTCalibration_t {
    QByteArrayData data[14];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmERTCalibration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmERTCalibration_t qt_meta_stringdata_frmERTCalibration = {
    {
QT_MOC_LITERAL(0, 0, 17), // "frmERTCalibration"
QT_MOC_LITERAL(1, 18, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 12), // "onRadioClick"
QT_MOC_LITERAL(4, 53, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(5, 75, 23), // "on_btnLinkImage_clicked"
QT_MOC_LITERAL(6, 99, 26), // "on_btnDelLinkImage_clicked"
QT_MOC_LITERAL(7, 126, 20), // "on_btnAddROI_clicked"
QT_MOC_LITERAL(8, 147, 23), // "on_btnDeleteROI_clicked"
QT_MOC_LITERAL(9, 171, 23), // "on_btnGetCenter_clicked"
QT_MOC_LITERAL(10, 195, 27), // "on_spinSegment_valueChanged"
QT_MOC_LITERAL(11, 223, 5), // "value"
QT_MOC_LITERAL(12, 229, 39), // "on_comboCalibMethod_currentIn..."
QT_MOC_LITERAL(13, 269, 5) // "index"

    },
    "frmERTCalibration\0onButtonCloseClicked\0"
    "\0onRadioClick\0on_btnExecute_clicked\0"
    "on_btnLinkImage_clicked\0"
    "on_btnDelLinkImage_clicked\0"
    "on_btnAddROI_clicked\0on_btnDeleteROI_clicked\0"
    "on_btnGetCenter_clicked\0"
    "on_spinSegment_valueChanged\0value\0"
    "on_comboCalibMethod_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmERTCalibration[] = {

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
       3,    1,   65,    2, 0x08 /* Private */,
       4,    0,   68,    2, 0x08 /* Private */,
       5,    0,   69,    2, 0x08 /* Private */,
       6,    0,   70,    2, 0x08 /* Private */,
       7,    0,   71,    2, 0x08 /* Private */,
       8,    0,   72,    2, 0x08 /* Private */,
       9,    0,   73,    2, 0x08 /* Private */,
      10,    1,   74,    2, 0x08 /* Private */,
      12,    1,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void frmERTCalibration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmERTCalibration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonCloseClicked(); break;
        case 1: _t->onRadioClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_btnExecute_clicked(); break;
        case 3: _t->on_btnLinkImage_clicked(); break;
        case 4: _t->on_btnDelLinkImage_clicked(); break;
        case 5: _t->on_btnAddROI_clicked(); break;
        case 6: _t->on_btnDeleteROI_clicked(); break;
        case 7: _t->on_btnGetCenter_clicked(); break;
        case 8: _t->on_spinSegment_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_comboCalibMethod_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmERTCalibration::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmERTCalibration.data,
    qt_meta_data_frmERTCalibration,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmERTCalibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmERTCalibration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmERTCalibration.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmERTCalibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
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
