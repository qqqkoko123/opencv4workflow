/****************************************************************************
** Meta object code from reading C++ file 'PlcCommunicate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../PlcCommunicate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlcCommunicate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlcCommunicate_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlcCommunicate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlcCommunicate_t qt_meta_stringdata_PlcCommunicate = {
    {
QT_MOC_LITERAL(0, 0, 14) // "PlcCommunicate"

    },
    "PlcCommunicate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlcCommunicate[] = {

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

void PlcCommunicate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PlcCommunicate::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PlcCommunicate.data,
    qt_meta_data_PlcCommunicate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PlcCommunicate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlcCommunicate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlcCommunicate.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "MainInterface"))
        return static_cast< MainInterface*>(this);
    if (!strcmp(_clname, "com.Interface.MainInterface"))
        return static_cast< MainInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int PlcCommunicate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x1b,  'c',  'o',  'm',  '.',  'I', 
    'n',  't',  'e',  'r',  'f',  'a',  'c',  'e', 
    '.',  'M',  'a',  'i',  'n',  'I',  'n',  't', 
    'e',  'r',  'f',  'a',  'c',  'e', 
    // "className"
    0x03,  0x6e,  'P',  'l',  'c',  'C',  'o',  'm', 
    'm',  'u',  'n',  'i',  'c',  'a',  't',  'e', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(PlcCommunicate, PlcCommunicate)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
