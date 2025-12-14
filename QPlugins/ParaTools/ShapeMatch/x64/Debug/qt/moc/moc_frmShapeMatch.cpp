/****************************************************************************
** Meta object code from reading C++ file 'frmShapeMatch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmShapeMatch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmShapeMatch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmShapeMatch_t {
    QByteArrayData data[15];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmShapeMatch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmShapeMatch_t qt_meta_stringdata_frmShapeMatch = {
    {
QT_MOC_LITERAL(0, 0, 13), // "frmShapeMatch"
QT_MOC_LITERAL(1, 14, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(4, 58, 23), // "on_btnLinkImage_clicked"
QT_MOC_LITERAL(5, 82, 26), // "on_btnDelLinkImage_clicked"
QT_MOC_LITERAL(6, 109, 20), // "on_btnAddROI_clicked"
QT_MOC_LITERAL(7, 130, 23), // "on_btnDeleteROI_clicked"
QT_MOC_LITERAL(8, 154, 22), // "on_btnAddROI_2_clicked"
QT_MOC_LITERAL(9, 177, 25), // "on_btnDeleteROI_2_clicked"
QT_MOC_LITERAL(10, 203, 23), // "on_btnCreateROI_clicked"
QT_MOC_LITERAL(11, 227, 25), // "on_btnDeleteModel_clicked"
QT_MOC_LITERAL(12, 253, 22), // "on_btnRoiColor_clicked"
QT_MOC_LITERAL(13, 276, 36), // "on_comboViewMode_currentIndex..."
QT_MOC_LITERAL(14, 313, 5) // "index"

    },
    "frmShapeMatch\0onButtonCloseClicked\0\0"
    "on_btnExecute_clicked\0on_btnLinkImage_clicked\0"
    "on_btnDelLinkImage_clicked\0"
    "on_btnAddROI_clicked\0on_btnDeleteROI_clicked\0"
    "on_btnAddROI_2_clicked\0on_btnDeleteROI_2_clicked\0"
    "on_btnCreateROI_clicked\0"
    "on_btnDeleteModel_clicked\0"
    "on_btnRoiColor_clicked\0"
    "on_comboViewMode_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmShapeMatch[] = {

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
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    1,   85,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void frmShapeMatch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmShapeMatch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonCloseClicked(); break;
        case 1: _t->on_btnExecute_clicked(); break;
        case 2: _t->on_btnLinkImage_clicked(); break;
        case 3: _t->on_btnDelLinkImage_clicked(); break;
        case 4: _t->on_btnAddROI_clicked(); break;
        case 5: _t->on_btnDeleteROI_clicked(); break;
        case 6: _t->on_btnAddROI_2_clicked(); break;
        case 7: _t->on_btnDeleteROI_2_clicked(); break;
        case 8: _t->on_btnCreateROI_clicked(); break;
        case 9: _t->on_btnDeleteModel_clicked(); break;
        case 10: _t->on_btnRoiColor_clicked(); break;
        case 11: _t->on_comboViewMode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmShapeMatch::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmShapeMatch.data,
    qt_meta_data_frmShapeMatch,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmShapeMatch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmShapeMatch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmShapeMatch.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmShapeMatch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
