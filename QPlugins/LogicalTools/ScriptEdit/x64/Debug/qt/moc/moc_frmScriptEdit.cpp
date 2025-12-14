/****************************************************************************
** Meta object code from reading C++ file 'frmScriptEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmScriptEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmScriptEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmScriptEdit_t {
    QByteArrayData data[22];
    char stringdata0[321];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmScriptEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmScriptEdit_t qt_meta_stringdata_frmScriptEdit = {
    {
QT_MOC_LITERAL(0, 0, 13), // "frmScriptEdit"
QT_MOC_LITERAL(1, 14, 21), // "sig_UpdateQTreeWidget"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 15), // "sig_ScriptError"
QT_MOC_LITERAL(4, 53, 14), // "QScriptEngine*"
QT_MOC_LITERAL(5, 68, 13), // "script_engine"
QT_MOC_LITERAL(6, 82, 8), // "str_code"
QT_MOC_LITERAL(7, 91, 12), // "QScriptValue"
QT_MOC_LITERAL(8, 104, 6), // "result"
QT_MOC_LITERAL(9, 111, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(10, 132, 21), // "on_btnCompile_clicked"
QT_MOC_LITERAL(11, 154, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(12, 176, 22), // "slot_ItemDoubleClicked"
QT_MOC_LITERAL(13, 199, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(14, 216, 4), // "item"
QT_MOC_LITERAL(15, 221, 6), // "column"
QT_MOC_LITERAL(16, 228, 15), // "slot_CreateList"
QT_MOC_LITERAL(17, 244, 14), // "slot_ListClick"
QT_MOC_LITERAL(18, 259, 11), // "QModelIndex"
QT_MOC_LITERAL(19, 271, 18), // "slot_DoubleClicked"
QT_MOC_LITERAL(20, 290, 13), // "slot_Accepted"
QT_MOC_LITERAL(21, 304, 16) // "slot_ScriptError"

    },
    "frmScriptEdit\0sig_UpdateQTreeWidget\0"
    "\0sig_ScriptError\0QScriptEngine*\0"
    "script_engine\0str_code\0QScriptValue\0"
    "result\0onButtonCloseClicked\0"
    "on_btnCompile_clicked\0on_btnExecute_clicked\0"
    "slot_ItemDoubleClicked\0QTreeWidgetItem*\0"
    "item\0column\0slot_CreateList\0slot_ListClick\0"
    "QModelIndex\0slot_DoubleClicked\0"
    "slot_Accepted\0slot_ScriptError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmScriptEdit[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       3,    3,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    2,   84,    2, 0x08 /* Private */,
      16,    0,   89,    2, 0x08 /* Private */,
      17,    1,   90,    2, 0x08 /* Private */,
      19,    2,   93,    2, 0x08 /* Private */,
      20,    0,   98,    2, 0x08 /* Private */,
      21,    3,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString, 0x80000000 | 7,    5,    6,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   15,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString, 0x80000000 | 7,    5,    6,    8,

       0        // eod
};

void frmScriptEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmScriptEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_UpdateQTreeWidget((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sig_ScriptError((*reinterpret_cast< QScriptEngine*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QScriptValue(*)>(_a[3]))); break;
        case 2: _t->onButtonCloseClicked(); break;
        case 3: _t->on_btnCompile_clicked(); break;
        case 4: _t->on_btnExecute_clicked(); break;
        case 5: _t->slot_ItemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->slot_CreateList(); break;
        case 7: _t->slot_ListClick((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 8: _t->slot_DoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->slot_Accepted(); break;
        case 10: _t->slot_ScriptError((*reinterpret_cast< QScriptEngine*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QScriptValue(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QScriptEngine* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QScriptEngine* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmScriptEdit::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmScriptEdit::sig_UpdateQTreeWidget)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmScriptEdit::*)(QScriptEngine * , QString , QScriptValue );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmScriptEdit::sig_ScriptError)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmScriptEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmScriptEdit.data,
    qt_meta_data_frmScriptEdit,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmScriptEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmScriptEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmScriptEdit.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmScriptEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void frmScriptEdit::sig_UpdateQTreeWidget(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void frmScriptEdit::sig_ScriptError(QScriptEngine * _t1, QString _t2, QScriptValue _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_IconHelpers_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IconHelpers_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IconHelpers_t qt_meta_stringdata_IconHelpers = {
    {
QT_MOC_LITERAL(0, 0, 11) // "IconHelpers"

    },
    "IconHelpers"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IconHelpers[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void IconHelpers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject IconHelpers::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_IconHelpers.data,
    qt_meta_data_IconHelpers,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IconHelpers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IconHelpers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IconHelpers.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IconHelpers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
