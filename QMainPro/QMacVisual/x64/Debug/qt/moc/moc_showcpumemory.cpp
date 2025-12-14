/****************************************************************************
** Meta object code from reading C++ file 'showcpumemory.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../showcpumemory.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showcpumemory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ShowCpuMemory_t {
    QByteArrayData data[12];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShowCpuMemory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShowCpuMemory_t qt_meta_stringdata_ShowCpuMemory = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ShowCpuMemory"
QT_MOC_LITERAL(1, 14, 12), // "GetCpuMemory"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "calCpuUsage"
QT_MOC_LITERAL(4, 40, 14), // "Filetime2Int64"
QT_MOC_LITERAL(5, 55, 7), // "__int64"
QT_MOC_LITERAL(6, 63, 15), // "const FILETIME*"
QT_MOC_LITERAL(7, 79, 5), // "ftime"
QT_MOC_LITERAL(8, 85, 15), // "CompareFileTime"
QT_MOC_LITERAL(9, 101, 8), // "FILETIME"
QT_MOC_LITERAL(10, 110, 7), // "preTime"
QT_MOC_LITERAL(11, 118, 7) // "nowTime"

    },
    "ShowCpuMemory\0GetCpuMemory\0\0calCpuUsage\0"
    "Filetime2Int64\0__int64\0const FILETIME*\0"
    "ftime\0CompareFileTime\0FILETIME\0preTime\0"
    "nowTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShowCpuMemory[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    1,   36,    2, 0x08 /* Private */,
       8,    2,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Int,
    0x80000000 | 5, 0x80000000 | 6,    7,
    0x80000000 | 5, 0x80000000 | 9, 0x80000000 | 9,   10,   11,

       0        // eod
};

void ShowCpuMemory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ShowCpuMemory *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetCpuMemory(); break;
        case 1: { int _r = _t->calCpuUsage();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { __int64 _r = _t->Filetime2Int64((*reinterpret_cast< const FILETIME*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< __int64*>(_a[0]) = std::move(_r); }  break;
        case 3: { __int64 _r = _t->CompareFileTime((*reinterpret_cast< FILETIME(*)>(_a[1])),(*reinterpret_cast< FILETIME(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< __int64*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ShowCpuMemory::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ShowCpuMemory.data,
    qt_meta_data_ShowCpuMemory,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ShowCpuMemory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowCpuMemory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShowCpuMemory.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ShowCpuMemory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
