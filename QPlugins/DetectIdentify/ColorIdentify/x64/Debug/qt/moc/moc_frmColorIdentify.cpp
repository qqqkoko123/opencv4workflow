/****************************************************************************
** Meta object code from reading C++ file 'frmColorIdentify.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmColorIdentify.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmColorIdentify.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmColorIdentify_t {
    QByteArrayData data[16];
    char stringdata0[300];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmColorIdentify_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmColorIdentify_t qt_meta_stringdata_frmColorIdentify = {
    {
QT_MOC_LITERAL(0, 0, 16), // "frmColorIdentify"
QT_MOC_LITERAL(1, 17, 14), // "sig_ScoreValue"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "InfoVal"
QT_MOC_LITERAL(4, 41, 11), // "sig_Message"
QT_MOC_LITERAL(5, 53, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(6, 74, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(7, 96, 23), // "on_btnLinkImage_clicked"
QT_MOC_LITERAL(8, 120, 26), // "on_btnDelLinkImage_clicked"
QT_MOC_LITERAL(9, 147, 24), // "on_btnLinkFollow_clicked"
QT_MOC_LITERAL(10, 172, 27), // "on_btnDelLinkFollow_clicked"
QT_MOC_LITERAL(11, 200, 20), // "on_btnAddROI_clicked"
QT_MOC_LITERAL(12, 221, 23), // "on_btnDeleteROI_clicked"
QT_MOC_LITERAL(13, 245, 22), // "on_btnRoiColor_clicked"
QT_MOC_LITERAL(14, 268, 12), // "slot_Message"
QT_MOC_LITERAL(15, 281, 18) // "slot_StandardImage"

    },
    "frmColorIdentify\0sig_ScoreValue\0\0"
    "InfoVal\0sig_Message\0onButtonCloseClicked\0"
    "on_btnExecute_clicked\0on_btnLinkImage_clicked\0"
    "on_btnDelLinkImage_clicked\0"
    "on_btnLinkFollow_clicked\0"
    "on_btnDelLinkFollow_clicked\0"
    "on_btnAddROI_clicked\0on_btnDeleteROI_clicked\0"
    "on_btnRoiColor_clicked\0slot_Message\0"
    "slot_StandardImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmColorIdentify[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    0,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   83,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

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

       0        // eod
};

void frmColorIdentify::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmColorIdentify *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_ScoreValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sig_Message(); break;
        case 2: _t->onButtonCloseClicked(); break;
        case 3: _t->on_btnExecute_clicked(); break;
        case 4: _t->on_btnLinkImage_clicked(); break;
        case 5: _t->on_btnDelLinkImage_clicked(); break;
        case 6: _t->on_btnLinkFollow_clicked(); break;
        case 7: _t->on_btnDelLinkFollow_clicked(); break;
        case 8: _t->on_btnAddROI_clicked(); break;
        case 9: _t->on_btnDeleteROI_clicked(); break;
        case 10: _t->on_btnRoiColor_clicked(); break;
        case 11: _t->slot_Message(); break;
        case 12: _t->slot_StandardImage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmColorIdentify::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmColorIdentify::sig_ScoreValue)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmColorIdentify::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmColorIdentify::sig_Message)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmColorIdentify::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmColorIdentify.data,
    qt_meta_data_frmColorIdentify,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmColorIdentify::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmColorIdentify::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmColorIdentify.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmColorIdentify::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void frmColorIdentify::sig_ScoreValue(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void frmColorIdentify::sig_Message()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
