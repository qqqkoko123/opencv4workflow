/****************************************************************************
** Meta object code from reading C++ file 'frmClassifier.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmClassifier.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmClassifier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmClassifier_t {
    QByteArrayData data[18];
    char stringdata0[366];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmClassifier_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmClassifier_t qt_meta_stringdata_frmClassifier = {
    {
QT_MOC_LITERAL(0, 0, 13), // "frmClassifier"
QT_MOC_LITERAL(1, 14, 19), // "sig_ClassifierValue"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 7), // "InfoVal"
QT_MOC_LITERAL(4, 43, 17), // "sigShowFullScreen"
QT_MOC_LITERAL(5, 61, 16), // "sigEndFullScreen"
QT_MOC_LITERAL(6, 78, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(7, 99, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(8, 121, 23), // "on_btnLinkImage_clicked"
QT_MOC_LITERAL(9, 145, 26), // "on_btnDelLinkImage_clicked"
QT_MOC_LITERAL(10, 172, 20), // "on_btnLabels_clicked"
QT_MOC_LITERAL(11, 193, 18), // "on_btnList_clicked"
QT_MOC_LITERAL(12, 212, 23), // "on_btnSaveModel_clicked"
QT_MOC_LITERAL(13, 236, 24), // "on_btnTrainModel_clicked"
QT_MOC_LITERAL(14, 261, 23), // "on_btnLoadModel_clicked"
QT_MOC_LITERAL(15, 285, 19), // "on_btnWrite_clicked"
QT_MOC_LITERAL(16, 305, 24), // "slot_CurrentIndexChanged"
QT_MOC_LITERAL(17, 330, 35) // "on_comboTypeBuf_currentIndexC..."

    },
    "frmClassifier\0sig_ClassifierValue\0\0"
    "InfoVal\0sigShowFullScreen\0sigEndFullScreen\0"
    "onButtonCloseClicked\0on_btnExecute_clicked\0"
    "on_btnLinkImage_clicked\0"
    "on_btnDelLinkImage_clicked\0"
    "on_btnLabels_clicked\0on_btnList_clicked\0"
    "on_btnSaveModel_clicked\0"
    "on_btnTrainModel_clicked\0"
    "on_btnLoadModel_clicked\0on_btnWrite_clicked\0"
    "slot_CurrentIndexChanged\0"
    "on_comboTypeBuf_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmClassifier[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    0,   92,    2, 0x06 /* Public */,
       5,    0,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   94,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    1,  104,    2, 0x08 /* Private */,
      17,    1,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
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
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void frmClassifier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmClassifier *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_ClassifierValue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigShowFullScreen(); break;
        case 2: _t->sigEndFullScreen(); break;
        case 3: _t->onButtonCloseClicked(); break;
        case 4: _t->on_btnExecute_clicked(); break;
        case 5: _t->on_btnLinkImage_clicked(); break;
        case 6: _t->on_btnDelLinkImage_clicked(); break;
        case 7: _t->on_btnLabels_clicked(); break;
        case 8: _t->on_btnList_clicked(); break;
        case 9: _t->on_btnSaveModel_clicked(); break;
        case 10: _t->on_btnTrainModel_clicked(); break;
        case 11: _t->on_btnLoadModel_clicked(); break;
        case 12: _t->on_btnWrite_clicked(); break;
        case 13: _t->slot_CurrentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_comboTypeBuf_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmClassifier::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmClassifier::sig_ClassifierValue)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmClassifier::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmClassifier::sigShowFullScreen)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (frmClassifier::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmClassifier::sigEndFullScreen)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmClassifier::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmClassifier.data,
    qt_meta_data_frmClassifier,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmClassifier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmClassifier::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmClassifier.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmClassifier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void frmClassifier::sig_ClassifierValue(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void frmClassifier::sigShowFullScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void frmClassifier::sigEndFullScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
