/****************************************************************************
** Meta object code from reading C++ file 'CvMediaPlayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../autoMeasure/component/CvMediaPlayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CvMediaPlayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CvMediaPlayer_t {
    QByteArrayData data[28];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CvMediaPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CvMediaPlayer_t qt_meta_stringdata_CvMediaPlayer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CvMediaPlayer"
QT_MOC_LITERAL(1, 14, 12), // "widthChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "srcWidth"
QT_MOC_LITERAL(4, 37, 13), // "heightChanged"
QT_MOC_LITERAL(5, 51, 9), // "srcHeight"
QT_MOC_LITERAL(6, 61, 10), // "fpsChanged"
QT_MOC_LITERAL(7, 72, 3), // "fps"
QT_MOC_LITERAL(8, 76, 15), // "durationChanged"
QT_MOC_LITERAL(9, 92, 8), // "duration"
QT_MOC_LITERAL(10, 101, 15), // "positionChanged"
QT_MOC_LITERAL(11, 117, 8), // "position"
QT_MOC_LITERAL(12, 126, 8), // "setWidth"
QT_MOC_LITERAL(13, 135, 5), // "value"
QT_MOC_LITERAL(14, 141, 9), // "setHeight"
QT_MOC_LITERAL(15, 151, 6), // "setFps"
QT_MOC_LITERAL(16, 158, 11), // "setDuration"
QT_MOC_LITERAL(17, 170, 11), // "setPosition"
QT_MOC_LITERAL(18, 182, 3), // "run"
QT_MOC_LITERAL(19, 186, 11), // "openPicture"
QT_MOC_LITERAL(20, 198, 4), // "path"
QT_MOC_LITERAL(21, 203, 9), // "openVideo"
QT_MOC_LITERAL(22, 213, 14), // "openWebPicture"
QT_MOC_LITERAL(23, 228, 10), // "openCamera"
QT_MOC_LITERAL(24, 239, 10), // "openWebCam"
QT_MOC_LITERAL(25, 250, 2), // "ip"
QT_MOC_LITERAL(26, 253, 11), // "savePicture"
QT_MOC_LITERAL(27, 265, 4) // "stop"

    },
    "CvMediaPlayer\0widthChanged\0\0srcWidth\0"
    "heightChanged\0srcHeight\0fpsChanged\0"
    "fps\0durationChanged\0duration\0"
    "positionChanged\0position\0setWidth\0"
    "value\0setHeight\0setFps\0setDuration\0"
    "setPosition\0run\0openPicture\0path\0"
    "openVideo\0openWebPicture\0openCamera\0"
    "openWebCam\0ip\0savePicture\0stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CvMediaPlayer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       5,  152, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       4,    1,  107,    2, 0x06 /* Public */,
       6,    1,  110,    2, 0x06 /* Public */,
       8,    1,  113,    2, 0x06 /* Public */,
      10,    1,  116,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,  119,    2, 0x0a /* Public */,
      14,    1,  122,    2, 0x0a /* Public */,
      15,    1,  125,    2, 0x0a /* Public */,
      16,    1,  128,    2, 0x0a /* Public */,
      17,    1,  131,    2, 0x0a /* Public */,
      18,    0,  134,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      19,    1,  135,    2, 0x02 /* Public */,
      21,    1,  138,    2, 0x02 /* Public */,
      22,    1,  141,    2, 0x02 /* Public */,
      23,    0,  144,    2, 0x02 /* Public */,
      24,    1,  145,    2, 0x02 /* Public */,
      26,    1,  148,    2, 0x02 /* Public */,
      27,    0,  151,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::QString, QMetaType::QString,   20,
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00495003,
       5, QMetaType::Int, 0x00495003,
       7, QMetaType::Int, 0x00495103,
       9, QMetaType::Double, 0x00495103,
      11, QMetaType::Double, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void CvMediaPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CvMediaPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->widthChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->heightChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->fpsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->durationChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->positionChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setFps((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setDuration((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setPosition((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->run(); break;
        case 11: _t->openPicture((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->openVideo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->openWebPicture((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->openCamera(); break;
        case 15: _t->openWebCam((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: { QString _r = _t->savePicture((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CvMediaPlayer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CvMediaPlayer::widthChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CvMediaPlayer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CvMediaPlayer::heightChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CvMediaPlayer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CvMediaPlayer::fpsChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CvMediaPlayer::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CvMediaPlayer::durationChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CvMediaPlayer::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CvMediaPlayer::positionChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CvMediaPlayer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getWidth(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getHeight(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getFps(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->getDuration(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->getPosition(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CvMediaPlayer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setWidth(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setHeight(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setFps(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setDuration(*reinterpret_cast< double*>(_v)); break;
        case 4: _t->setPosition(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CvMediaPlayer::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickFramebufferObject::staticMetaObject>(),
    qt_meta_stringdata_CvMediaPlayer.data,
    qt_meta_data_CvMediaPlayer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CvMediaPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CvMediaPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CvMediaPlayer.stringdata0))
        return static_cast<void*>(this);
    return QQuickFramebufferObject::qt_metacast(_clname);
}

int CvMediaPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickFramebufferObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CvMediaPlayer::widthChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CvMediaPlayer::heightChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CvMediaPlayer::fpsChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CvMediaPlayer::durationChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CvMediaPlayer::positionChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
