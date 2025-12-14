/****************************************************************************
** Meta object code from reading C++ file 'frmImageSource.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../frmImageSource.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmImageSource.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmImageSource_t {
    QByteArrayData data[20];
    char stringdata0[417];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmImageSource_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmImageSource_t qt_meta_stringdata_frmImageSource = {
    {
QT_MOC_LITERAL(0, 0, 14), // "frmImageSource"
QT_MOC_LITERAL(1, 15, 11), // "sig_Message"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "sig_PathMessage"
QT_MOC_LITERAL(4, 44, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(5, 65, 25), // "on_btnSelectImage_clicked"
QT_MOC_LITERAL(6, 91, 24), // "on_btnSelectPath_clicked"
QT_MOC_LITERAL(7, 116, 29), // "on_btnSelectCalibPath_clicked"
QT_MOC_LITERAL(8, 146, 30), // "on_btnLinkCameraMatrix_clicked"
QT_MOC_LITERAL(9, 177, 33), // "on_btnDelLinkCameraMatrix_cli..."
QT_MOC_LITERAL(10, 211, 28), // "on_btnLinkDistCoeffs_clicked"
QT_MOC_LITERAL(11, 240, 31), // "on_btnDelLinkDistCoeffs_clicked"
QT_MOC_LITERAL(12, 272, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(13, 294, 20), // "on_btnUpdata_clicked"
QT_MOC_LITERAL(14, 315, 34), // "on_comboCamera_currentIndexCh..."
QT_MOC_LITERAL(15, 350, 5), // "index"
QT_MOC_LITERAL(16, 356, 12), // "onRadioClick"
QT_MOC_LITERAL(17, 369, 17), // "onCalibRadioClick"
QT_MOC_LITERAL(18, 387, 12), // "slot_Message"
QT_MOC_LITERAL(19, 400, 16) // "slot_PathMessage"

    },
    "frmImageSource\0sig_Message\0\0sig_PathMessage\0"
    "onButtonCloseClicked\0on_btnSelectImage_clicked\0"
    "on_btnSelectPath_clicked\0"
    "on_btnSelectCalibPath_clicked\0"
    "on_btnLinkCameraMatrix_clicked\0"
    "on_btnDelLinkCameraMatrix_clicked\0"
    "on_btnLinkDistCoeffs_clicked\0"
    "on_btnDelLinkDistCoeffs_clicked\0"
    "on_btnExecute_clicked\0on_btnUpdata_clicked\0"
    "on_comboCamera_currentIndexChanged\0"
    "index\0onRadioClick\0onCalibRadioClick\0"
    "slot_Message\0slot_PathMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmImageSource[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    1,  111,    2, 0x08 /* Private */,
      16,    1,  114,    2, 0x08 /* Private */,
      17,    1,  117,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmImageSource::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmImageSource *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_Message(); break;
        case 1: _t->sig_PathMessage(); break;
        case 2: _t->onButtonCloseClicked(); break;
        case 3: _t->on_btnSelectImage_clicked(); break;
        case 4: _t->on_btnSelectPath_clicked(); break;
        case 5: _t->on_btnSelectCalibPath_clicked(); break;
        case 6: _t->on_btnLinkCameraMatrix_clicked(); break;
        case 7: _t->on_btnDelLinkCameraMatrix_clicked(); break;
        case 8: _t->on_btnLinkDistCoeffs_clicked(); break;
        case 9: _t->on_btnDelLinkDistCoeffs_clicked(); break;
        case 10: _t->on_btnExecute_clicked(); break;
        case 11: _t->on_btnUpdata_clicked(); break;
        case 12: _t->on_comboCamera_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->onRadioClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->onCalibRadioClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->slot_Message(); break;
        case 16: _t->slot_PathMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmImageSource::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageSource::sig_Message)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmImageSource::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmImageSource::sig_PathMessage)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmImageSource::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface2::staticMetaObject>(),
    qt_meta_stringdata_frmImageSource.data,
    qt_meta_data_frmImageSource,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmImageSource::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmImageSource::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmImageSource.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface2::qt_metacast(_clname);
}

int frmImageSource::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface2::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void frmImageSource::sig_Message()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void frmImageSource::sig_PathMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
