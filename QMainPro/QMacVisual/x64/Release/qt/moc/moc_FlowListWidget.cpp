/****************************************************************************
** Meta object code from reading C++ file 'FlowListWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../FlowListWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FlowListWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DragListWidgetPrivate_t {
    QByteArrayData data[14];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DragListWidgetPrivate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DragListWidgetPrivate_t qt_meta_stringdata_DragListWidgetPrivate = {
    {
QT_MOC_LITERAL(0, 0, 21), // "DragListWidgetPrivate"
QT_MOC_LITERAL(1, 22, 17), // "signalItemClicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 5), // "index"
QT_MOC_LITERAL(4, 47, 17), // "sig_ActionProItem"
QT_MOC_LITERAL(5, 65, 15), // "sig_DActivation"
QT_MOC_LITERAL(6, 81, 17), // "SltDragPressCheck"
QT_MOC_LITERAL(7, 99, 14), // "slot_IconCheck"
QT_MOC_LITERAL(8, 114, 12), // "slot_Current"
QT_MOC_LITERAL(9, 127, 13), // "slot_Previous"
QT_MOC_LITERAL(10, 141, 9), // "slot_Next"
QT_MOC_LITERAL(11, 151, 16), // "slot_DActivation"
QT_MOC_LITERAL(12, 168, 23), // "slot_DisabledActivation"
QT_MOC_LITERAL(13, 192, 11) // "slot_Delete"

    },
    "DragListWidgetPrivate\0signalItemClicked\0"
    "\0index\0sig_ActionProItem\0sig_DActivation\0"
    "SltDragPressCheck\0slot_IconCheck\0"
    "slot_Current\0slot_Previous\0slot_Next\0"
    "slot_DActivation\0slot_DisabledActivation\0"
    "slot_Delete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DragListWidgetPrivate[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    3,   72,    2, 0x06 /* Public */,
       5,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   82,    2, 0x08 /* Private */,
       7,    0,   83,    2, 0x08 /* Private */,
       8,    0,   84,    2, 0x08 /* Private */,
       9,    0,   85,    2, 0x08 /* Private */,
      10,    0,   86,    2, 0x08 /* Private */,
      11,    0,   87,    2, 0x08 /* Private */,
      12,    1,   88,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void DragListWidgetPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DragListWidgetPrivate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalItemClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sig_ActionProItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->sig_DActivation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->SltDragPressCheck(); break;
        case 4: _t->slot_IconCheck(); break;
        case 5: _t->slot_Current(); break;
        case 6: _t->slot_Previous(); break;
        case 7: _t->slot_Next(); break;
        case 8: _t->slot_DActivation(); break;
        case 9: _t->slot_DisabledActivation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->slot_Delete(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DragListWidgetPrivate::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DragListWidgetPrivate::signalItemClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DragListWidgetPrivate::*)(int , QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DragListWidgetPrivate::sig_ActionProItem)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DragListWidgetPrivate::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DragListWidgetPrivate::sig_DActivation)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DragListWidgetPrivate::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DragListWidgetPrivate.data,
    qt_meta_data_DragListWidgetPrivate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DragListWidgetPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DragListWidgetPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DragListWidgetPrivate.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DragListWidgetPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void DragListWidgetPrivate::signalItemClicked(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DragListWidgetPrivate::sig_ActionProItem(int _t1, QString _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DragListWidgetPrivate::sig_DActivation(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_QtDragListWidget_t {
    QByteArrayData data[89];
    char stringdata0[1707];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtDragListWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtDragListWidget_t qt_meta_stringdata_QtDragListWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QtDragListWidget"
QT_MOC_LITERAL(1, 17, 17), // "signalItemClicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "index"
QT_MOC_LITERAL(4, 42, 17), // "sig_ActionProItem"
QT_MOC_LITERAL(5, 60, 18), // "sig_ItemSubText_B1"
QT_MOC_LITERAL(6, 79, 8), // "itemName"
QT_MOC_LITERAL(7, 88, 11), // "subTitleStr"
QT_MOC_LITERAL(8, 100, 18), // "sig_ItemSubText_B2"
QT_MOC_LITERAL(9, 119, 18), // "sig_ItemSubText_B3"
QT_MOC_LITERAL(10, 138, 18), // "sig_ItemSubText_B4"
QT_MOC_LITERAL(11, 157, 18), // "sig_ItemSubText_B5"
QT_MOC_LITERAL(12, 176, 18), // "sig_ItemSubText_B6"
QT_MOC_LITERAL(13, 195, 18), // "sig_ItemSubText_B7"
QT_MOC_LITERAL(14, 214, 18), // "sig_ItemSubText_B8"
QT_MOC_LITERAL(15, 233, 18), // "sig_ItemSubText_B9"
QT_MOC_LITERAL(16, 252, 19), // "sig_ItemSubText_B10"
QT_MOC_LITERAL(17, 272, 19), // "sig_ItemSubText_B11"
QT_MOC_LITERAL(18, 292, 19), // "sig_ItemSubText_B12"
QT_MOC_LITERAL(19, 312, 19), // "sig_ItemSubText_B13"
QT_MOC_LITERAL(20, 332, 19), // "sig_ItemSubText_B14"
QT_MOC_LITERAL(21, 352, 19), // "sig_ItemSubText_B15"
QT_MOC_LITERAL(22, 372, 19), // "sig_ItemSubText_B16"
QT_MOC_LITERAL(23, 392, 19), // "sig_ItemSubText_B17"
QT_MOC_LITERAL(24, 412, 19), // "sig_ItemSubText_B18"
QT_MOC_LITERAL(25, 432, 19), // "sig_ItemSubText_B19"
QT_MOC_LITERAL(26, 452, 19), // "sig_ItemSubText_B20"
QT_MOC_LITERAL(27, 472, 18), // "sig_ItemSubIcon_B1"
QT_MOC_LITERAL(28, 491, 2), // "pm"
QT_MOC_LITERAL(29, 494, 18), // "sig_ItemSubIcon_B2"
QT_MOC_LITERAL(30, 513, 18), // "sig_ItemSubIcon_B3"
QT_MOC_LITERAL(31, 532, 18), // "sig_ItemSubIcon_B4"
QT_MOC_LITERAL(32, 551, 18), // "sig_ItemSubIcon_B5"
QT_MOC_LITERAL(33, 570, 18), // "sig_ItemSubIcon_B6"
QT_MOC_LITERAL(34, 589, 18), // "sig_ItemSubIcon_B7"
QT_MOC_LITERAL(35, 608, 18), // "sig_ItemSubIcon_B8"
QT_MOC_LITERAL(36, 627, 18), // "sig_ItemSubIcon_B9"
QT_MOC_LITERAL(37, 646, 19), // "sig_ItemSubIcon_B10"
QT_MOC_LITERAL(38, 666, 19), // "sig_ItemSubIcon_B11"
QT_MOC_LITERAL(39, 686, 19), // "sig_ItemSubIcon_B12"
QT_MOC_LITERAL(40, 706, 19), // "sig_ItemSubIcon_B13"
QT_MOC_LITERAL(41, 726, 19), // "sig_ItemSubIcon_B14"
QT_MOC_LITERAL(42, 746, 19), // "sig_ItemSubIcon_B15"
QT_MOC_LITERAL(43, 766, 19), // "sig_ItemSubIcon_B16"
QT_MOC_LITERAL(44, 786, 19), // "sig_ItemSubIcon_B17"
QT_MOC_LITERAL(45, 806, 19), // "sig_ItemSubIcon_B18"
QT_MOC_LITERAL(46, 826, 19), // "sig_ItemSubIcon_B19"
QT_MOC_LITERAL(47, 846, 19), // "sig_ItemSubIcon_B20"
QT_MOC_LITERAL(48, 866, 19), // "slot_ItemSubText_B1"
QT_MOC_LITERAL(49, 886, 19), // "slot_ItemSubText_B2"
QT_MOC_LITERAL(50, 906, 19), // "slot_ItemSubText_B3"
QT_MOC_LITERAL(51, 926, 19), // "slot_ItemSubText_B4"
QT_MOC_LITERAL(52, 946, 19), // "slot_ItemSubText_B5"
QT_MOC_LITERAL(53, 966, 19), // "slot_ItemSubText_B6"
QT_MOC_LITERAL(54, 986, 19), // "slot_ItemSubText_B7"
QT_MOC_LITERAL(55, 1006, 19), // "slot_ItemSubText_B8"
QT_MOC_LITERAL(56, 1026, 19), // "slot_ItemSubText_B9"
QT_MOC_LITERAL(57, 1046, 20), // "slot_ItemSubText_B10"
QT_MOC_LITERAL(58, 1067, 20), // "slot_ItemSubText_B11"
QT_MOC_LITERAL(59, 1088, 20), // "slot_ItemSubText_B12"
QT_MOC_LITERAL(60, 1109, 20), // "slot_ItemSubText_B13"
QT_MOC_LITERAL(61, 1130, 20), // "slot_ItemSubText_B14"
QT_MOC_LITERAL(62, 1151, 20), // "slot_ItemSubText_B15"
QT_MOC_LITERAL(63, 1172, 20), // "slot_ItemSubText_B16"
QT_MOC_LITERAL(64, 1193, 20), // "slot_ItemSubText_B17"
QT_MOC_LITERAL(65, 1214, 20), // "slot_ItemSubText_B18"
QT_MOC_LITERAL(66, 1235, 20), // "slot_ItemSubText_B19"
QT_MOC_LITERAL(67, 1256, 20), // "slot_ItemSubText_B20"
QT_MOC_LITERAL(68, 1277, 19), // "slot_ItemSubIcon_B1"
QT_MOC_LITERAL(69, 1297, 19), // "slot_ItemSubIcon_B2"
QT_MOC_LITERAL(70, 1317, 19), // "slot_ItemSubIcon_B3"
QT_MOC_LITERAL(71, 1337, 19), // "slot_ItemSubIcon_B4"
QT_MOC_LITERAL(72, 1357, 19), // "slot_ItemSubIcon_B5"
QT_MOC_LITERAL(73, 1377, 19), // "slot_ItemSubIcon_B6"
QT_MOC_LITERAL(74, 1397, 19), // "slot_ItemSubIcon_B7"
QT_MOC_LITERAL(75, 1417, 19), // "slot_ItemSubIcon_B8"
QT_MOC_LITERAL(76, 1437, 19), // "slot_ItemSubIcon_B9"
QT_MOC_LITERAL(77, 1457, 20), // "slot_ItemSubIcon_B10"
QT_MOC_LITERAL(78, 1478, 20), // "slot_ItemSubIcon_B11"
QT_MOC_LITERAL(79, 1499, 20), // "slot_ItemSubIcon_B12"
QT_MOC_LITERAL(80, 1520, 20), // "slot_ItemSubIcon_B13"
QT_MOC_LITERAL(81, 1541, 20), // "slot_ItemSubIcon_B14"
QT_MOC_LITERAL(82, 1562, 20), // "slot_ItemSubIcon_B15"
QT_MOC_LITERAL(83, 1583, 20), // "slot_ItemSubIcon_B16"
QT_MOC_LITERAL(84, 1604, 20), // "slot_ItemSubIcon_B17"
QT_MOC_LITERAL(85, 1625, 20), // "slot_ItemSubIcon_B18"
QT_MOC_LITERAL(86, 1646, 20), // "slot_ItemSubIcon_B19"
QT_MOC_LITERAL(87, 1667, 20), // "slot_ItemSubIcon_B20"
QT_MOC_LITERAL(88, 1688, 18) // "slot_ActionProItem"

    },
    "QtDragListWidget\0signalItemClicked\0\0"
    "index\0sig_ActionProItem\0sig_ItemSubText_B1\0"
    "itemName\0subTitleStr\0sig_ItemSubText_B2\0"
    "sig_ItemSubText_B3\0sig_ItemSubText_B4\0"
    "sig_ItemSubText_B5\0sig_ItemSubText_B6\0"
    "sig_ItemSubText_B7\0sig_ItemSubText_B8\0"
    "sig_ItemSubText_B9\0sig_ItemSubText_B10\0"
    "sig_ItemSubText_B11\0sig_ItemSubText_B12\0"
    "sig_ItemSubText_B13\0sig_ItemSubText_B14\0"
    "sig_ItemSubText_B15\0sig_ItemSubText_B16\0"
    "sig_ItemSubText_B17\0sig_ItemSubText_B18\0"
    "sig_ItemSubText_B19\0sig_ItemSubText_B20\0"
    "sig_ItemSubIcon_B1\0pm\0sig_ItemSubIcon_B2\0"
    "sig_ItemSubIcon_B3\0sig_ItemSubIcon_B4\0"
    "sig_ItemSubIcon_B5\0sig_ItemSubIcon_B6\0"
    "sig_ItemSubIcon_B7\0sig_ItemSubIcon_B8\0"
    "sig_ItemSubIcon_B9\0sig_ItemSubIcon_B10\0"
    "sig_ItemSubIcon_B11\0sig_ItemSubIcon_B12\0"
    "sig_ItemSubIcon_B13\0sig_ItemSubIcon_B14\0"
    "sig_ItemSubIcon_B15\0sig_ItemSubIcon_B16\0"
    "sig_ItemSubIcon_B17\0sig_ItemSubIcon_B18\0"
    "sig_ItemSubIcon_B19\0sig_ItemSubIcon_B20\0"
    "slot_ItemSubText_B1\0slot_ItemSubText_B2\0"
    "slot_ItemSubText_B3\0slot_ItemSubText_B4\0"
    "slot_ItemSubText_B5\0slot_ItemSubText_B6\0"
    "slot_ItemSubText_B7\0slot_ItemSubText_B8\0"
    "slot_ItemSubText_B9\0slot_ItemSubText_B10\0"
    "slot_ItemSubText_B11\0slot_ItemSubText_B12\0"
    "slot_ItemSubText_B13\0slot_ItemSubText_B14\0"
    "slot_ItemSubText_B15\0slot_ItemSubText_B16\0"
    "slot_ItemSubText_B17\0slot_ItemSubText_B18\0"
    "slot_ItemSubText_B19\0slot_ItemSubText_B20\0"
    "slot_ItemSubIcon_B1\0slot_ItemSubIcon_B2\0"
    "slot_ItemSubIcon_B3\0slot_ItemSubIcon_B4\0"
    "slot_ItemSubIcon_B5\0slot_ItemSubIcon_B6\0"
    "slot_ItemSubIcon_B7\0slot_ItemSubIcon_B8\0"
    "slot_ItemSubIcon_B9\0slot_ItemSubIcon_B10\0"
    "slot_ItemSubIcon_B11\0slot_ItemSubIcon_B12\0"
    "slot_ItemSubIcon_B13\0slot_ItemSubIcon_B14\0"
    "slot_ItemSubIcon_B15\0slot_ItemSubIcon_B16\0"
    "slot_ItemSubIcon_B17\0slot_ItemSubIcon_B18\0"
    "slot_ItemSubIcon_B19\0slot_ItemSubIcon_B20\0"
    "slot_ActionProItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtDragListWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      83,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      42,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  429,    2, 0x06 /* Public */,
       4,    3,  432,    2, 0x06 /* Public */,
       5,    2,  439,    2, 0x06 /* Public */,
       8,    2,  444,    2, 0x06 /* Public */,
       9,    2,  449,    2, 0x06 /* Public */,
      10,    2,  454,    2, 0x06 /* Public */,
      11,    2,  459,    2, 0x06 /* Public */,
      12,    2,  464,    2, 0x06 /* Public */,
      13,    2,  469,    2, 0x06 /* Public */,
      14,    2,  474,    2, 0x06 /* Public */,
      15,    2,  479,    2, 0x06 /* Public */,
      16,    2,  484,    2, 0x06 /* Public */,
      17,    2,  489,    2, 0x06 /* Public */,
      18,    2,  494,    2, 0x06 /* Public */,
      19,    2,  499,    2, 0x06 /* Public */,
      20,    2,  504,    2, 0x06 /* Public */,
      21,    2,  509,    2, 0x06 /* Public */,
      22,    2,  514,    2, 0x06 /* Public */,
      23,    2,  519,    2, 0x06 /* Public */,
      24,    2,  524,    2, 0x06 /* Public */,
      25,    2,  529,    2, 0x06 /* Public */,
      26,    2,  534,    2, 0x06 /* Public */,
      27,    2,  539,    2, 0x06 /* Public */,
      29,    2,  544,    2, 0x06 /* Public */,
      30,    2,  549,    2, 0x06 /* Public */,
      31,    2,  554,    2, 0x06 /* Public */,
      32,    2,  559,    2, 0x06 /* Public */,
      33,    2,  564,    2, 0x06 /* Public */,
      34,    2,  569,    2, 0x06 /* Public */,
      35,    2,  574,    2, 0x06 /* Public */,
      36,    2,  579,    2, 0x06 /* Public */,
      37,    2,  584,    2, 0x06 /* Public */,
      38,    2,  589,    2, 0x06 /* Public */,
      39,    2,  594,    2, 0x06 /* Public */,
      40,    2,  599,    2, 0x06 /* Public */,
      41,    2,  604,    2, 0x06 /* Public */,
      42,    2,  609,    2, 0x06 /* Public */,
      43,    2,  614,    2, 0x06 /* Public */,
      44,    2,  619,    2, 0x06 /* Public */,
      45,    2,  624,    2, 0x06 /* Public */,
      46,    2,  629,    2, 0x06 /* Public */,
      47,    2,  634,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      48,    2,  639,    2, 0x08 /* Private */,
      49,    2,  644,    2, 0x08 /* Private */,
      50,    2,  649,    2, 0x08 /* Private */,
      51,    2,  654,    2, 0x08 /* Private */,
      52,    2,  659,    2, 0x08 /* Private */,
      53,    2,  664,    2, 0x08 /* Private */,
      54,    2,  669,    2, 0x08 /* Private */,
      55,    2,  674,    2, 0x08 /* Private */,
      56,    2,  679,    2, 0x08 /* Private */,
      57,    2,  684,    2, 0x08 /* Private */,
      58,    2,  689,    2, 0x08 /* Private */,
      59,    2,  694,    2, 0x08 /* Private */,
      60,    2,  699,    2, 0x08 /* Private */,
      61,    2,  704,    2, 0x08 /* Private */,
      62,    2,  709,    2, 0x08 /* Private */,
      63,    2,  714,    2, 0x08 /* Private */,
      64,    2,  719,    2, 0x08 /* Private */,
      65,    2,  724,    2, 0x08 /* Private */,
      66,    2,  729,    2, 0x08 /* Private */,
      67,    2,  734,    2, 0x08 /* Private */,
      68,    2,  739,    2, 0x08 /* Private */,
      69,    2,  744,    2, 0x08 /* Private */,
      70,    2,  749,    2, 0x08 /* Private */,
      71,    2,  754,    2, 0x08 /* Private */,
      72,    2,  759,    2, 0x08 /* Private */,
      73,    2,  764,    2, 0x08 /* Private */,
      74,    2,  769,    2, 0x08 /* Private */,
      75,    2,  774,    2, 0x08 /* Private */,
      76,    2,  779,    2, 0x08 /* Private */,
      77,    2,  784,    2, 0x08 /* Private */,
      78,    2,  789,    2, 0x08 /* Private */,
      79,    2,  794,    2, 0x08 /* Private */,
      80,    2,  799,    2, 0x08 /* Private */,
      81,    2,  804,    2, 0x08 /* Private */,
      82,    2,  809,    2, 0x08 /* Private */,
      83,    2,  814,    2, 0x08 /* Private */,
      84,    2,  819,    2, 0x08 /* Private */,
      85,    2,  824,    2, 0x08 /* Private */,
      86,    2,  829,    2, 0x08 /* Private */,
      87,    2,  834,    2, 0x08 /* Private */,
      88,    3,  839,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    6,   28,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,    2,    2,    2,

       0        // eod
};

void QtDragListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtDragListWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalItemClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sig_ActionProItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->sig_ItemSubText_B1((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->sig_ItemSubText_B2((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->sig_ItemSubText_B3((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->sig_ItemSubText_B4((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->sig_ItemSubText_B5((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->sig_ItemSubText_B6((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->sig_ItemSubText_B7((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->sig_ItemSubText_B8((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 10: _t->sig_ItemSubText_B9((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->sig_ItemSubText_B10((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 12: _t->sig_ItemSubText_B11((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 13: _t->sig_ItemSubText_B12((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 14: _t->sig_ItemSubText_B13((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 15: _t->sig_ItemSubText_B14((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 16: _t->sig_ItemSubText_B15((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 17: _t->sig_ItemSubText_B16((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 18: _t->sig_ItemSubText_B17((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 19: _t->sig_ItemSubText_B18((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 20: _t->sig_ItemSubText_B19((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 21: _t->sig_ItemSubText_B20((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 22: _t->sig_ItemSubIcon_B1((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 23: _t->sig_ItemSubIcon_B2((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 24: _t->sig_ItemSubIcon_B3((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 25: _t->sig_ItemSubIcon_B4((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 26: _t->sig_ItemSubIcon_B5((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 27: _t->sig_ItemSubIcon_B6((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 28: _t->sig_ItemSubIcon_B7((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 29: _t->sig_ItemSubIcon_B8((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 30: _t->sig_ItemSubIcon_B9((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 31: _t->sig_ItemSubIcon_B10((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 32: _t->sig_ItemSubIcon_B11((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 33: _t->sig_ItemSubIcon_B12((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 34: _t->sig_ItemSubIcon_B13((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 35: _t->sig_ItemSubIcon_B14((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 36: _t->sig_ItemSubIcon_B15((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 37: _t->sig_ItemSubIcon_B16((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 38: _t->sig_ItemSubIcon_B17((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 39: _t->sig_ItemSubIcon_B18((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 40: _t->sig_ItemSubIcon_B19((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 41: _t->sig_ItemSubIcon_B20((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 42: _t->slot_ItemSubText_B1((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 43: _t->slot_ItemSubText_B2((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 44: _t->slot_ItemSubText_B3((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 45: _t->slot_ItemSubText_B4((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 46: _t->slot_ItemSubText_B5((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 47: _t->slot_ItemSubText_B6((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 48: _t->slot_ItemSubText_B7((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 49: _t->slot_ItemSubText_B8((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 50: _t->slot_ItemSubText_B9((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 51: _t->slot_ItemSubText_B10((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 52: _t->slot_ItemSubText_B11((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 53: _t->slot_ItemSubText_B12((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 54: _t->slot_ItemSubText_B13((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 55: _t->slot_ItemSubText_B14((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 56: _t->slot_ItemSubText_B15((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 57: _t->slot_ItemSubText_B16((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 58: _t->slot_ItemSubText_B17((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 59: _t->slot_ItemSubText_B18((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 60: _t->slot_ItemSubText_B19((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 61: _t->slot_ItemSubText_B20((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 62: _t->slot_ItemSubIcon_B1((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 63: _t->slot_ItemSubIcon_B2((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 64: _t->slot_ItemSubIcon_B3((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 65: _t->slot_ItemSubIcon_B4((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 66: _t->slot_ItemSubIcon_B5((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 67: _t->slot_ItemSubIcon_B6((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 68: _t->slot_ItemSubIcon_B7((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 69: _t->slot_ItemSubIcon_B8((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 70: _t->slot_ItemSubIcon_B9((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 71: _t->slot_ItemSubIcon_B10((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 72: _t->slot_ItemSubIcon_B11((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 73: _t->slot_ItemSubIcon_B12((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 74: _t->slot_ItemSubIcon_B13((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 75: _t->slot_ItemSubIcon_B14((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 76: _t->slot_ItemSubIcon_B15((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 77: _t->slot_ItemSubIcon_B16((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 78: _t->slot_ItemSubIcon_B17((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 79: _t->slot_ItemSubIcon_B18((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 80: _t->slot_ItemSubIcon_B19((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 81: _t->slot_ItemSubIcon_B20((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 82: _t->slot_ActionProItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtDragListWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::signalItemClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(int , QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ActionProItem)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B1)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B2)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B3)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B4)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B5)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B6)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B7)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B8)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B9)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B10)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B11)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B12)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B13)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B14)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B15)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B16)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B17)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B18)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B19)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubText_B20)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B1)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B2)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B3)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B4)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B5)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B6)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B7)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B8)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B9)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B10)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B11)) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B12)) {
                *result = 33;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B13)) {
                *result = 34;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B14)) {
                *result = 35;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B15)) {
                *result = 36;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B16)) {
                *result = 37;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B17)) {
                *result = 38;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B18)) {
                *result = 39;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B19)) {
                *result = 40;
                return;
            }
        }
        {
            using _t = void (QtDragListWidget::*)(const QString , const QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtDragListWidget::sig_ItemSubIcon_B20)) {
                *result = 41;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtDragListWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QtDragListWidget.data,
    qt_meta_data_QtDragListWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtDragListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtDragListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtDragListWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QtDragListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 83)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 83;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 83)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 83;
    }
    return _id;
}

// SIGNAL 0
void QtDragListWidget::signalItemClicked(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtDragListWidget::sig_ActionProItem(int _t1, QString _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtDragListWidget::sig_ItemSubText_B1(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QtDragListWidget::sig_ItemSubText_B2(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QtDragListWidget::sig_ItemSubText_B3(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QtDragListWidget::sig_ItemSubText_B4(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QtDragListWidget::sig_ItemSubText_B5(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QtDragListWidget::sig_ItemSubText_B6(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QtDragListWidget::sig_ItemSubText_B7(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QtDragListWidget::sig_ItemSubText_B8(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void QtDragListWidget::sig_ItemSubText_B9(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void QtDragListWidget::sig_ItemSubText_B10(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void QtDragListWidget::sig_ItemSubText_B11(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void QtDragListWidget::sig_ItemSubText_B12(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void QtDragListWidget::sig_ItemSubText_B13(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void QtDragListWidget::sig_ItemSubText_B14(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void QtDragListWidget::sig_ItemSubText_B15(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void QtDragListWidget::sig_ItemSubText_B16(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void QtDragListWidget::sig_ItemSubText_B17(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void QtDragListWidget::sig_ItemSubText_B18(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void QtDragListWidget::sig_ItemSubText_B19(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void QtDragListWidget::sig_ItemSubText_B20(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void QtDragListWidget::sig_ItemSubIcon_B1(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void QtDragListWidget::sig_ItemSubIcon_B2(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void QtDragListWidget::sig_ItemSubIcon_B3(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void QtDragListWidget::sig_ItemSubIcon_B4(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void QtDragListWidget::sig_ItemSubIcon_B5(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void QtDragListWidget::sig_ItemSubIcon_B6(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void QtDragListWidget::sig_ItemSubIcon_B7(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void QtDragListWidget::sig_ItemSubIcon_B8(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void QtDragListWidget::sig_ItemSubIcon_B9(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void QtDragListWidget::sig_ItemSubIcon_B10(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void QtDragListWidget::sig_ItemSubIcon_B11(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void QtDragListWidget::sig_ItemSubIcon_B12(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void QtDragListWidget::sig_ItemSubIcon_B13(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void QtDragListWidget::sig_ItemSubIcon_B14(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 36
void QtDragListWidget::sig_ItemSubIcon_B15(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}

// SIGNAL 37
void QtDragListWidget::sig_ItemSubIcon_B16(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 37, _a);
}

// SIGNAL 38
void QtDragListWidget::sig_ItemSubIcon_B17(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 38, _a);
}

// SIGNAL 39
void QtDragListWidget::sig_ItemSubIcon_B18(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 39, _a);
}

// SIGNAL 40
void QtDragListWidget::sig_ItemSubIcon_B19(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 40, _a);
}

// SIGNAL 41
void QtDragListWidget::sig_ItemSubIcon_B20(const QString _t1, const QPixmap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 41, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
