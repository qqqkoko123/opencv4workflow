/****************************************************************************
** Meta object code from reading C++ file 'frmProcessSetUp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmProcessSetUp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmProcessSetUp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmProcessSetUp_t {
    QByteArrayData data[11];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmProcessSetUp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmProcessSetUp_t qt_meta_stringdata_frmProcessSetUp = {
    {
QT_MOC_LITERAL(0, 0, 15), // "frmProcessSetUp"
QT_MOC_LITERAL(1, 16, 21), // "sig_UpdateQTreeWidget"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 15), // "slot_CreateList"
QT_MOC_LITERAL(4, 55, 15), // "slot_SetProject"
QT_MOC_LITERAL(5, 71, 8), // "str_name"
QT_MOC_LITERAL(6, 80, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(7, 101, 14), // "slot_ListClick"
QT_MOC_LITERAL(8, 116, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 128, 27), // "on_btnProjectModify_clicked"
QT_MOC_LITERAL(10, 156, 27) // "on_btnProcessModify_clicked"

    },
    "frmProcessSetUp\0sig_UpdateQTreeWidget\0"
    "\0slot_CreateList\0slot_SetProject\0"
    "str_name\0onButtonCloseClicked\0"
    "slot_ListClick\0QModelIndex\0"
    "on_btnProjectModify_clicked\0"
    "on_btnProcessModify_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmProcessSetUp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   54,    2, 0x0a /* Public */,
       4,    1,   55,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    1,   59,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmProcessSetUp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmProcessSetUp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_UpdateQTreeWidget((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->slot_CreateList(); break;
        case 2: _t->slot_SetProject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->onButtonCloseClicked(); break;
        case 4: _t->slot_ListClick((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_btnProjectModify_clicked(); break;
        case 6: _t->on_btnProcessModify_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmProcessSetUp::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmProcessSetUp::sig_UpdateQTreeWidget)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmProcessSetUp::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_frmProcessSetUp.data,
    qt_meta_data_frmProcessSetUp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmProcessSetUp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmProcessSetUp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmProcessSetUp.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int frmProcessSetUp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void frmProcessSetUp::sig_UpdateQTreeWidget(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
