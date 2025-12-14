/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[43];
    char stringdata0[710];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "sig_ToThreadCpu"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "sig_LoginSignal"
QT_MOC_LITERAL(4, 44, 15), // "sig_AboutSignal"
QT_MOC_LITERAL(5, 60, 9), // "sig_Login"
QT_MOC_LITERAL(6, 70, 10), // "sig_Logout"
QT_MOC_LITERAL(7, 81, 13), // "sig_PermisSet"
QT_MOC_LITERAL(8, 95, 13), // "sig_ManualRun"
QT_MOC_LITERAL(9, 109, 14), // "sig_ManualStop"
QT_MOC_LITERAL(10, 124, 22), // "slot_DoTopLevelChanged"
QT_MOC_LITERAL(11, 147, 8), // "topLevel"
QT_MOC_LITERAL(12, 156, 17), // "slot_DoDockClosed"
QT_MOC_LITERAL(13, 174, 12), // "slot_DoLogin"
QT_MOC_LITERAL(14, 187, 12), // "slot_DoAbout"
QT_MOC_LITERAL(15, 200, 13), // "slot_CycleRun"
QT_MOC_LITERAL(16, 214, 14), // "slot_CycleStop"
QT_MOC_LITERAL(17, 229, 29), // "on_m_pRunContinueAc_triggered"
QT_MOC_LITERAL(18, 259, 14), // "slot_PermisSet"
QT_MOC_LITERAL(19, 274, 18), // "slot_DoSystemSetUp"
QT_MOC_LITERAL(20, 293, 18), // "slot_DoImageLayout"
QT_MOC_LITERAL(21, 312, 21), // "slot_DoGlobalVariable"
QT_MOC_LITERAL(22, 334, 18), // "slot_DoCameraSetUp"
QT_MOC_LITERAL(23, 353, 20), // "slot_Instrumentation"
QT_MOC_LITERAL(24, 374, 20), // "slot_DoCreateProject"
QT_MOC_LITERAL(25, 395, 18), // "slot_DoOpenProject"
QT_MOC_LITERAL(26, 414, 18), // "slot_DoSaveProject"
QT_MOC_LITERAL(27, 433, 20), // "slot_DoSaveAsProject"
QT_MOC_LITERAL(28, 454, 18), // "slot_DefaultLayout"
QT_MOC_LITERAL(29, 473, 15), // "slot_SaveLayout"
QT_MOC_LITERAL(30, 489, 15), // "slot_InitLayout"
QT_MOC_LITERAL(31, 505, 20), // "slot_RestoreToolDock"
QT_MOC_LITERAL(32, 526, 20), // "slot_RestoreFlowDock"
QT_MOC_LITERAL(33, 547, 19), // "slot_RestoreLogDock"
QT_MOC_LITERAL(34, 567, 13), // "slot_DelParam"
QT_MOC_LITERAL(35, 581, 10), // "timerEvent"
QT_MOC_LITERAL(36, 592, 17), // "slot_AllCycleStop"
QT_MOC_LITERAL(37, 610, 11), // "timerUpdate"
QT_MOC_LITERAL(38, 622, 18), // "slot_LoginBtnState"
QT_MOC_LITERAL(39, 641, 19), // "slot_LogoutBtnState"
QT_MOC_LITERAL(40, 661, 21), // "slot_OpenProjectParam"
QT_MOC_LITERAL(41, 683, 21), // "slot_SaveProjectParam"
QT_MOC_LITERAL(42, 705, 4) // "mode"

    },
    "MainWindow\0sig_ToThreadCpu\0\0sig_LoginSignal\0"
    "sig_AboutSignal\0sig_Login\0sig_Logout\0"
    "sig_PermisSet\0sig_ManualRun\0sig_ManualStop\0"
    "slot_DoTopLevelChanged\0topLevel\0"
    "slot_DoDockClosed\0slot_DoLogin\0"
    "slot_DoAbout\0slot_CycleRun\0slot_CycleStop\0"
    "on_m_pRunContinueAc_triggered\0"
    "slot_PermisSet\0slot_DoSystemSetUp\0"
    "slot_DoImageLayout\0slot_DoGlobalVariable\0"
    "slot_DoCameraSetUp\0slot_Instrumentation\0"
    "slot_DoCreateProject\0slot_DoOpenProject\0"
    "slot_DoSaveProject\0slot_DoSaveAsProject\0"
    "slot_DefaultLayout\0slot_SaveLayout\0"
    "slot_InitLayout\0slot_RestoreToolDock\0"
    "slot_RestoreFlowDock\0slot_RestoreLogDock\0"
    "slot_DelParam\0timerEvent\0slot_AllCycleStop\0"
    "timerUpdate\0slot_LoginBtnState\0"
    "slot_LogoutBtnState\0slot_OpenProjectParam\0"
    "slot_SaveProjectParam\0mode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  214,    2, 0x06 /* Public */,
       3,    0,  215,    2, 0x06 /* Public */,
       4,    0,  216,    2, 0x06 /* Public */,
       5,    0,  217,    2, 0x06 /* Public */,
       6,    0,  218,    2, 0x06 /* Public */,
       7,    0,  219,    2, 0x06 /* Public */,
       8,    0,  220,    2, 0x06 /* Public */,
       9,    0,  221,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  222,    2, 0x08 /* Private */,
      10,    0,  225,    2, 0x28 /* Private | MethodCloned */,
      12,    0,  226,    2, 0x08 /* Private */,
      13,    0,  227,    2, 0x08 /* Private */,
      14,    0,  228,    2, 0x08 /* Private */,
      15,    0,  229,    2, 0x08 /* Private */,
      16,    0,  230,    2, 0x08 /* Private */,
      17,    0,  231,    2, 0x08 /* Private */,
      18,    0,  232,    2, 0x08 /* Private */,
      19,    0,  233,    2, 0x08 /* Private */,
      20,    0,  234,    2, 0x08 /* Private */,
      21,    0,  235,    2, 0x08 /* Private */,
      22,    0,  236,    2, 0x08 /* Private */,
      23,    0,  237,    2, 0x08 /* Private */,
      24,    0,  238,    2, 0x08 /* Private */,
      25,    0,  239,    2, 0x08 /* Private */,
      26,    0,  240,    2, 0x08 /* Private */,
      27,    0,  241,    2, 0x08 /* Private */,
      28,    0,  242,    2, 0x08 /* Private */,
      29,    0,  243,    2, 0x08 /* Private */,
      30,    0,  244,    2, 0x08 /* Private */,
      31,    0,  245,    2, 0x08 /* Private */,
      32,    0,  246,    2, 0x08 /* Private */,
      33,    0,  247,    2, 0x08 /* Private */,
      34,    0,  248,    2, 0x08 /* Private */,
      35,    0,  249,    2, 0x0a /* Public */,
      36,    0,  250,    2, 0x0a /* Public */,
      37,    0,  251,    2, 0x0a /* Public */,
      38,    0,  252,    2, 0x0a /* Public */,
      39,    0,  253,    2, 0x0a /* Public */,
      40,    0,  254,    2, 0x0a /* Public */,
      41,    1,  255,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   11,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   42,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_ToThreadCpu(); break;
        case 1: _t->sig_LoginSignal(); break;
        case 2: _t->sig_AboutSignal(); break;
        case 3: _t->sig_Login(); break;
        case 4: _t->sig_Logout(); break;
        case 5: _t->sig_PermisSet(); break;
        case 6: _t->sig_ManualRun(); break;
        case 7: _t->sig_ManualStop(); break;
        case 8: _t->slot_DoTopLevelChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->slot_DoTopLevelChanged(); break;
        case 10: _t->slot_DoDockClosed(); break;
        case 11: _t->slot_DoLogin(); break;
        case 12: _t->slot_DoAbout(); break;
        case 13: _t->slot_CycleRun(); break;
        case 14: _t->slot_CycleStop(); break;
        case 15: _t->on_m_pRunContinueAc_triggered(); break;
        case 16: _t->slot_PermisSet(); break;
        case 17: _t->slot_DoSystemSetUp(); break;
        case 18: _t->slot_DoImageLayout(); break;
        case 19: _t->slot_DoGlobalVariable(); break;
        case 20: _t->slot_DoCameraSetUp(); break;
        case 21: _t->slot_Instrumentation(); break;
        case 22: _t->slot_DoCreateProject(); break;
        case 23: _t->slot_DoOpenProject(); break;
        case 24: _t->slot_DoSaveProject(); break;
        case 25: _t->slot_DoSaveAsProject(); break;
        case 26: _t->slot_DefaultLayout(); break;
        case 27: _t->slot_SaveLayout(); break;
        case 28: _t->slot_InitLayout(); break;
        case 29: _t->slot_RestoreToolDock(); break;
        case 30: _t->slot_RestoreFlowDock(); break;
        case 31: _t->slot_RestoreLogDock(); break;
        case 32: _t->slot_DelParam(); break;
        case 33: _t->timerEvent(); break;
        case 34: _t->slot_AllCycleStop(); break;
        case 35: _t->timerUpdate(); break;
        case 36: _t->slot_LoginBtnState(); break;
        case 37: _t->slot_LogoutBtnState(); break;
        case 38: _t->slot_OpenProjectParam(); break;
        case 39: _t->slot_SaveProjectParam((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_ToThreadCpu)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_LoginSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_AboutSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_Login)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_Logout)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_PermisSet)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_ManualRun)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_ManualStop)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 40;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sig_ToThreadCpu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::sig_LoginSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::sig_AboutSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::sig_Login()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::sig_Logout()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::sig_PermisSet()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MainWindow::sig_ManualRun()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MainWindow::sig_ManualStop()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
struct qt_meta_stringdata_DFMenuIconStyle_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DFMenuIconStyle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DFMenuIconStyle_t qt_meta_stringdata_DFMenuIconStyle = {
    {
QT_MOC_LITERAL(0, 0, 15) // "DFMenuIconStyle"

    },
    "DFMenuIconStyle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DFMenuIconStyle[] = {

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

void DFMenuIconStyle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DFMenuIconStyle::staticMetaObject = { {
    QMetaObject::SuperData::link<QProxyStyle::staticMetaObject>(),
    qt_meta_stringdata_DFMenuIconStyle.data,
    qt_meta_data_DFMenuIconStyle,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DFMenuIconStyle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DFMenuIconStyle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DFMenuIconStyle.stringdata0))
        return static_cast<void*>(this);
    return QProxyStyle::qt_metacast(_clname);
}

int DFMenuIconStyle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QProxyStyle::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
