/****************************************************************************
** Meta object code from reading C++ file 'frmTemplateMatch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmTemplateMatch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmTemplateMatch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmTemplateMatch_t {
    QByteArrayData data[16];
    char stringdata0[355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmTemplateMatch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmTemplateMatch_t qt_meta_stringdata_frmTemplateMatch = {
    {
QT_MOC_LITERAL(0, 0, 16), // "frmTemplateMatch"
QT_MOC_LITERAL(1, 17, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(4, 61, 23), // "on_btnLinkImage_clicked"
QT_MOC_LITERAL(5, 85, 26), // "on_btnDelLinkImage_clicked"
QT_MOC_LITERAL(6, 112, 20), // "on_btnAddROI_clicked"
QT_MOC_LITERAL(7, 133, 23), // "on_btnDeleteROI_clicked"
QT_MOC_LITERAL(8, 157, 22), // "on_btnAddROI_2_clicked"
QT_MOC_LITERAL(9, 180, 25), // "on_btnDeleteROI_2_clicked"
QT_MOC_LITERAL(10, 206, 23), // "on_btnCreateROI_clicked"
QT_MOC_LITERAL(11, 230, 25), // "on_btnDeleteModel_clicked"
QT_MOC_LITERAL(12, 256, 22), // "on_btnRoiColor_clicked"
QT_MOC_LITERAL(13, 279, 32), // "on_comboMode_currentIndexChanged"
QT_MOC_LITERAL(14, 312, 5), // "index"
QT_MOC_LITERAL(15, 318, 36) // "on_comboViewMode_currentIndex..."

    },
    "frmTemplateMatch\0onButtonCloseClicked\0"
    "\0on_btnExecute_clicked\0on_btnLinkImage_clicked\0"
    "on_btnDelLinkImage_clicked\0"
    "on_btnAddROI_clicked\0on_btnDeleteROI_clicked\0"
    "on_btnAddROI_2_clicked\0on_btnDeleteROI_2_clicked\0"
    "on_btnCreateROI_clicked\0"
    "on_btnDeleteModel_clicked\0"
    "on_btnRoiColor_clicked\0"
    "on_comboMode_currentIndexChanged\0index\0"
    "on_comboViewMode_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmTemplateMatch[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    1,   90,    2, 0x08 /* Private */,
      15,    1,   93,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void frmTemplateMatch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmTemplateMatch *>(_o);
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
        case 11: _t->on_comboMode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_comboViewMode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmTemplateMatch::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmTemplateMatch.data,
    qt_meta_data_frmTemplateMatch,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmTemplateMatch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmTemplateMatch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmTemplateMatch.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmTemplateMatch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
