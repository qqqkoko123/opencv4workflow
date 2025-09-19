/****************************************************************************
** Meta object code from reading C++ file 'FileHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../autoMeasure/system/FileHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileHandler_t {
    QByteArrayData data[15];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileHandler_t qt_meta_stringdata_FileHandler = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FileHandler"
QT_MOC_LITERAL(1, 12, 11), // "validateUrl"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 3), // "url"
QT_MOC_LITERAL(4, 29, 14), // "getCurrentPath"
QT_MOC_LITERAL(5, 44, 4), // "cdUp"
QT_MOC_LITERAL(6, 49, 3), // "dir"
QT_MOC_LITERAL(7, 53, 17), // "convertPathToName"
QT_MOC_LITERAL(8, 71, 17), // "convertPathToType"
QT_MOC_LITERAL(9, 89, 7), // "isImage"
QT_MOC_LITERAL(10, 97, 10), // "fileToIcon"
QT_MOC_LITERAL(11, 108, 11), // "imageToIcon"
QT_MOC_LITERAL(12, 120, 8), // "fileName"
QT_MOC_LITERAL(13, 129, 11), // "convertByte"
QT_MOC_LITERAL(14, 141, 4) // "byte"

    },
    "FileHandler\0validateUrl\0\0url\0"
    "getCurrentPath\0cdUp\0dir\0convertPathToName\0"
    "convertPathToType\0isImage\0fileToIcon\0"
    "imageToIcon\0fileName\0convertByte\0byte"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x02 /* Public */,
       4,    0,   67,    2, 0x02 /* Public */,
       5,    1,   68,    2, 0x02 /* Public */,
       7,    1,   71,    2, 0x02 /* Public */,
       8,    1,   74,    2, 0x02 /* Public */,
       9,    1,   77,    2, 0x02 /* Public */,
      10,    1,   80,    2, 0x02 /* Public */,
      11,    1,   83,    2, 0x02 /* Public */,
      12,    1,   86,    2, 0x02 /* Public */,
      13,    1,   89,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Bool, QMetaType::QUrl,    3,
    QMetaType::QString,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::Bool, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QUrl,    3,
    QMetaType::QString, QMetaType::QUrl,    3,
    QMetaType::QString, QMetaType::QUrl,    3,
    QMetaType::QString, QMetaType::Int,   14,

       0        // eod
};

void FileHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->validateUrl((*reinterpret_cast< const QUrl(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->getCurrentPath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->cdUp((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->convertPathToName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->convertPathToType((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->isImage((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->fileToIcon((*reinterpret_cast< const QUrl(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->imageToIcon((*reinterpret_cast< const QUrl(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->fileName((*reinterpret_cast< const QUrl(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->convertByte((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FileHandler.data,
    qt_meta_data_FileHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
