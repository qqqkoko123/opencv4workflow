/****************************************************************************
** Meta object code from reading C++ file 'frmImageMorphology.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../frmImageMorphology.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmImageMorphology.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmImageMorphology_t {
    QByteArrayData data[79];
    char stringdata0[1582];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmImageMorphology_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmImageMorphology_t qt_meta_stringdata_frmImageMorphology = {
    {
QT_MOC_LITERAL(0, 0, 18), // "frmImageMorphology"
QT_MOC_LITERAL(1, 19, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 21), // "on_btnExecute_clicked"
QT_MOC_LITERAL(4, 63, 23), // "on_btnLinkImage_clicked"
QT_MOC_LITERAL(5, 87, 26), // "on_btnDelLinkImage_clicked"
QT_MOC_LITERAL(6, 114, 20), // "on_btnAddROI_clicked"
QT_MOC_LITERAL(7, 135, 23), // "on_btnDeleteROI_clicked"
QT_MOC_LITERAL(8, 159, 21), // "on_btnAddType_clicked"
QT_MOC_LITERAL(9, 181, 24), // "on_btnDeleteType_clicked"
QT_MOC_LITERAL(10, 206, 20), // "on_btnMoveUp_clicked"
QT_MOC_LITERAL(11, 227, 22), // "on_btnMoveDown_clicked"
QT_MOC_LITERAL(12, 250, 27), // "on_btnThresholdBack_clicked"
QT_MOC_LITERAL(13, 278, 26), // "on_btnAdaptiveBack_clicked"
QT_MOC_LITERAL(14, 305, 22), // "on_btnBlurBack_clicked"
QT_MOC_LITERAL(15, 328, 28), // "on_btnMedianBlurBack_clicked"
QT_MOC_LITERAL(16, 357, 30), // "on_btnGaussianBlurBack_clicked"
QT_MOC_LITERAL(17, 388, 27), // "on_btnBilateralBack_clicked"
QT_MOC_LITERAL(18, 416, 21), // "on_btnBoxBack_clicked"
QT_MOC_LITERAL(19, 438, 23), // "on_btnSobelBack_clicked"
QT_MOC_LITERAL(20, 462, 23), // "on_btnCannyBack_clicked"
QT_MOC_LITERAL(21, 486, 25), // "on_btnLaplaceBack_clicked"
QT_MOC_LITERAL(22, 512, 23), // "on_btnErodeBack_clicked"
QT_MOC_LITERAL(23, 536, 24), // "on_btnDilateBack_clicked"
QT_MOC_LITERAL(24, 561, 22), // "on_btnOpenBack_clicked"
QT_MOC_LITERAL(25, 584, 23), // "on_btnCloseBack_clicked"
QT_MOC_LITERAL(26, 608, 24), // "on_btnTophatBack_clicked"
QT_MOC_LITERAL(27, 633, 26), // "on_btnBlackhatBack_clicked"
QT_MOC_LITERAL(28, 660, 26), // "on_btnGradientBack_clicked"
QT_MOC_LITERAL(29, 687, 25), // "on_btnHitmissBack_clicked"
QT_MOC_LITERAL(30, 713, 23), // "on_btnLightBack_clicked"
QT_MOC_LITERAL(31, 737, 27), // "on_btnLaplacianBack_clicked"
QT_MOC_LITERAL(32, 765, 26), // "on_btnContrastBack_clicked"
QT_MOC_LITERAL(33, 792, 23), // "on_btnGammaBack_clicked"
QT_MOC_LITERAL(34, 816, 21), // "on_btnMulBack_clicked"
QT_MOC_LITERAL(35, 838, 27), // "on_btnEmphasizeBack_clicked"
QT_MOC_LITERAL(36, 866, 29), // "on_btnUnevenLightBack_clicked"
QT_MOC_LITERAL(37, 896, 24), // "on_btnFillUpBack_clicked"
QT_MOC_LITERAL(38, 921, 28), // "on_btnShapeTransBack_clicked"
QT_MOC_LITERAL(39, 950, 24), // "on_btnThreshBack_clicked"
QT_MOC_LITERAL(40, 975, 25), // "on_btnChannelBack_clicked"
QT_MOC_LITERAL(41, 1001, 18), // "slot_DoubleClicked"
QT_MOC_LITERAL(42, 1020, 10), // "timerEvent"
QT_MOC_LITERAL(43, 1031, 11), // "slot_grayAc"
QT_MOC_LITERAL(44, 1043, 14), // "slot_channelAc"
QT_MOC_LITERAL(45, 1058, 13), // "slot_fillUpAc"
QT_MOC_LITERAL(46, 1072, 17), // "slot_shapeTransAc"
QT_MOC_LITERAL(47, 1090, 16), // "slot_thresholdAc"
QT_MOC_LITERAL(48, 1107, 17), // "slot_connectionAc"
QT_MOC_LITERAL(49, 1125, 15), // "slot_adaptiveAc"
QT_MOC_LITERAL(50, 1141, 13), // "slot_threshAc"
QT_MOC_LITERAL(51, 1155, 17), // "slot_entropySegAc"
QT_MOC_LITERAL(52, 1173, 16), // "slot_iterationAc"
QT_MOC_LITERAL(53, 1190, 11), // "slot_meanAc"
QT_MOC_LITERAL(54, 1202, 13), // "slot_medianAc"
QT_MOC_LITERAL(55, 1216, 12), // "slot_gaussAc"
QT_MOC_LITERAL(56, 1229, 16), // "slot_bilateralAc"
QT_MOC_LITERAL(57, 1246, 10), // "slot_boxAc"
QT_MOC_LITERAL(58, 1257, 13), // "slot_scharrAc"
QT_MOC_LITERAL(59, 1271, 12), // "slot_cannyAc"
QT_MOC_LITERAL(60, 1284, 14), // "slot_laplaceAc"
QT_MOC_LITERAL(61, 1299, 12), // "slot_sobelAc"
QT_MOC_LITERAL(62, 1312, 12), // "slot_erodeAc"
QT_MOC_LITERAL(63, 1325, 13), // "slot_dilateAc"
QT_MOC_LITERAL(64, 1339, 11), // "slot_openAc"
QT_MOC_LITERAL(65, 1351, 12), // "slot_closeAc"
QT_MOC_LITERAL(66, 1364, 13), // "slot_tophatAc"
QT_MOC_LITERAL(67, 1378, 16), // "slot_bottomhatAc"
QT_MOC_LITERAL(68, 1395, 15), // "slot_gradientAc"
QT_MOC_LITERAL(69, 1411, 14), // "slot_hitmissAc"
QT_MOC_LITERAL(70, 1426, 15), // "slot_contrastAc"
QT_MOC_LITERAL(71, 1442, 17), // "slot_brightnessAc"
QT_MOC_LITERAL(72, 1460, 14), // "slot_sharpenAc"
QT_MOC_LITERAL(73, 1475, 22), // "slot_gammaCorrectionAc"
QT_MOC_LITERAL(74, 1498, 16), // "slot_histogramAc"
QT_MOC_LITERAL(75, 1515, 19), // "slot_whiteBalanceAc"
QT_MOC_LITERAL(76, 1535, 16), // "slot_emphasizeAc"
QT_MOC_LITERAL(77, 1552, 10), // "slot_mulAc"
QT_MOC_LITERAL(78, 1563, 18) // "slot_unevenLightAc"

    },
    "frmImageMorphology\0onButtonCloseClicked\0"
    "\0on_btnExecute_clicked\0on_btnLinkImage_clicked\0"
    "on_btnDelLinkImage_clicked\0"
    "on_btnAddROI_clicked\0on_btnDeleteROI_clicked\0"
    "on_btnAddType_clicked\0on_btnDeleteType_clicked\0"
    "on_btnMoveUp_clicked\0on_btnMoveDown_clicked\0"
    "on_btnThresholdBack_clicked\0"
    "on_btnAdaptiveBack_clicked\0"
    "on_btnBlurBack_clicked\0"
    "on_btnMedianBlurBack_clicked\0"
    "on_btnGaussianBlurBack_clicked\0"
    "on_btnBilateralBack_clicked\0"
    "on_btnBoxBack_clicked\0on_btnSobelBack_clicked\0"
    "on_btnCannyBack_clicked\0"
    "on_btnLaplaceBack_clicked\0"
    "on_btnErodeBack_clicked\0"
    "on_btnDilateBack_clicked\0"
    "on_btnOpenBack_clicked\0on_btnCloseBack_clicked\0"
    "on_btnTophatBack_clicked\0"
    "on_btnBlackhatBack_clicked\0"
    "on_btnGradientBack_clicked\0"
    "on_btnHitmissBack_clicked\0"
    "on_btnLightBack_clicked\0"
    "on_btnLaplacianBack_clicked\0"
    "on_btnContrastBack_clicked\0"
    "on_btnGammaBack_clicked\0on_btnMulBack_clicked\0"
    "on_btnEmphasizeBack_clicked\0"
    "on_btnUnevenLightBack_clicked\0"
    "on_btnFillUpBack_clicked\0"
    "on_btnShapeTransBack_clicked\0"
    "on_btnThreshBack_clicked\0"
    "on_btnChannelBack_clicked\0slot_DoubleClicked\0"
    "timerEvent\0slot_grayAc\0slot_channelAc\0"
    "slot_fillUpAc\0slot_shapeTransAc\0"
    "slot_thresholdAc\0slot_connectionAc\0"
    "slot_adaptiveAc\0slot_threshAc\0"
    "slot_entropySegAc\0slot_iterationAc\0"
    "slot_meanAc\0slot_medianAc\0slot_gaussAc\0"
    "slot_bilateralAc\0slot_boxAc\0slot_scharrAc\0"
    "slot_cannyAc\0slot_laplaceAc\0slot_sobelAc\0"
    "slot_erodeAc\0slot_dilateAc\0slot_openAc\0"
    "slot_closeAc\0slot_tophatAc\0slot_bottomhatAc\0"
    "slot_gradientAc\0slot_hitmissAc\0"
    "slot_contrastAc\0slot_brightnessAc\0"
    "slot_sharpenAc\0slot_gammaCorrectionAc\0"
    "slot_histogramAc\0slot_whiteBalanceAc\0"
    "slot_emphasizeAc\0slot_mulAc\0"
    "slot_unevenLightAc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmImageMorphology[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      77,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  399,    2, 0x08 /* Private */,
       3,    0,  400,    2, 0x08 /* Private */,
       4,    0,  401,    2, 0x08 /* Private */,
       5,    0,  402,    2, 0x08 /* Private */,
       6,    0,  403,    2, 0x08 /* Private */,
       7,    0,  404,    2, 0x08 /* Private */,
       8,    0,  405,    2, 0x08 /* Private */,
       9,    0,  406,    2, 0x08 /* Private */,
      10,    0,  407,    2, 0x08 /* Private */,
      11,    0,  408,    2, 0x08 /* Private */,
      12,    0,  409,    2, 0x08 /* Private */,
      13,    0,  410,    2, 0x08 /* Private */,
      14,    0,  411,    2, 0x08 /* Private */,
      15,    0,  412,    2, 0x08 /* Private */,
      16,    0,  413,    2, 0x08 /* Private */,
      17,    0,  414,    2, 0x08 /* Private */,
      18,    0,  415,    2, 0x08 /* Private */,
      19,    0,  416,    2, 0x08 /* Private */,
      20,    0,  417,    2, 0x08 /* Private */,
      21,    0,  418,    2, 0x08 /* Private */,
      22,    0,  419,    2, 0x08 /* Private */,
      23,    0,  420,    2, 0x08 /* Private */,
      24,    0,  421,    2, 0x08 /* Private */,
      25,    0,  422,    2, 0x08 /* Private */,
      26,    0,  423,    2, 0x08 /* Private */,
      27,    0,  424,    2, 0x08 /* Private */,
      28,    0,  425,    2, 0x08 /* Private */,
      29,    0,  426,    2, 0x08 /* Private */,
      30,    0,  427,    2, 0x08 /* Private */,
      31,    0,  428,    2, 0x08 /* Private */,
      32,    0,  429,    2, 0x08 /* Private */,
      33,    0,  430,    2, 0x08 /* Private */,
      34,    0,  431,    2, 0x08 /* Private */,
      35,    0,  432,    2, 0x08 /* Private */,
      36,    0,  433,    2, 0x08 /* Private */,
      37,    0,  434,    2, 0x08 /* Private */,
      38,    0,  435,    2, 0x08 /* Private */,
      39,    0,  436,    2, 0x08 /* Private */,
      40,    0,  437,    2, 0x08 /* Private */,
      41,    2,  438,    2, 0x08 /* Private */,
      42,    0,  443,    2, 0x08 /* Private */,
      43,    0,  444,    2, 0x08 /* Private */,
      44,    0,  445,    2, 0x08 /* Private */,
      45,    0,  446,    2, 0x08 /* Private */,
      46,    0,  447,    2, 0x08 /* Private */,
      47,    0,  448,    2, 0x08 /* Private */,
      48,    0,  449,    2, 0x08 /* Private */,
      49,    0,  450,    2, 0x08 /* Private */,
      50,    0,  451,    2, 0x08 /* Private */,
      51,    0,  452,    2, 0x08 /* Private */,
      52,    0,  453,    2, 0x08 /* Private */,
      53,    0,  454,    2, 0x08 /* Private */,
      54,    0,  455,    2, 0x08 /* Private */,
      55,    0,  456,    2, 0x08 /* Private */,
      56,    0,  457,    2, 0x08 /* Private */,
      57,    0,  458,    2, 0x08 /* Private */,
      58,    0,  459,    2, 0x08 /* Private */,
      59,    0,  460,    2, 0x08 /* Private */,
      60,    0,  461,    2, 0x08 /* Private */,
      61,    0,  462,    2, 0x08 /* Private */,
      62,    0,  463,    2, 0x08 /* Private */,
      63,    0,  464,    2, 0x08 /* Private */,
      64,    0,  465,    2, 0x08 /* Private */,
      65,    0,  466,    2, 0x08 /* Private */,
      66,    0,  467,    2, 0x08 /* Private */,
      67,    0,  468,    2, 0x08 /* Private */,
      68,    0,  469,    2, 0x08 /* Private */,
      69,    0,  470,    2, 0x08 /* Private */,
      70,    0,  471,    2, 0x08 /* Private */,
      71,    0,  472,    2, 0x08 /* Private */,
      72,    0,  473,    2, 0x08 /* Private */,
      73,    0,  474,    2, 0x08 /* Private */,
      74,    0,  475,    2, 0x08 /* Private */,
      75,    0,  476,    2, 0x08 /* Private */,
      76,    0,  477,    2, 0x08 /* Private */,
      77,    0,  478,    2, 0x08 /* Private */,
      78,    0,  479,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmImageMorphology::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmImageMorphology *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonCloseClicked(); break;
        case 1: _t->on_btnExecute_clicked(); break;
        case 2: _t->on_btnLinkImage_clicked(); break;
        case 3: _t->on_btnDelLinkImage_clicked(); break;
        case 4: _t->on_btnAddROI_clicked(); break;
        case 5: _t->on_btnDeleteROI_clicked(); break;
        case 6: _t->on_btnAddType_clicked(); break;
        case 7: _t->on_btnDeleteType_clicked(); break;
        case 8: _t->on_btnMoveUp_clicked(); break;
        case 9: _t->on_btnMoveDown_clicked(); break;
        case 10: _t->on_btnThresholdBack_clicked(); break;
        case 11: _t->on_btnAdaptiveBack_clicked(); break;
        case 12: _t->on_btnBlurBack_clicked(); break;
        case 13: _t->on_btnMedianBlurBack_clicked(); break;
        case 14: _t->on_btnGaussianBlurBack_clicked(); break;
        case 15: _t->on_btnBilateralBack_clicked(); break;
        case 16: _t->on_btnBoxBack_clicked(); break;
        case 17: _t->on_btnSobelBack_clicked(); break;
        case 18: _t->on_btnCannyBack_clicked(); break;
        case 19: _t->on_btnLaplaceBack_clicked(); break;
        case 20: _t->on_btnErodeBack_clicked(); break;
        case 21: _t->on_btnDilateBack_clicked(); break;
        case 22: _t->on_btnOpenBack_clicked(); break;
        case 23: _t->on_btnCloseBack_clicked(); break;
        case 24: _t->on_btnTophatBack_clicked(); break;
        case 25: _t->on_btnBlackhatBack_clicked(); break;
        case 26: _t->on_btnGradientBack_clicked(); break;
        case 27: _t->on_btnHitmissBack_clicked(); break;
        case 28: _t->on_btnLightBack_clicked(); break;
        case 29: _t->on_btnLaplacianBack_clicked(); break;
        case 30: _t->on_btnContrastBack_clicked(); break;
        case 31: _t->on_btnGammaBack_clicked(); break;
        case 32: _t->on_btnMulBack_clicked(); break;
        case 33: _t->on_btnEmphasizeBack_clicked(); break;
        case 34: _t->on_btnUnevenLightBack_clicked(); break;
        case 35: _t->on_btnFillUpBack_clicked(); break;
        case 36: _t->on_btnShapeTransBack_clicked(); break;
        case 37: _t->on_btnThreshBack_clicked(); break;
        case 38: _t->on_btnChannelBack_clicked(); break;
        case 39: _t->slot_DoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 40: _t->timerEvent(); break;
        case 41: _t->slot_grayAc(); break;
        case 42: _t->slot_channelAc(); break;
        case 43: _t->slot_fillUpAc(); break;
        case 44: _t->slot_shapeTransAc(); break;
        case 45: _t->slot_thresholdAc(); break;
        case 46: _t->slot_connectionAc(); break;
        case 47: _t->slot_adaptiveAc(); break;
        case 48: _t->slot_threshAc(); break;
        case 49: _t->slot_entropySegAc(); break;
        case 50: _t->slot_iterationAc(); break;
        case 51: _t->slot_meanAc(); break;
        case 52: _t->slot_medianAc(); break;
        case 53: _t->slot_gaussAc(); break;
        case 54: _t->slot_bilateralAc(); break;
        case 55: _t->slot_boxAc(); break;
        case 56: _t->slot_scharrAc(); break;
        case 57: _t->slot_cannyAc(); break;
        case 58: _t->slot_laplaceAc(); break;
        case 59: _t->slot_sobelAc(); break;
        case 60: _t->slot_erodeAc(); break;
        case 61: _t->slot_dilateAc(); break;
        case 62: _t->slot_openAc(); break;
        case 63: _t->slot_closeAc(); break;
        case 64: _t->slot_tophatAc(); break;
        case 65: _t->slot_bottomhatAc(); break;
        case 66: _t->slot_gradientAc(); break;
        case 67: _t->slot_hitmissAc(); break;
        case 68: _t->slot_contrastAc(); break;
        case 69: _t->slot_brightnessAc(); break;
        case 70: _t->slot_sharpenAc(); break;
        case 71: _t->slot_gammaCorrectionAc(); break;
        case 72: _t->slot_histogramAc(); break;
        case 73: _t->slot_whiteBalanceAc(); break;
        case 74: _t->slot_emphasizeAc(); break;
        case 75: _t->slot_mulAc(); break;
        case 76: _t->slot_unevenLightAc(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmImageMorphology::staticMetaObject = { {
    QMetaObject::SuperData::link<Toolnterface::staticMetaObject>(),
    qt_meta_stringdata_frmImageMorphology.data,
    qt_meta_data_frmImageMorphology,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmImageMorphology::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmImageMorphology::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmImageMorphology.stringdata0))
        return static_cast<void*>(this);
    return Toolnterface::qt_metacast(_clname);
}

int frmImageMorphology::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Toolnterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 77)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 77;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 77)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 77;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
