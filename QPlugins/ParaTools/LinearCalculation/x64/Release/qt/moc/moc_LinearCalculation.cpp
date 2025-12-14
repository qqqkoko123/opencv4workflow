/****************************************************************************
** Meta object code from reading C++ file 'LinearCalculation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../LinearCalculation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LinearCalculation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LinearCalculation_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LinearCalculation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LinearCalculation_t qt_meta_stringdata_LinearCalculation = {
    {
QT_MOC_LITERAL(0, 0, 17) // "LinearCalculation"

    },
    "LinearCalculation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LinearCalculation[] = {

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

void LinearCalculation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject LinearCalculation::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_LinearCalculation.data,
    qt_meta_data_LinearCalculation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LinearCalculation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LinearCalculation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LinearCalculation.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "MainInterface"))
        return static_cast< MainInterface*>(this);
    if (!strcmp(_clname, "com.Interface.MainInterface"))
        return static_cast< MainInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int LinearCalculation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    0x03,  0x71,  'L',  'i',  'n',  'e',  'a',  'r', 
    'C',  'a',  'l',  'c',  'u',  'l',  'a',  't', 
    'i',  'o',  'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(LinearCalculation, LinearCalculation)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
