/****************************************************************************
** Meta object code from reading C++ file 'frmBlobDetector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmBlobDetector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmBlobDetector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmBlobDetector_t {
    QByteArrayData data[11];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmBlobDetector_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmBlobDetector_t qt_meta_stringdata_frmBlobDetector = {
    {
QT_MOC_LITERAL(0, 0, 15), // "frmBlobDetector"
QT_MOC_LITERAL(1, 16, 13), // "sig_BlobValue"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "InfoVal"
QT_MOC_LITERAL(4, 39, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(5, 60, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(6, 82, 23), // "on_btnLinkImage_clicked"
QT_MOC_LITERAL(7, 106, 26), // "on_btnDelLinkImage_clicked"
QT_MOC_LITERAL(8, 133, 20), // "on_btnAddROI_clicked"
QT_MOC_LITERAL(9, 154, 23), // "on_btnDeleteROI_clicked"
QT_MOC_LITERAL(10, 178, 22) // "on_btnRoiColor_clicked"

    },
    "frmBlobDetector\0sig_BlobValue\0\0InfoVal\0"
    "onButtonCloseClicked\0on_btnExecute_clicked\0"
    "on_btnLinkImage_clicked\0"
    "on_btnDelLinkImage_clicked\0"
    "on_btnAddROI_clicked\0on_btnDeleteROI_clicked\0"
    "on_btnRoiColor_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmBlobDetector[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

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

void frmBlobDetector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmBlobDetector *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_BlobValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->onButtonCloseClicked(); break;
        case 2: _t->on_btnExecute_clicked(); break;
        case 3: _t->on_btnLinkImage_clicked(); break;
        case 4: _t->on_btnDelLinkImage_clicked(); break;
        case 5: _t->on_btnAddROI_clicked(); break;
        case 6: _t->on_btnDeleteROI_clicked(); break;
        case 7: _t->on_btnRoiColor_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmBlobDetector::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmBlobDetector::sig_BlobValue)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmBlobDetector::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmBlobDetector.data,
    qt_meta_data_frmBlobDetector,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmBlobDetector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmBlobDetector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmBlobDetector.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmBlobDetector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void frmBlobDetector::sig_BlobValue(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
