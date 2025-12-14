/********************************************************************************
** Form generated from reading UI file 'frmImageMorphology.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMIMAGEMORPHOLOGY_H
#define UI_FRMIMAGEMORPHOLOGY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmImageMorphologyClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QGridLayout *imageLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupC_3;
    QLabel *label_4;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QPushButton *btnDelLinkImage;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *groupC;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidgetType;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnAddType;
    QPushButton *btnDeleteType;
    QPushButton *btnMoveUp;
    QPushButton *btnMoveDown;
    QSpacerItem *verticalSpacer_3;
    QWidget *horizontalLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *lblType;
    QPushButton *btnMenu;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *checkRealTime;
    QWidget *page_31;
    QGroupBox *groupParam_30;
    QPushButton *btnChannelBack;
    QLabel *label_62;
    QComboBox *comboChannel;
    QGroupBox *groupC_2;
    QRadioButton *radioImage;
    QRadioButton *radioImageC1;
    QRadioButton *radioImageC2;
    QRadioButton *radioImageC3;
    QWidget *page_27;
    QGroupBox *groupParam_26;
    QPushButton *btnFillUpBack;
    QLabel *label_58;
    QComboBox *comboFillUp;
    QWidget *page_28;
    QGroupBox *groupParam_27;
    QPushButton *btnShapeTransBack;
    QLabel *label_59;
    QComboBox *comboShapeTrans;
    QComboBox *comboSTColor;
    QLabel *label_60;
    QWidget *page_2;
    QGroupBox *groupParam;
    QLabel *label_7;
    QSpinBox *spinMinThreshold;
    QPushButton *btnThresholdBack;
    QLabel *label_8;
    QSpinBox *spinMaxThreshold;
    QLabel *label_9;
    QComboBox *comboThreshold;
    QWidget *page_3;
    QGroupBox *groupParam_28;
    QLabel *label_56;
    QSpinBox *spinMinThresh;
    QPushButton *btnThreshBack;
    QLabel *label_57;
    QSpinBox *spinMaxThresh;
    QWidget *page_29;
    QGroupBox *groupParam_2;
    QLabel *label_10;
    QSpinBox *spinAdaptiveOffset;
    QPushButton *btnAdaptiveBack;
    QLabel *label_11;
    QSpinBox *spinAdaptiveKSize;
    QLabel *label_12;
    QComboBox *comboAdaptiveType;
    QWidget *page_4;
    QGroupBox *groupParam_3;
    QPushButton *btnBlurBack;
    QLabel *label_14;
    QSpinBox *spinBlurKSize;
    QWidget *page_5;
    QGroupBox *groupParam_4;
    QPushButton *btnMedianBlurBack;
    QLabel *label_15;
    QSpinBox *spinMedianBlurKSize;
    QWidget *page_6;
    QGroupBox *groupParam_5;
    QPushButton *btnGaussianBlurBack;
    QLabel *label_16;
    QSpinBox *spinGaussianBlurKSize;
    QWidget *page_7;
    QGroupBox *groupParam_6;
    QPushButton *btnBilateralBack;
    QLabel *label_17;
    QSpinBox *spinBilateralDSize;
    QLabel *label_18;
    QSpinBox *spinBilateralSigma;
    QWidget *page_8;
    QGroupBox *groupParam_7;
    QPushButton *btnBoxBack;
    QLabel *label_19;
    QSpinBox *spinBoxKSize;
    QWidget *page_9;
    QGroupBox *groupParam_8;
    QPushButton *btnSobelBack;
    QLabel *label_20;
    QSpinBox *spinSobelKSize;
    QWidget *page_10;
    QGroupBox *groupParam_9;
    QLabel *label_13;
    QSpinBox *spinCannyMinThreshold;
    QPushButton *btnCannyBack;
    QLabel *label_21;
    QSpinBox *spinCannyMaxThreshold;
    QSpinBox *spinCannyKSize;
    QLabel *label_23;
    QWidget *page_11;
    QGroupBox *groupParam_10;
    QPushButton *btnLaplaceBack;
    QLabel *label_22;
    QSpinBox *spinLaplaceKSize;
    QWidget *page_12;
    QGroupBox *groupParam_11;
    QPushButton *btnErodeBack;
    QLabel *label_25;
    QSpinBox *spinErodeSize;
    QLabel *label_26;
    QComboBox *comboErodeType;
    QLabel *label_27;
    QSpinBox *spinErodeIterations;
    QWidget *page_13;
    QGroupBox *groupParam_12;
    QPushButton *btnDilateBack;
    QLabel *label_28;
    QSpinBox *spinDilateSize;
    QLabel *label_29;
    QComboBox *comboDilateType;
    QLabel *label_30;
    QSpinBox *spinDilateIterations;
    QWidget *page_14;
    QGroupBox *groupParam_13;
    QPushButton *btnOpenBack;
    QLabel *label_31;
    QSpinBox *spinOpenSize;
    QLabel *label_32;
    QComboBox *comboOpenType;
    QLabel *label_33;
    QSpinBox *spinOpenIterations;
    QWidget *page_15;
    QGroupBox *groupParam_14;
    QPushButton *btnCloseBack;
    QLabel *label_34;
    QSpinBox *spinCloseSize;
    QLabel *label_35;
    QComboBox *comboCloseType;
    QLabel *label_36;
    QSpinBox *spinCloseIterations;
    QWidget *page_16;
    QGroupBox *groupParam_15;
    QPushButton *btnTophatBack;
    QLabel *label_37;
    QSpinBox *spinTophatSize;
    QLabel *label_38;
    QComboBox *comboTophatType;
    QLabel *label_39;
    QSpinBox *spinTophatIterations;
    QWidget *page_17;
    QGroupBox *groupParam_16;
    QPushButton *btnBlackhatBack;
    QLabel *label_40;
    QSpinBox *spinBlackhatSize;
    QLabel *label_41;
    QComboBox *comboBlackhatType;
    QLabel *label_42;
    QSpinBox *spinBlackhatIterations;
    QWidget *page_18;
    QGroupBox *groupParam_17;
    QPushButton *btnGradientBack;
    QLabel *label_43;
    QSpinBox *spinGradientSize;
    QLabel *label_44;
    QComboBox *comboGradientType;
    QLabel *label_45;
    QSpinBox *spinGradientIterations;
    QWidget *page_19;
    QGroupBox *groupParam_18;
    QPushButton *btnHitmissBack;
    QLabel *label_46;
    QSpinBox *spinHitmissSize;
    QLabel *label_47;
    QComboBox *comboHitmissType;
    QLabel *label_48;
    QSpinBox *spinHitmissIterations;
    QWidget *page_20;
    QGroupBox *groupParam_19;
    QPushButton *btnLightBack;
    QLabel *label_24;
    QSpinBox *spinLightValue;
    QWidget *page_21;
    QGroupBox *groupParam_20;
    QPushButton *btnLaplacianBack;
    QLabel *label_49;
    QSpinBox *spinLaplacianKSize;
    QWidget *page_22;
    QGroupBox *groupParam_21;
    QPushButton *btnContrastBack;
    QLabel *label_50;
    QSpinBox *spinContrastValue;
    QWidget *page_23;
    QGroupBox *groupParam_22;
    QPushButton *btnGammaBack;
    QLabel *label_51;
    QDoubleSpinBox *spinGammaValue;
    QWidget *page_24;
    QGroupBox *groupParam_23;
    QPushButton *btnMulBack;
    QLabel *label_52;
    QDoubleSpinBox *spinMulValue;
    QWidget *page_25;
    QGroupBox *groupParam_24;
    QPushButton *btnEmphasizeBack;
    QLabel *label_53;
    QSpinBox *spinEmphasizeKSize;
    QLabel *label_54;
    QDoubleSpinBox *spinEmphasizeValue;
    QWidget *page_26;
    QGroupBox *groupParam_25;
    QPushButton *btnUnevenLightBack;
    QLabel *label_55;
    QSpinBox *spinUnevenLightSize;
    QWidget *tab_4;
    QGroupBox *groupCamera_9;
    QCheckBox *checkUseROI;
    QComboBox *comboROIShape;
    QPushButton *btnAddROI;
    QPushButton *btnDeleteROI;

    void setupUi(QDialog *frmImageMorphologyClass)
    {
        if (frmImageMorphologyClass->objectName().isEmpty())
            frmImageMorphologyClass->setObjectName(QString::fromUtf8("frmImageMorphologyClass"));
        frmImageMorphologyClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmImageMorphologyClass->sizePolicy().hasHeightForWidth());
        frmImageMorphologyClass->setSizePolicy(sizePolicy);
        frmImageMorphologyClass->setMinimumSize(QSize(1160, 655));
        frmImageMorphologyClass->setMaximumSize(QSize(1160, 655));
        frmImageMorphologyClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmImageMorphologyClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        imageLayout = new QGridLayout();
        imageLayout->setSpacing(1);
        imageLayout->setObjectName(QString::fromUtf8("imageLayout"));

        gridLayout->addLayout(imageLayout, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmImageMorphologyClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmImageMorphologyClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmImageMorphologyClass);
        btnExecute->setObjectName(QString::fromUtf8("btnExecute"));
        btnExecute->setMinimumSize(QSize(90, 37));
        btnExecute->setFont(font);
        btnExecute->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 135, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 155, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 175, 127);}"));

        horizontalLayout->addWidget(btnExecute);

        horizontalSpacer_2 = new QSpacerItem(6, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        tabWidget = new QTabWidget(frmImageMorphologyClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(450, 550));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupC_3 = new QGroupBox(tab);
        groupC_3->setObjectName(QString::fromUtf8("groupC_3"));
        groupC_3->setGeometry(QRect(9, 18, 427, 73));
        groupC_3->setFont(font);
        groupC_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_4 = new QLabel(groupC_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(13, 42, 79, 19));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtLinkImage = new QLineEdit(groupC_3);
        txtLinkImage->setObjectName(QString::fromUtf8("txtLinkImage"));
        txtLinkImage->setGeometry(QRect(100, 39, 255, 27));
        txtLinkImage->setFont(font);
        txtLinkImage->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkImage->setAlignment(Qt::AlignCenter);
        txtLinkImage->setReadOnly(true);
        btnLinkImage = new QPushButton(groupC_3);
        btnLinkImage->setObjectName(QString::fromUtf8("btnLinkImage"));
        btnLinkImage->setGeometry(QRect(360, 39, 27, 27));
        btnLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLinkImage->setIcon(icon);
        btnLinkImage->setIconSize(QSize(27, 27));
        btnDelLinkImage = new QPushButton(groupC_3);
        btnDelLinkImage->setObjectName(QString::fromUtf8("btnDelLinkImage"));
        btnDelLinkImage->setGeometry(QRect(394, 39, 27, 27));
        btnDelLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/del_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelLinkImage->setIcon(icon1);
        btnDelLinkImage->setIconSize(QSize(27, 27));
        stackedWidget = new QStackedWidget(tab);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(3, 90, 439, 427));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        groupC = new QGroupBox(page);
        groupC->setObjectName(QString::fromUtf8("groupC"));
        groupC->setGeometry(QRect(6, 10, 427, 417));
        groupC->setFont(font);
        groupC->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        horizontalLayoutWidget_3 = new QWidget(groupC);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(8, 82, 411, 329));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(horizontalLayoutWidget_3);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setStyleSheet(QString::fromUtf8("border: 1px solid;\n"
"border-color: rgba(173, 173, 173, 155);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableWidgetType = new QTableWidget(frame_3);
        if (tableWidgetType->columnCount() < 1)
            tableWidgetType->setColumnCount(1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tableWidgetType->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidgetType->setObjectName(QString::fromUtf8("tableWidgetType"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        tableWidgetType->setFont(font2);
        tableWidgetType->setStyleSheet(QString::fromUtf8("QTableWidget          \n"
"{\n"
"    background-color: #b7c7af; \n"
"    border:none;\n"
"    gridline-color: rgba(20, 25, 155,50);\n"
"    color: rgba(20, 20, 20,200);\n"
"}\n"
"QTableWidget::item::selected\n"
"{   \n"
"    background-color: rgba(180, 180, 215,255); \n"
"}\n"
"QScrollBar:vertical{ \n"
"		background:#FFFFF2;\n"
"		padding-top:20px;\n"
"		padding-bottom:20px;\n"
"		padding-left:2px;\n"
"		padding-right:2px;\n"
"		border-left:1px solid #d7d7d7;}\n"
"QScrollBar::handle:vertical{\n"
"		background:#dbdbdb;\n"
"		border-radius:6px;\n"
"		min-height:20px;}\n"
"QScrollBar::handle:vertical:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:vertical{\n"
"		background:url(:/resource/down.png) center no-repeat;}\n"
"QScrollBar::sub-line:vertical{\n"
"		background:url(:/resource/up.png) center no-repeat;}\n"
"QScrollBar:horizontal{ \n"
"		background:#FFFFF2;\n"
"		padding-top:20px;\n"
"		padding-bottom:20px;\n"
"		padding-left:2px;\n"
"		padding-right:2px;\n"
"		border-left:1px solid #d7d7d7;}\n"
""
                        "QScrollBar::handle:horizontal{\n"
"		background:#dbdbdb;\n"
"		border-radius:6px;\n"
"		min-height:20px;}\n"
"QScrollBar::handle:horizontal:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:horizontal{\n"
"		background:url(:/resource/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/resource/left.png) center no-repeat;}"));
        tableWidgetType->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetType->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetType->setGridStyle(Qt::DashLine);
        tableWidgetType->horizontalHeader()->setMinimumSectionSize(29);
        tableWidgetType->horizontalHeader()->setDefaultSectionSize(338);
        tableWidgetType->verticalHeader()->setDefaultSectionSize(30);

        verticalLayout_3->addWidget(tableWidgetType);


        horizontalLayout_3->addWidget(frame_3);

        frame_4 = new QFrame(horizontalLayoutWidget_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setStyleSheet(QString::fromUtf8("border: 1px solid;\n"
"border-color: rgba(173, 173, 173, 155);\n"
"background-color: #b7c7a7;"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_4);
        verticalLayout_4->setSpacing(17);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(1, 2, 1, 1);
        btnAddType = new QPushButton(frame_4);
        btnAddType->setObjectName(QString::fromUtf8("btnAddType"));
        sizePolicy.setHeightForWidth(btnAddType->sizePolicy().hasHeightForWidth());
        btnAddType->setSizePolicy(sizePolicy);
        btnAddType->setMinimumSize(QSize(60, 30));
        btnAddType->setFont(font1);
        btnAddType->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        verticalLayout_4->addWidget(btnAddType);

        btnDeleteType = new QPushButton(frame_4);
        btnDeleteType->setObjectName(QString::fromUtf8("btnDeleteType"));
        sizePolicy.setHeightForWidth(btnDeleteType->sizePolicy().hasHeightForWidth());
        btnDeleteType->setSizePolicy(sizePolicy);
        btnDeleteType->setMinimumSize(QSize(60, 30));
        btnDeleteType->setFont(font1);
        btnDeleteType->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));

        verticalLayout_4->addWidget(btnDeleteType);

        btnMoveUp = new QPushButton(frame_4);
        btnMoveUp->setObjectName(QString::fromUtf8("btnMoveUp"));
        sizePolicy.setHeightForWidth(btnMoveUp->sizePolicy().hasHeightForWidth());
        btnMoveUp->setSizePolicy(sizePolicy);
        btnMoveUp->setMinimumSize(QSize(60, 30));
        btnMoveUp->setFont(font2);
        btnMoveUp->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        verticalLayout_4->addWidget(btnMoveUp);

        btnMoveDown = new QPushButton(frame_4);
        btnMoveDown->setObjectName(QString::fromUtf8("btnMoveDown"));
        sizePolicy.setHeightForWidth(btnMoveDown->sizePolicy().hasHeightForWidth());
        btnMoveDown->setSizePolicy(sizePolicy);
        btnMoveDown->setMinimumSize(QSize(60, 30));
        btnMoveDown->setFont(font2);
        btnMoveDown->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        verticalLayout_4->addWidget(btnMoveDown);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);


        horizontalLayout_3->addWidget(frame_4);

        horizontalLayoutWidget_2 = new QWidget(groupC);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(8, 34, 411, 39));
        gridLayout_2 = new QGridLayout(horizontalLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(1);
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(horizontalLayoutWidget_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setStyleSheet(QString::fromUtf8("border: 1px solid;\n"
"border-color: rgba(173, 173, 173, 155);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 1, 0);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);"));

        horizontalLayout_2->addWidget(label);

        lblType = new QLabel(frame);
        lblType->setObjectName(QString::fromUtf8("lblType"));
        sizePolicy3.setHeightForWidth(lblType->sizePolicy().hasHeightForWidth());
        lblType->setSizePolicy(sizePolicy3);
        lblType->setMinimumSize(QSize(136, 0));
        lblType->setMaximumSize(QSize(136, 16777215));
        lblType->setFont(font);
        lblType->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        lblType->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lblType);

        btnMenu = new QPushButton(frame);
        btnMenu->setObjectName(QString::fromUtf8("btnMenu"));
        sizePolicy.setHeightForWidth(btnMenu->sizePolicy().hasHeightForWidth());
        btnMenu->setSizePolicy(sizePolicy);
        btnMenu->setMinimumSize(QSize(42, 35));
        btnMenu->setMaximumSize(QSize(42, 35));
        btnMenu->setStyleSheet(QString::fromUtf8("QWidget{border: none}\n"
"QPushButton::menu-indicator{image:none}\n"
"QPushButton:hover{background-color: rgb(188, 199, 228)}\n"
"QPushButton:pressed{background-color: rgb(139, 158, 210)}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resource/btnmenu.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMenu->setIcon(icon2);
        btnMenu->setIconSize(QSize(42, 35));

        horizontalLayout_2->addWidget(btnMenu);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        checkRealTime = new QCheckBox(frame);
        checkRealTime->setObjectName(QString::fromUtf8("checkRealTime"));
        sizePolicy.setHeightForWidth(checkRealTime->sizePolicy().hasHeightForWidth());
        checkRealTime->setSizePolicy(sizePolicy);
        checkRealTime->setFont(font);
        checkRealTime->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 17px;\n"
"    height: 17px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));

        horizontalLayout_2->addWidget(checkRealTime);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_31 = new QWidget();
        page_31->setObjectName(QString::fromUtf8("page_31"));
        groupParam_30 = new QGroupBox(page_31);
        groupParam_30->setObjectName(QString::fromUtf8("groupParam_30"));
        groupParam_30->setGeometry(QRect(6, 10, 427, 417));
        groupParam_30->setFont(font);
        groupParam_30->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnChannelBack = new QPushButton(groupParam_30);
        btnChannelBack->setObjectName(QString::fromUtf8("btnChannelBack"));
        btnChannelBack->setGeometry(QRect(352, 376, 70, 35));
        btnChannelBack->setMinimumSize(QSize(70, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        btnChannelBack->setFont(font3);
        btnChannelBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_62 = new QLabel(groupParam_30);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(22, 48, 149, 19));
        label_62->setFont(font);
        label_62->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboChannel = new QComboBox(groupParam_30);
        comboChannel->addItem(QString());
        comboChannel->addItem(QString());
        comboChannel->addItem(QString());
        comboChannel->addItem(QString());
        comboChannel->addItem(QString());
        comboChannel->addItem(QString());
        comboChannel->addItem(QString());
        comboChannel->setObjectName(QString::fromUtf8("comboChannel"));
        comboChannel->setGeometry(QRect(174, 42, 120, 30));
        sizePolicy.setHeightForWidth(comboChannel->sizePolicy().hasHeightForWidth());
        comboChannel->setSizePolicy(sizePolicy);
        comboChannel->setMinimumSize(QSize(120, 30));
        comboChannel->setMaximumSize(QSize(120, 16777215));
        comboChannel->setFont(font);
        comboChannel->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboChannel->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        groupC_2 = new QGroupBox(groupParam_30);
        groupC_2->setObjectName(QString::fromUtf8("groupC_2"));
        groupC_2->setGeometry(QRect(8, 88, 411, 117));
        groupC_2->setFont(font);
        groupC_2->setStyleSheet(QString::fromUtf8("background-color: #acbbac;\n"
"color: rgb(0, 0, 127);"));
        radioImage = new QRadioButton(groupC_2);
        radioImage->setObjectName(QString::fromUtf8("radioImage"));
        radioImage->setGeometry(QRect(56, 40, 115, 19));
        radioImage->setFont(font);
        radioImage->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        radioImage->setChecked(true);
        radioImageC1 = new QRadioButton(groupC_2);
        radioImageC1->setObjectName(QString::fromUtf8("radioImageC1"));
        radioImageC1->setGeometry(QRect(248, 40, 115, 19));
        radioImageC1->setFont(font);
        radioImageC1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        radioImageC2 = new QRadioButton(groupC_2);
        radioImageC2->setObjectName(QString::fromUtf8("radioImageC2"));
        radioImageC2->setGeometry(QRect(56, 90, 115, 19));
        radioImageC2->setFont(font);
        radioImageC2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        radioImageC3 = new QRadioButton(groupC_2);
        radioImageC3->setObjectName(QString::fromUtf8("radioImageC3"));
        radioImageC3->setGeometry(QRect(248, 90, 115, 19));
        radioImageC3->setFont(font);
        radioImageC3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        stackedWidget->addWidget(page_31);
        page_27 = new QWidget();
        page_27->setObjectName(QString::fromUtf8("page_27"));
        groupParam_26 = new QGroupBox(page_27);
        groupParam_26->setObjectName(QString::fromUtf8("groupParam_26"));
        groupParam_26->setGeometry(QRect(6, 10, 427, 417));
        groupParam_26->setFont(font);
        groupParam_26->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnFillUpBack = new QPushButton(groupParam_26);
        btnFillUpBack->setObjectName(QString::fromUtf8("btnFillUpBack"));
        btnFillUpBack->setGeometry(QRect(352, 376, 70, 35));
        btnFillUpBack->setMinimumSize(QSize(70, 30));
        btnFillUpBack->setFont(font3);
        btnFillUpBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_58 = new QLabel(groupParam_26);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(22, 48, 97, 21));
        label_58->setFont(font);
        label_58->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboFillUp = new QComboBox(groupParam_26);
        comboFillUp->addItem(QString());
        comboFillUp->addItem(QString());
        comboFillUp->setObjectName(QString::fromUtf8("comboFillUp"));
        comboFillUp->setGeometry(QRect(124, 43, 100, 30));
        sizePolicy.setHeightForWidth(comboFillUp->sizePolicy().hasHeightForWidth());
        comboFillUp->setSizePolicy(sizePolicy);
        comboFillUp->setMinimumSize(QSize(100, 30));
        comboFillUp->setMaximumSize(QSize(100, 16777215));
        comboFillUp->setFont(font);
        comboFillUp->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboFillUp->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        stackedWidget->addWidget(page_27);
        page_28 = new QWidget();
        page_28->setObjectName(QString::fromUtf8("page_28"));
        groupParam_27 = new QGroupBox(page_28);
        groupParam_27->setObjectName(QString::fromUtf8("groupParam_27"));
        groupParam_27->setGeometry(QRect(6, 10, 427, 417));
        groupParam_27->setFont(font);
        groupParam_27->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnShapeTransBack = new QPushButton(groupParam_27);
        btnShapeTransBack->setObjectName(QString::fromUtf8("btnShapeTransBack"));
        btnShapeTransBack->setGeometry(QRect(352, 376, 70, 35));
        btnShapeTransBack->setMinimumSize(QSize(70, 30));
        btnShapeTransBack->setFont(font3);
        btnShapeTransBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_59 = new QLabel(groupParam_27);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(22, 48, 83, 21));
        label_59->setFont(font);
        label_59->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboShapeTrans = new QComboBox(groupParam_27);
        comboShapeTrans->addItem(QString());
        comboShapeTrans->addItem(QString());
        comboShapeTrans->addItem(QString());
        comboShapeTrans->setObjectName(QString::fromUtf8("comboShapeTrans"));
        comboShapeTrans->setGeometry(QRect(104, 43, 130, 30));
        sizePolicy.setHeightForWidth(comboShapeTrans->sizePolicy().hasHeightForWidth());
        comboShapeTrans->setSizePolicy(sizePolicy);
        comboShapeTrans->setMinimumSize(QSize(130, 30));
        comboShapeTrans->setMaximumSize(QSize(130, 16777215));
        comboShapeTrans->setFont(font);
        comboShapeTrans->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboShapeTrans->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboSTColor = new QComboBox(groupParam_27);
        comboSTColor->addItem(QString());
        comboSTColor->addItem(QString());
        comboSTColor->setObjectName(QString::fromUtf8("comboSTColor"));
        comboSTColor->setGeometry(QRect(122, 98, 111, 30));
        sizePolicy.setHeightForWidth(comboSTColor->sizePolicy().hasHeightForWidth());
        comboSTColor->setSizePolicy(sizePolicy);
        comboSTColor->setMinimumSize(QSize(111, 30));
        comboSTColor->setMaximumSize(QSize(111, 16777215));
        comboSTColor->setFont(font);
        comboSTColor->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboSTColor->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label_60 = new QLabel(groupParam_27);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(22, 103, 97, 21));
        label_60->setFont(font);
        label_60->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        stackedWidget->addWidget(page_28);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        groupParam = new QGroupBox(page_2);
        groupParam->setObjectName(QString::fromUtf8("groupParam"));
        groupParam->setGeometry(QRect(6, 10, 427, 417));
        groupParam->setFont(font);
        groupParam->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_7 = new QLabel(groupParam);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(22, 48, 79, 19));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinThreshold = new QSpinBox(groupParam);
        spinMinThreshold->setObjectName(QString::fromUtf8("spinMinThreshold"));
        spinMinThreshold->setGeometry(QRect(104, 44, 70, 27));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(11);
        spinMinThreshold->setFont(font4);
        spinMinThreshold->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMinThreshold->setAlignment(Qt::AlignCenter);
        spinMinThreshold->setMinimum(0);
        spinMinThreshold->setMaximum(254);
        spinMinThreshold->setSingleStep(1);
        spinMinThreshold->setValue(0);
        btnThresholdBack = new QPushButton(groupParam);
        btnThresholdBack->setObjectName(QString::fromUtf8("btnThresholdBack"));
        btnThresholdBack->setGeometry(QRect(352, 376, 70, 35));
        btnThresholdBack->setMinimumSize(QSize(70, 30));
        btnThresholdBack->setFont(font3);
        btnThresholdBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_8 = new QLabel(groupParam);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(250, 48, 79, 19));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMaxThreshold = new QSpinBox(groupParam);
        spinMaxThreshold->setObjectName(QString::fromUtf8("spinMaxThreshold"));
        spinMaxThreshold->setGeometry(QRect(332, 44, 70, 27));
        spinMaxThreshold->setFont(font4);
        spinMaxThreshold->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMaxThreshold->setAlignment(Qt::AlignCenter);
        spinMaxThreshold->setMinimum(1);
        spinMaxThreshold->setMaximum(255);
        spinMaxThreshold->setSingleStep(1);
        spinMaxThreshold->setValue(255);
        label_9 = new QLabel(groupParam);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(22, 96, 79, 19));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboThreshold = new QComboBox(groupParam);
        comboThreshold->addItem(QString());
        comboThreshold->addItem(QString());
        comboThreshold->addItem(QString());
        comboThreshold->addItem(QString());
        comboThreshold->addItem(QString());
        comboThreshold->addItem(QString());
        comboThreshold->addItem(QString());
        comboThreshold->setObjectName(QString::fromUtf8("comboThreshold"));
        comboThreshold->setGeometry(QRect(104, 91, 212, 30));
        sizePolicy.setHeightForWidth(comboThreshold->sizePolicy().hasHeightForWidth());
        comboThreshold->setSizePolicy(sizePolicy);
        comboThreshold->setMinimumSize(QSize(212, 30));
        comboThreshold->setMaximumSize(QSize(212, 16777215));
        comboThreshold->setFont(font);
        comboThreshold->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboThreshold->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        groupParam_28 = new QGroupBox(page_3);
        groupParam_28->setObjectName(QString::fromUtf8("groupParam_28"));
        groupParam_28->setGeometry(QRect(6, 10, 427, 417));
        groupParam_28->setFont(font);
        groupParam_28->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_56 = new QLabel(groupParam_28);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(22, 48, 79, 19));
        label_56->setFont(font);
        label_56->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinThresh = new QSpinBox(groupParam_28);
        spinMinThresh->setObjectName(QString::fromUtf8("spinMinThresh"));
        spinMinThresh->setGeometry(QRect(104, 44, 70, 27));
        spinMinThresh->setFont(font4);
        spinMinThresh->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMinThresh->setAlignment(Qt::AlignCenter);
        spinMinThresh->setMinimum(0);
        spinMinThresh->setMaximum(254);
        spinMinThresh->setSingleStep(1);
        spinMinThresh->setValue(0);
        btnThreshBack = new QPushButton(groupParam_28);
        btnThreshBack->setObjectName(QString::fromUtf8("btnThreshBack"));
        btnThreshBack->setGeometry(QRect(352, 376, 70, 35));
        btnThreshBack->setMinimumSize(QSize(70, 30));
        btnThreshBack->setFont(font3);
        btnThreshBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_57 = new QLabel(groupParam_28);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(250, 48, 79, 19));
        label_57->setFont(font);
        label_57->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMaxThresh = new QSpinBox(groupParam_28);
        spinMaxThresh->setObjectName(QString::fromUtf8("spinMaxThresh"));
        spinMaxThresh->setGeometry(QRect(332, 44, 70, 27));
        spinMaxThresh->setFont(font4);
        spinMaxThresh->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMaxThresh->setAlignment(Qt::AlignCenter);
        spinMaxThresh->setMinimum(1);
        spinMaxThresh->setMaximum(255);
        spinMaxThresh->setSingleStep(1);
        spinMaxThresh->setValue(255);
        stackedWidget->addWidget(page_3);
        page_29 = new QWidget();
        page_29->setObjectName(QString::fromUtf8("page_29"));
        groupParam_2 = new QGroupBox(page_29);
        groupParam_2->setObjectName(QString::fromUtf8("groupParam_2"));
        groupParam_2->setGeometry(QRect(6, 10, 427, 417));
        groupParam_2->setFont(font);
        groupParam_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_10 = new QLabel(groupParam_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(22, 48, 79, 19));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinAdaptiveOffset = new QSpinBox(groupParam_2);
        spinAdaptiveOffset->setObjectName(QString::fromUtf8("spinAdaptiveOffset"));
        spinAdaptiveOffset->setGeometry(QRect(88, 44, 70, 27));
        spinAdaptiveOffset->setFont(font4);
        spinAdaptiveOffset->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinAdaptiveOffset->setAlignment(Qt::AlignCenter);
        spinAdaptiveOffset->setMinimum(-255);
        spinAdaptiveOffset->setMaximum(255);
        spinAdaptiveOffset->setSingleStep(1);
        spinAdaptiveOffset->setValue(5);
        btnAdaptiveBack = new QPushButton(groupParam_2);
        btnAdaptiveBack->setObjectName(QString::fromUtf8("btnAdaptiveBack"));
        btnAdaptiveBack->setGeometry(QRect(352, 376, 70, 35));
        btnAdaptiveBack->setMinimumSize(QSize(70, 30));
        btnAdaptiveBack->setFont(font3);
        btnAdaptiveBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_11 = new QLabel(groupParam_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(200, 48, 131, 19));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinAdaptiveKSize = new QSpinBox(groupParam_2);
        spinAdaptiveKSize->setObjectName(QString::fromUtf8("spinAdaptiveKSize"));
        spinAdaptiveKSize->setGeometry(QRect(336, 44, 70, 27));
        spinAdaptiveKSize->setFont(font4);
        spinAdaptiveKSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinAdaptiveKSize->setAlignment(Qt::AlignCenter);
        spinAdaptiveKSize->setMinimum(1);
        spinAdaptiveKSize->setMaximum(101);
        spinAdaptiveKSize->setSingleStep(1);
        spinAdaptiveKSize->setValue(9);
        label_12 = new QLabel(groupParam_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(22, 96, 113, 19));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboAdaptiveType = new QComboBox(groupParam_2);
        comboAdaptiveType->addItem(QString());
        comboAdaptiveType->addItem(QString());
        comboAdaptiveType->addItem(QString());
        comboAdaptiveType->addItem(QString());
        comboAdaptiveType->setObjectName(QString::fromUtf8("comboAdaptiveType"));
        comboAdaptiveType->setGeometry(QRect(140, 91, 130, 30));
        sizePolicy.setHeightForWidth(comboAdaptiveType->sizePolicy().hasHeightForWidth());
        comboAdaptiveType->setSizePolicy(sizePolicy);
        comboAdaptiveType->setMinimumSize(QSize(130, 30));
        comboAdaptiveType->setMaximumSize(QSize(130, 16777215));
        comboAdaptiveType->setFont(font);
        comboAdaptiveType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboAdaptiveType->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        stackedWidget->addWidget(page_29);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        groupParam_3 = new QGroupBox(page_4);
        groupParam_3->setObjectName(QString::fromUtf8("groupParam_3"));
        groupParam_3->setGeometry(QRect(6, 10, 427, 417));
        groupParam_3->setFont(font);
        groupParam_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnBlurBack = new QPushButton(groupParam_3);
        btnBlurBack->setObjectName(QString::fromUtf8("btnBlurBack"));
        btnBlurBack->setGeometry(QRect(352, 376, 70, 35));
        btnBlurBack->setMinimumSize(QSize(70, 30));
        btnBlurBack->setFont(font3);
        btnBlurBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_14 = new QLabel(groupParam_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(22, 48, 131, 19));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinBlurKSize = new QSpinBox(groupParam_3);
        spinBlurKSize->setObjectName(QString::fromUtf8("spinBlurKSize"));
        spinBlurKSize->setGeometry(QRect(160, 44, 70, 27));
        spinBlurKSize->setFont(font4);
        spinBlurKSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinBlurKSize->setAlignment(Qt::AlignCenter);
        spinBlurKSize->setMinimum(1);
        spinBlurKSize->setMaximum(101);
        spinBlurKSize->setSingleStep(1);
        spinBlurKSize->setValue(9);
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        groupParam_4 = new QGroupBox(page_5);
        groupParam_4->setObjectName(QString::fromUtf8("groupParam_4"));
        groupParam_4->setGeometry(QRect(6, 10, 427, 417));
        groupParam_4->setFont(font);
        groupParam_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnMedianBlurBack = new QPushButton(groupParam_4);
        btnMedianBlurBack->setObjectName(QString::fromUtf8("btnMedianBlurBack"));
        btnMedianBlurBack->setGeometry(QRect(352, 376, 70, 35));
        btnMedianBlurBack->setMinimumSize(QSize(70, 30));
        btnMedianBlurBack->setFont(font3);
        btnMedianBlurBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_15 = new QLabel(groupParam_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(22, 48, 131, 19));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMedianBlurKSize = new QSpinBox(groupParam_4);
        spinMedianBlurKSize->setObjectName(QString::fromUtf8("spinMedianBlurKSize"));
        spinMedianBlurKSize->setGeometry(QRect(160, 44, 70, 27));
        spinMedianBlurKSize->setFont(font4);
        spinMedianBlurKSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMedianBlurKSize->setAlignment(Qt::AlignCenter);
        spinMedianBlurKSize->setMinimum(1);
        spinMedianBlurKSize->setMaximum(101);
        spinMedianBlurKSize->setSingleStep(1);
        spinMedianBlurKSize->setValue(9);
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        groupParam_5 = new QGroupBox(page_6);
        groupParam_5->setObjectName(QString::fromUtf8("groupParam_5"));
        groupParam_5->setGeometry(QRect(6, 10, 427, 417));
        groupParam_5->setFont(font);
        groupParam_5->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnGaussianBlurBack = new QPushButton(groupParam_5);
        btnGaussianBlurBack->setObjectName(QString::fromUtf8("btnGaussianBlurBack"));
        btnGaussianBlurBack->setGeometry(QRect(352, 376, 70, 35));
        btnGaussianBlurBack->setMinimumSize(QSize(70, 30));
        btnGaussianBlurBack->setFont(font3);
        btnGaussianBlurBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_16 = new QLabel(groupParam_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(22, 48, 131, 19));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinGaussianBlurKSize = new QSpinBox(groupParam_5);
        spinGaussianBlurKSize->setObjectName(QString::fromUtf8("spinGaussianBlurKSize"));
        spinGaussianBlurKSize->setGeometry(QRect(160, 44, 70, 27));
        spinGaussianBlurKSize->setFont(font4);
        spinGaussianBlurKSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinGaussianBlurKSize->setAlignment(Qt::AlignCenter);
        spinGaussianBlurKSize->setMinimum(1);
        spinGaussianBlurKSize->setMaximum(101);
        spinGaussianBlurKSize->setSingleStep(1);
        spinGaussianBlurKSize->setValue(9);
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        groupParam_6 = new QGroupBox(page_7);
        groupParam_6->setObjectName(QString::fromUtf8("groupParam_6"));
        groupParam_6->setGeometry(QRect(6, 10, 427, 417));
        groupParam_6->setFont(font);
        groupParam_6->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnBilateralBack = new QPushButton(groupParam_6);
        btnBilateralBack->setObjectName(QString::fromUtf8("btnBilateralBack"));
        btnBilateralBack->setGeometry(QRect(352, 376, 70, 35));
        btnBilateralBack->setMinimumSize(QSize(70, 30));
        btnBilateralBack->setFont(font3);
        btnBilateralBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_17 = new QLabel(groupParam_6);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(22, 48, 131, 19));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinBilateralDSize = new QSpinBox(groupParam_6);
        spinBilateralDSize->setObjectName(QString::fromUtf8("spinBilateralDSize"));
        spinBilateralDSize->setGeometry(QRect(160, 44, 70, 27));
        spinBilateralDSize->setFont(font4);
        spinBilateralDSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinBilateralDSize->setAlignment(Qt::AlignCenter);
        spinBilateralDSize->setMinimum(1);
        spinBilateralDSize->setMaximum(11);
        spinBilateralDSize->setSingleStep(1);
        spinBilateralDSize->setValue(5);
        label_18 = new QLabel(groupParam_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(252, 47, 83, 21));
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinBilateralSigma = new QSpinBox(groupParam_6);
        spinBilateralSigma->setObjectName(QString::fromUtf8("spinBilateralSigma"));
        spinBilateralSigma->setGeometry(QRect(336, 44, 70, 27));
        spinBilateralSigma->setFont(font4);
        spinBilateralSigma->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinBilateralSigma->setAlignment(Qt::AlignCenter);
        spinBilateralSigma->setMinimum(1);
        spinBilateralSigma->setMaximum(255);
        spinBilateralSigma->setSingleStep(1);
        spinBilateralSigma->setValue(21);
        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        groupParam_7 = new QGroupBox(page_8);
        groupParam_7->setObjectName(QString::fromUtf8("groupParam_7"));
        groupParam_7->setGeometry(QRect(6, 10, 427, 417));
        groupParam_7->setFont(font);
        groupParam_7->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnBoxBack = new QPushButton(groupParam_7);
        btnBoxBack->setObjectName(QString::fromUtf8("btnBoxBack"));
        btnBoxBack->setGeometry(QRect(352, 376, 70, 35));
        btnBoxBack->setMinimumSize(QSize(70, 30));
        btnBoxBack->setFont(font3);
        btnBoxBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_19 = new QLabel(groupParam_7);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(22, 48, 131, 19));
        label_19->setFont(font);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinBoxKSize = new QSpinBox(groupParam_7);
        spinBoxKSize->setObjectName(QString::fromUtf8("spinBoxKSize"));
        spinBoxKSize->setGeometry(QRect(160, 44, 70, 27));
        spinBoxKSize->setFont(font4);
        spinBoxKSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinBoxKSize->setAlignment(Qt::AlignCenter);
        spinBoxKSize->setMinimum(1);
        spinBoxKSize->setMaximum(101);
        spinBoxKSize->setSingleStep(1);
        spinBoxKSize->setValue(9);
        stackedWidget->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        groupParam_8 = new QGroupBox(page_9);
        groupParam_8->setObjectName(QString::fromUtf8("groupParam_8"));
        groupParam_8->setGeometry(QRect(6, 10, 427, 417));
        groupParam_8->setFont(font);
        groupParam_8->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnSobelBack = new QPushButton(groupParam_8);
        btnSobelBack->setObjectName(QString::fromUtf8("btnSobelBack"));
        btnSobelBack->setGeometry(QRect(352, 376, 70, 35));
        btnSobelBack->setMinimumSize(QSize(70, 30));
        btnSobelBack->setFont(font3);
        btnSobelBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_20 = new QLabel(groupParam_8);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(22, 48, 143, 19));
        label_20->setFont(font);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinSobelKSize = new QSpinBox(groupParam_8);
        spinSobelKSize->setObjectName(QString::fromUtf8("spinSobelKSize"));
        spinSobelKSize->setGeometry(QRect(168, 44, 70, 27));
        spinSobelKSize->setFont(font4);
        spinSobelKSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinSobelKSize->setAlignment(Qt::AlignCenter);
        spinSobelKSize->setMinimum(1);
        spinSobelKSize->setMaximum(101);
        spinSobelKSize->setSingleStep(1);
        spinSobelKSize->setValue(9);
        stackedWidget->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName(QString::fromUtf8("page_10"));
        groupParam_9 = new QGroupBox(page_10);
        groupParam_9->setObjectName(QString::fromUtf8("groupParam_9"));
        groupParam_9->setGeometry(QRect(6, 10, 427, 417));
        groupParam_9->setFont(font);
        groupParam_9->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_13 = new QLabel(groupParam_9);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(22, 48, 79, 19));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinCannyMinThreshold = new QSpinBox(groupParam_9);
        spinCannyMinThreshold->setObjectName(QString::fromUtf8("spinCannyMinThreshold"));
        spinCannyMinThreshold->setGeometry(QRect(104, 44, 70, 27));
        spinCannyMinThreshold->setFont(font4);
        spinCannyMinThreshold->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinCannyMinThreshold->setAlignment(Qt::AlignCenter);
        spinCannyMinThreshold->setMinimum(0);
        spinCannyMinThreshold->setMaximum(254);
        spinCannyMinThreshold->setSingleStep(1);
        spinCannyMinThreshold->setValue(0);
        btnCannyBack = new QPushButton(groupParam_9);
        btnCannyBack->setObjectName(QString::fromUtf8("btnCannyBack"));
        btnCannyBack->setGeometry(QRect(352, 376, 70, 35));
        btnCannyBack->setMinimumSize(QSize(70, 30));
        btnCannyBack->setFont(font3);
        btnCannyBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_21 = new QLabel(groupParam_9);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(250, 48, 79, 19));
        label_21->setFont(font);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinCannyMaxThreshold = new QSpinBox(groupParam_9);
        spinCannyMaxThreshold->setObjectName(QString::fromUtf8("spinCannyMaxThreshold"));
        spinCannyMaxThreshold->setGeometry(QRect(332, 44, 70, 27));
        spinCannyMaxThreshold->setFont(font4);
        spinCannyMaxThreshold->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinCannyMaxThreshold->setAlignment(Qt::AlignCenter);
        spinCannyMaxThreshold->setMinimum(1);
        spinCannyMaxThreshold->setMaximum(255);
        spinCannyMaxThreshold->setSingleStep(1);
        spinCannyMaxThreshold->setValue(255);
        spinCannyKSize = new QSpinBox(groupParam_9);
        spinCannyKSize->setObjectName(QString::fromUtf8("spinCannyKSize"));
        spinCannyKSize->setGeometry(QRect(170, 94, 70, 27));
        spinCannyKSize->setFont(font4);
        spinCannyKSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinCannyKSize->setAlignment(Qt::AlignCenter);
        spinCannyKSize->setMinimum(3);
        spinCannyKSize->setMaximum(5);
        spinCannyKSize->setSingleStep(1);
        spinCannyKSize->setValue(3);
        label_23 = new QLabel(groupParam_9);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(22, 96, 143, 22));
        label_23->setFont(font);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        stackedWidget->addWidget(page_10);
        page_11 = new QWidget();
        page_11->setObjectName(QString::fromUtf8("page_11"));
        groupParam_10 = new QGroupBox(page_11);
        groupParam_10->setObjectName(QString::fromUtf8("groupParam_10"));
        groupParam_10->setGeometry(QRect(6, 10, 427, 417));
        groupParam_10->setFont(font);
        groupParam_10->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnLaplaceBack = new QPushButton(groupParam_10);
        btnLaplaceBack->setObjectName(QString::fromUtf8("btnLaplaceBack"));
        btnLaplaceBack->setGeometry(QRect(352, 376, 70, 35));
        btnLaplaceBack->setMinimumSize(QSize(70, 30));
        btnLaplaceBack->setFont(font3);
        btnLaplaceBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_22 = new QLabel(groupParam_10);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(22, 48, 161, 19));
        label_22->setFont(font);
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinLaplaceKSize = new QSpinBox(groupParam_10);
        spinLaplaceKSize->setObjectName(QString::fromUtf8("spinLaplaceKSize"));
        spinLaplaceKSize->setGeometry(QRect(184, 44, 70, 27));
        spinLaplaceKSize->setFont(font4);
        spinLaplaceKSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinLaplaceKSize->setAlignment(Qt::AlignCenter);
        spinLaplaceKSize->setMinimum(1);
        spinLaplaceKSize->setMaximum(101);
        spinLaplaceKSize->setSingleStep(1);
        spinLaplaceKSize->setValue(9);
        stackedWidget->addWidget(page_11);
        page_12 = new QWidget();
        page_12->setObjectName(QString::fromUtf8("page_12"));
        groupParam_11 = new QGroupBox(page_12);
        groupParam_11->setObjectName(QString::fromUtf8("groupParam_11"));
        groupParam_11->setGeometry(QRect(6, 10, 427, 417));
        groupParam_11->setFont(font);
        groupParam_11->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnErodeBack = new QPushButton(groupParam_11);
        btnErodeBack->setObjectName(QString::fromUtf8("btnErodeBack"));
        btnErodeBack->setGeometry(QRect(352, 376, 70, 35));
        btnErodeBack->setMinimumSize(QSize(70, 30));
        btnErodeBack->setFont(font3);
        btnErodeBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_25 = new QLabel(groupParam_11);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(22, 48, 131, 19));
        label_25->setFont(font);
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinErodeSize = new QSpinBox(groupParam_11);
        spinErodeSize->setObjectName(QString::fromUtf8("spinErodeSize"));
        spinErodeSize->setGeometry(QRect(136, 45, 70, 27));
        spinErodeSize->setFont(font4);
        spinErodeSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinErodeSize->setAlignment(Qt::AlignCenter);
        spinErodeSize->setMinimum(1);
        spinErodeSize->setMaximum(101);
        spinErodeSize->setSingleStep(1);
        spinErodeSize->setValue(9);
        label_26 = new QLabel(groupParam_11);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(232, 48, 79, 19));
        label_26->setFont(font);
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboErodeType = new QComboBox(groupParam_11);
        comboErodeType->addItem(QString());
        comboErodeType->addItem(QString());
        comboErodeType->addItem(QString());
        comboErodeType->setObjectName(QString::fromUtf8("comboErodeType"));
        comboErodeType->setGeometry(QRect(314, 43, 90, 30));
        sizePolicy.setHeightForWidth(comboErodeType->sizePolicy().hasHeightForWidth());
        comboErodeType->setSizePolicy(sizePolicy);
        comboErodeType->setMinimumSize(QSize(90, 30));
        comboErodeType->setMaximumSize(QSize(90, 16777215));
        comboErodeType->setFont(font);
        comboErodeType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboErodeType->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label_27 = new QLabel(groupParam_11);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(22, 96, 83, 19));
        label_27->setFont(font);
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinErodeIterations = new QSpinBox(groupParam_11);
        spinErodeIterations->setObjectName(QString::fromUtf8("spinErodeIterations"));
        spinErodeIterations->setGeometry(QRect(102, 94, 70, 27));
        spinErodeIterations->setFont(font4);
        spinErodeIterations->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinErodeIterations->setAlignment(Qt::AlignCenter);
        spinErodeIterations->setMinimum(1);
        spinErodeIterations->setMaximum(100);
        spinErodeIterations->setSingleStep(1);
        spinErodeIterations->setValue(1);
        stackedWidget->addWidget(page_12);
        page_13 = new QWidget();
        page_13->setObjectName(QString::fromUtf8("page_13"));
        groupParam_12 = new QGroupBox(page_13);
        groupParam_12->setObjectName(QString::fromUtf8("groupParam_12"));
        groupParam_12->setGeometry(QRect(6, 10, 427, 417));
        groupParam_12->setFont(font);
        groupParam_12->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnDilateBack = new QPushButton(groupParam_12);
        btnDilateBack->setObjectName(QString::fromUtf8("btnDilateBack"));
        btnDilateBack->setGeometry(QRect(352, 376, 70, 35));
        btnDilateBack->setMinimumSize(QSize(70, 30));
        btnDilateBack->setFont(font3);
        btnDilateBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_28 = new QLabel(groupParam_12);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(22, 48, 115, 19));
        label_28->setFont(font);
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinDilateSize = new QSpinBox(groupParam_12);
        spinDilateSize->setObjectName(QString::fromUtf8("spinDilateSize"));
        spinDilateSize->setGeometry(QRect(136, 45, 70, 27));
        spinDilateSize->setFont(font4);
        spinDilateSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinDilateSize->setAlignment(Qt::AlignCenter);
        spinDilateSize->setMinimum(1);
        spinDilateSize->setMaximum(101);
        spinDilateSize->setSingleStep(1);
        spinDilateSize->setValue(9);
        label_29 = new QLabel(groupParam_12);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(232, 48, 79, 19));
        label_29->setFont(font);
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboDilateType = new QComboBox(groupParam_12);
        comboDilateType->addItem(QString());
        comboDilateType->addItem(QString());
        comboDilateType->addItem(QString());
        comboDilateType->setObjectName(QString::fromUtf8("comboDilateType"));
        comboDilateType->setGeometry(QRect(314, 43, 90, 30));
        sizePolicy.setHeightForWidth(comboDilateType->sizePolicy().hasHeightForWidth());
        comboDilateType->setSizePolicy(sizePolicy);
        comboDilateType->setMinimumSize(QSize(90, 30));
        comboDilateType->setMaximumSize(QSize(90, 16777215));
        comboDilateType->setFont(font);
        comboDilateType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboDilateType->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label_30 = new QLabel(groupParam_12);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(22, 96, 83, 19));
        label_30->setFont(font);
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinDilateIterations = new QSpinBox(groupParam_12);
        spinDilateIterations->setObjectName(QString::fromUtf8("spinDilateIterations"));
        spinDilateIterations->setGeometry(QRect(102, 94, 70, 27));
        spinDilateIterations->setFont(font4);
        spinDilateIterations->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinDilateIterations->setAlignment(Qt::AlignCenter);
        spinDilateIterations->setMinimum(1);
        spinDilateIterations->setMaximum(100);
        spinDilateIterations->setSingleStep(1);
        spinDilateIterations->setValue(1);
        stackedWidget->addWidget(page_13);
        page_14 = new QWidget();
        page_14->setObjectName(QString::fromUtf8("page_14"));
        groupParam_13 = new QGroupBox(page_14);
        groupParam_13->setObjectName(QString::fromUtf8("groupParam_13"));
        groupParam_13->setGeometry(QRect(6, 10, 427, 417));
        groupParam_13->setFont(font);
        groupParam_13->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnOpenBack = new QPushButton(groupParam_13);
        btnOpenBack->setObjectName(QString::fromUtf8("btnOpenBack"));
        btnOpenBack->setGeometry(QRect(352, 376, 70, 35));
        btnOpenBack->setMinimumSize(QSize(70, 30));
        btnOpenBack->setFont(font3);
        btnOpenBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_31 = new QLabel(groupParam_13);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(22, 48, 131, 19));
        label_31->setFont(font);
        label_31->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinOpenSize = new QSpinBox(groupParam_13);
        spinOpenSize->setObjectName(QString::fromUtf8("spinOpenSize"));
        spinOpenSize->setGeometry(QRect(136, 45, 70, 27));
        spinOpenSize->setFont(font4);
        spinOpenSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinOpenSize->setAlignment(Qt::AlignCenter);
        spinOpenSize->setMinimum(1);
        spinOpenSize->setMaximum(101);
        spinOpenSize->setSingleStep(1);
        spinOpenSize->setValue(9);
        label_32 = new QLabel(groupParam_13);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(232, 48, 79, 19));
        label_32->setFont(font);
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboOpenType = new QComboBox(groupParam_13);
        comboOpenType->addItem(QString());
        comboOpenType->addItem(QString());
        comboOpenType->addItem(QString());
        comboOpenType->setObjectName(QString::fromUtf8("comboOpenType"));
        comboOpenType->setGeometry(QRect(314, 43, 90, 30));
        sizePolicy.setHeightForWidth(comboOpenType->sizePolicy().hasHeightForWidth());
        comboOpenType->setSizePolicy(sizePolicy);
        comboOpenType->setMinimumSize(QSize(90, 30));
        comboOpenType->setMaximumSize(QSize(90, 16777215));
        comboOpenType->setFont(font);
        comboOpenType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboOpenType->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label_33 = new QLabel(groupParam_13);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(22, 96, 83, 19));
        label_33->setFont(font);
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinOpenIterations = new QSpinBox(groupParam_13);
        spinOpenIterations->setObjectName(QString::fromUtf8("spinOpenIterations"));
        spinOpenIterations->setGeometry(QRect(102, 94, 70, 27));
        spinOpenIterations->setFont(font4);
        spinOpenIterations->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinOpenIterations->setAlignment(Qt::AlignCenter);
        spinOpenIterations->setMinimum(1);
        spinOpenIterations->setMaximum(100);
        spinOpenIterations->setSingleStep(1);
        spinOpenIterations->setValue(1);
        stackedWidget->addWidget(page_14);
        page_15 = new QWidget();
        page_15->setObjectName(QString::fromUtf8("page_15"));
        groupParam_14 = new QGroupBox(page_15);
        groupParam_14->setObjectName(QString::fromUtf8("groupParam_14"));
        groupParam_14->setGeometry(QRect(6, 10, 427, 417));
        groupParam_14->setFont(font);
        groupParam_14->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnCloseBack = new QPushButton(groupParam_14);
        btnCloseBack->setObjectName(QString::fromUtf8("btnCloseBack"));
        btnCloseBack->setGeometry(QRect(352, 376, 70, 35));
        btnCloseBack->setMinimumSize(QSize(70, 30));
        btnCloseBack->setFont(font3);
        btnCloseBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_34 = new QLabel(groupParam_14);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(22, 48, 115, 19));
        label_34->setFont(font);
        label_34->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinCloseSize = new QSpinBox(groupParam_14);
        spinCloseSize->setObjectName(QString::fromUtf8("spinCloseSize"));
        spinCloseSize->setGeometry(QRect(136, 45, 70, 27));
        spinCloseSize->setFont(font4);
        spinCloseSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinCloseSize->setAlignment(Qt::AlignCenter);
        spinCloseSize->setMinimum(1);
        spinCloseSize->setMaximum(101);
        spinCloseSize->setSingleStep(1);
        spinCloseSize->setValue(9);
        label_35 = new QLabel(groupParam_14);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(232, 48, 79, 19));
        label_35->setFont(font);
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboCloseType = new QComboBox(groupParam_14);
        comboCloseType->addItem(QString());
        comboCloseType->addItem(QString());
        comboCloseType->addItem(QString());
        comboCloseType->setObjectName(QString::fromUtf8("comboCloseType"));
        comboCloseType->setGeometry(QRect(314, 43, 90, 30));
        sizePolicy.setHeightForWidth(comboCloseType->sizePolicy().hasHeightForWidth());
        comboCloseType->setSizePolicy(sizePolicy);
        comboCloseType->setMinimumSize(QSize(90, 30));
        comboCloseType->setMaximumSize(QSize(90, 16777215));
        comboCloseType->setFont(font);
        comboCloseType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboCloseType->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label_36 = new QLabel(groupParam_14);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(22, 96, 83, 19));
        label_36->setFont(font);
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinCloseIterations = new QSpinBox(groupParam_14);
        spinCloseIterations->setObjectName(QString::fromUtf8("spinCloseIterations"));
        spinCloseIterations->setGeometry(QRect(102, 94, 70, 27));
        spinCloseIterations->setFont(font4);
        spinCloseIterations->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinCloseIterations->setAlignment(Qt::AlignCenter);
        spinCloseIterations->setMinimum(1);
        spinCloseIterations->setMaximum(100);
        spinCloseIterations->setSingleStep(1);
        spinCloseIterations->setValue(1);
        stackedWidget->addWidget(page_15);
        page_16 = new QWidget();
        page_16->setObjectName(QString::fromUtf8("page_16"));
        groupParam_15 = new QGroupBox(page_16);
        groupParam_15->setObjectName(QString::fromUtf8("groupParam_15"));
        groupParam_15->setGeometry(QRect(6, 10, 427, 417));
        groupParam_15->setFont(font);
        groupParam_15->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnTophatBack = new QPushButton(groupParam_15);
        btnTophatBack->setObjectName(QString::fromUtf8("btnTophatBack"));
        btnTophatBack->setGeometry(QRect(352, 376, 70, 35));
        btnTophatBack->setMinimumSize(QSize(70, 30));
        btnTophatBack->setFont(font3);
        btnTophatBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_37 = new QLabel(groupParam_15);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(22, 48, 119, 19));
        label_37->setFont(font);
        label_37->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinTophatSize = new QSpinBox(groupParam_15);
        spinTophatSize->setObjectName(QString::fromUtf8("spinTophatSize"));
        spinTophatSize->setGeometry(QRect(136, 45, 70, 27));
        spinTophatSize->setFont(font4);
        spinTophatSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinTophatSize->setAlignment(Qt::AlignCenter);
        spinTophatSize->setMinimum(1);
        spinTophatSize->setMaximum(101);
        spinTophatSize->setSingleStep(1);
        spinTophatSize->setValue(9);
        label_38 = new QLabel(groupParam_15);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(232, 48, 79, 19));
        label_38->setFont(font);
        label_38->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboTophatType = new QComboBox(groupParam_15);
        comboTophatType->addItem(QString());
        comboTophatType->addItem(QString());
        comboTophatType->addItem(QString());
        comboTophatType->setObjectName(QString::fromUtf8("comboTophatType"));
        comboTophatType->setGeometry(QRect(314, 43, 90, 30));
        sizePolicy.setHeightForWidth(comboTophatType->sizePolicy().hasHeightForWidth());
        comboTophatType->setSizePolicy(sizePolicy);
        comboTophatType->setMinimumSize(QSize(90, 30));
        comboTophatType->setMaximumSize(QSize(90, 16777215));
        comboTophatType->setFont(font);
        comboTophatType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboTophatType->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label_39 = new QLabel(groupParam_15);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(22, 96, 83, 19));
        label_39->setFont(font);
        label_39->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinTophatIterations = new QSpinBox(groupParam_15);
        spinTophatIterations->setObjectName(QString::fromUtf8("spinTophatIterations"));
        spinTophatIterations->setGeometry(QRect(102, 94, 70, 27));
        spinTophatIterations->setFont(font4);
        spinTophatIterations->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinTophatIterations->setAlignment(Qt::AlignCenter);
        spinTophatIterations->setMinimum(1);
        spinTophatIterations->setMaximum(100);
        spinTophatIterations->setSingleStep(1);
        spinTophatIterations->setValue(1);
        stackedWidget->addWidget(page_16);
        page_17 = new QWidget();
        page_17->setObjectName(QString::fromUtf8("page_17"));
        groupParam_16 = new QGroupBox(page_17);
        groupParam_16->setObjectName(QString::fromUtf8("groupParam_16"));
        groupParam_16->setGeometry(QRect(6, 10, 427, 417));
        groupParam_16->setFont(font);
        groupParam_16->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnBlackhatBack = new QPushButton(groupParam_16);
        btnBlackhatBack->setObjectName(QString::fromUtf8("btnBlackhatBack"));
        btnBlackhatBack->setGeometry(QRect(352, 376, 70, 35));
        btnBlackhatBack->setMinimumSize(QSize(70, 30));
        btnBlackhatBack->setFont(font3);
        btnBlackhatBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_40 = new QLabel(groupParam_16);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(22, 48, 115, 19));
        label_40->setFont(font);
        label_40->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinBlackhatSize = new QSpinBox(groupParam_16);
        spinBlackhatSize->setObjectName(QString::fromUtf8("spinBlackhatSize"));
        spinBlackhatSize->setGeometry(QRect(136, 45, 70, 27));
        spinBlackhatSize->setFont(font4);
        spinBlackhatSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinBlackhatSize->setAlignment(Qt::AlignCenter);
        spinBlackhatSize->setMinimum(1);
        spinBlackhatSize->setMaximum(101);
        spinBlackhatSize->setSingleStep(1);
        spinBlackhatSize->setValue(9);
        label_41 = new QLabel(groupParam_16);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(232, 48, 79, 19));
        label_41->setFont(font);
        label_41->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboBlackhatType = new QComboBox(groupParam_16);
        comboBlackhatType->addItem(QString());
        comboBlackhatType->addItem(QString());
        comboBlackhatType->addItem(QString());
        comboBlackhatType->setObjectName(QString::fromUtf8("comboBlackhatType"));
        comboBlackhatType->setGeometry(QRect(314, 43, 90, 30));
        sizePolicy.setHeightForWidth(comboBlackhatType->sizePolicy().hasHeightForWidth());
        comboBlackhatType->setSizePolicy(sizePolicy);
        comboBlackhatType->setMinimumSize(QSize(90, 30));
        comboBlackhatType->setMaximumSize(QSize(90, 16777215));
        comboBlackhatType->setFont(font);
        comboBlackhatType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboBlackhatType->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label_42 = new QLabel(groupParam_16);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(22, 96, 83, 19));
        label_42->setFont(font);
        label_42->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinBlackhatIterations = new QSpinBox(groupParam_16);
        spinBlackhatIterations->setObjectName(QString::fromUtf8("spinBlackhatIterations"));
        spinBlackhatIterations->setGeometry(QRect(102, 94, 70, 27));
        spinBlackhatIterations->setFont(font4);
        spinBlackhatIterations->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinBlackhatIterations->setAlignment(Qt::AlignCenter);
        spinBlackhatIterations->setMinimum(1);
        spinBlackhatIterations->setMaximum(100);
        spinBlackhatIterations->setSingleStep(1);
        spinBlackhatIterations->setValue(1);
        stackedWidget->addWidget(page_17);
        page_18 = new QWidget();
        page_18->setObjectName(QString::fromUtf8("page_18"));
        groupParam_17 = new QGroupBox(page_18);
        groupParam_17->setObjectName(QString::fromUtf8("groupParam_17"));
        groupParam_17->setGeometry(QRect(6, 10, 427, 417));
        groupParam_17->setFont(font);
        groupParam_17->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnGradientBack = new QPushButton(groupParam_17);
        btnGradientBack->setObjectName(QString::fromUtf8("btnGradientBack"));
        btnGradientBack->setGeometry(QRect(352, 376, 70, 35));
        btnGradientBack->setMinimumSize(QSize(70, 30));
        btnGradientBack->setFont(font3);
        btnGradientBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_43 = new QLabel(groupParam_17);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(22, 48, 113, 19));
        label_43->setFont(font);
        label_43->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinGradientSize = new QSpinBox(groupParam_17);
        spinGradientSize->setObjectName(QString::fromUtf8("spinGradientSize"));
        spinGradientSize->setGeometry(QRect(136, 45, 70, 27));
        spinGradientSize->setFont(font4);
        spinGradientSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinGradientSize->setAlignment(Qt::AlignCenter);
        spinGradientSize->setMinimum(1);
        spinGradientSize->setMaximum(101);
        spinGradientSize->setSingleStep(1);
        spinGradientSize->setValue(9);
        label_44 = new QLabel(groupParam_17);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(232, 48, 79, 19));
        label_44->setFont(font);
        label_44->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboGradientType = new QComboBox(groupParam_17);
        comboGradientType->addItem(QString());
        comboGradientType->addItem(QString());
        comboGradientType->addItem(QString());
        comboGradientType->setObjectName(QString::fromUtf8("comboGradientType"));
        comboGradientType->setGeometry(QRect(314, 43, 90, 30));
        sizePolicy.setHeightForWidth(comboGradientType->sizePolicy().hasHeightForWidth());
        comboGradientType->setSizePolicy(sizePolicy);
        comboGradientType->setMinimumSize(QSize(90, 30));
        comboGradientType->setMaximumSize(QSize(90, 16777215));
        comboGradientType->setFont(font);
        comboGradientType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboGradientType->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label_45 = new QLabel(groupParam_17);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(22, 96, 83, 19));
        label_45->setFont(font);
        label_45->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinGradientIterations = new QSpinBox(groupParam_17);
        spinGradientIterations->setObjectName(QString::fromUtf8("spinGradientIterations"));
        spinGradientIterations->setGeometry(QRect(102, 94, 70, 27));
        spinGradientIterations->setFont(font4);
        spinGradientIterations->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinGradientIterations->setAlignment(Qt::AlignCenter);
        spinGradientIterations->setMinimum(1);
        spinGradientIterations->setMaximum(100);
        spinGradientIterations->setSingleStep(1);
        spinGradientIterations->setValue(1);
        stackedWidget->addWidget(page_18);
        page_19 = new QWidget();
        page_19->setObjectName(QString::fromUtf8("page_19"));
        groupParam_18 = new QGroupBox(page_19);
        groupParam_18->setObjectName(QString::fromUtf8("groupParam_18"));
        groupParam_18->setGeometry(QRect(6, 10, 427, 417));
        groupParam_18->setFont(font);
        groupParam_18->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnHitmissBack = new QPushButton(groupParam_18);
        btnHitmissBack->setObjectName(QString::fromUtf8("btnHitmissBack"));
        btnHitmissBack->setGeometry(QRect(352, 376, 70, 35));
        btnHitmissBack->setMinimumSize(QSize(70, 30));
        btnHitmissBack->setFont(font3);
        btnHitmissBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_46 = new QLabel(groupParam_18);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(22, 48, 115, 19));
        label_46->setFont(font);
        label_46->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinHitmissSize = new QSpinBox(groupParam_18);
        spinHitmissSize->setObjectName(QString::fromUtf8("spinHitmissSize"));
        spinHitmissSize->setGeometry(QRect(136, 45, 70, 27));
        spinHitmissSize->setFont(font4);
        spinHitmissSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinHitmissSize->setAlignment(Qt::AlignCenter);
        spinHitmissSize->setMinimum(1);
        spinHitmissSize->setMaximum(101);
        spinHitmissSize->setSingleStep(1);
        spinHitmissSize->setValue(9);
        label_47 = new QLabel(groupParam_18);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(232, 48, 79, 19));
        label_47->setFont(font);
        label_47->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboHitmissType = new QComboBox(groupParam_18);
        comboHitmissType->addItem(QString());
        comboHitmissType->addItem(QString());
        comboHitmissType->addItem(QString());
        comboHitmissType->setObjectName(QString::fromUtf8("comboHitmissType"));
        comboHitmissType->setGeometry(QRect(314, 43, 90, 30));
        sizePolicy.setHeightForWidth(comboHitmissType->sizePolicy().hasHeightForWidth());
        comboHitmissType->setSizePolicy(sizePolicy);
        comboHitmissType->setMinimumSize(QSize(90, 30));
        comboHitmissType->setMaximumSize(QSize(90, 16777215));
        comboHitmissType->setFont(font);
        comboHitmissType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboHitmissType->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label_48 = new QLabel(groupParam_18);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(22, 96, 83, 19));
        label_48->setFont(font);
        label_48->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinHitmissIterations = new QSpinBox(groupParam_18);
        spinHitmissIterations->setObjectName(QString::fromUtf8("spinHitmissIterations"));
        spinHitmissIterations->setGeometry(QRect(102, 94, 70, 27));
        spinHitmissIterations->setFont(font4);
        spinHitmissIterations->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinHitmissIterations->setAlignment(Qt::AlignCenter);
        spinHitmissIterations->setMinimum(1);
        spinHitmissIterations->setMaximum(100);
        spinHitmissIterations->setSingleStep(1);
        spinHitmissIterations->setValue(1);
        stackedWidget->addWidget(page_19);
        page_20 = new QWidget();
        page_20->setObjectName(QString::fromUtf8("page_20"));
        groupParam_19 = new QGroupBox(page_20);
        groupParam_19->setObjectName(QString::fromUtf8("groupParam_19"));
        groupParam_19->setGeometry(QRect(6, 10, 427, 417));
        groupParam_19->setFont(font);
        groupParam_19->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnLightBack = new QPushButton(groupParam_19);
        btnLightBack->setObjectName(QString::fromUtf8("btnLightBack"));
        btnLightBack->setGeometry(QRect(352, 376, 70, 35));
        btnLightBack->setMinimumSize(QSize(70, 30));
        btnLightBack->setFont(font3);
        btnLightBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_24 = new QLabel(groupParam_19);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(22, 48, 99, 19));
        label_24->setFont(font);
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinLightValue = new QSpinBox(groupParam_19);
        spinLightValue->setObjectName(QString::fromUtf8("spinLightValue"));
        spinLightValue->setGeometry(QRect(122, 44, 70, 27));
        spinLightValue->setFont(font4);
        spinLightValue->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinLightValue->setAlignment(Qt::AlignCenter);
        spinLightValue->setMinimum(-255);
        spinLightValue->setMaximum(255);
        spinLightValue->setSingleStep(1);
        spinLightValue->setValue(0);
        stackedWidget->addWidget(page_20);
        page_21 = new QWidget();
        page_21->setObjectName(QString::fromUtf8("page_21"));
        groupParam_20 = new QGroupBox(page_21);
        groupParam_20->setObjectName(QString::fromUtf8("groupParam_20"));
        groupParam_20->setGeometry(QRect(6, 10, 427, 417));
        groupParam_20->setFont(font);
        groupParam_20->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnLaplacianBack = new QPushButton(groupParam_20);
        btnLaplacianBack->setObjectName(QString::fromUtf8("btnLaplacianBack"));
        btnLaplacianBack->setGeometry(QRect(352, 376, 70, 35));
        btnLaplacianBack->setMinimumSize(QSize(70, 30));
        btnLaplacianBack->setFont(font3);
        btnLaplacianBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_49 = new QLabel(groupParam_20);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(22, 48, 145, 19));
        label_49->setFont(font);
        label_49->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinLaplacianKSize = new QSpinBox(groupParam_20);
        spinLaplacianKSize->setObjectName(QString::fromUtf8("spinLaplacianKSize"));
        spinLaplacianKSize->setGeometry(QRect(166, 44, 70, 27));
        spinLaplacianKSize->setFont(font4);
        spinLaplacianKSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinLaplacianKSize->setAlignment(Qt::AlignCenter);
        spinLaplacianKSize->setMinimum(1);
        spinLaplacianKSize->setMaximum(101);
        spinLaplacianKSize->setSingleStep(1);
        spinLaplacianKSize->setValue(9);
        stackedWidget->addWidget(page_21);
        page_22 = new QWidget();
        page_22->setObjectName(QString::fromUtf8("page_22"));
        groupParam_21 = new QGroupBox(page_22);
        groupParam_21->setObjectName(QString::fromUtf8("groupParam_21"));
        groupParam_21->setGeometry(QRect(6, 10, 427, 417));
        groupParam_21->setFont(font);
        groupParam_21->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnContrastBack = new QPushButton(groupParam_21);
        btnContrastBack->setObjectName(QString::fromUtf8("btnContrastBack"));
        btnContrastBack->setGeometry(QRect(352, 376, 70, 35));
        btnContrastBack->setMinimumSize(QSize(70, 30));
        btnContrastBack->setFont(font3);
        btnContrastBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_50 = new QLabel(groupParam_21);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(22, 48, 117, 19));
        label_50->setFont(font);
        label_50->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinContrastValue = new QSpinBox(groupParam_21);
        spinContrastValue->setObjectName(QString::fromUtf8("spinContrastValue"));
        spinContrastValue->setGeometry(QRect(140, 44, 70, 27));
        spinContrastValue->setFont(font4);
        spinContrastValue->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinContrastValue->setAlignment(Qt::AlignCenter);
        spinContrastValue->setMinimum(-255);
        spinContrastValue->setMaximum(255);
        spinContrastValue->setSingleStep(1);
        spinContrastValue->setValue(1);
        stackedWidget->addWidget(page_22);
        page_23 = new QWidget();
        page_23->setObjectName(QString::fromUtf8("page_23"));
        groupParam_22 = new QGroupBox(page_23);
        groupParam_22->setObjectName(QString::fromUtf8("groupParam_22"));
        groupParam_22->setGeometry(QRect(6, 10, 427, 417));
        groupParam_22->setFont(font);
        groupParam_22->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnGammaBack = new QPushButton(groupParam_22);
        btnGammaBack->setObjectName(QString::fromUtf8("btnGammaBack"));
        btnGammaBack->setGeometry(QRect(352, 376, 70, 35));
        btnGammaBack->setMinimumSize(QSize(70, 30));
        btnGammaBack->setFont(font3);
        btnGammaBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_51 = new QLabel(groupParam_22);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(22, 48, 99, 19));
        label_51->setFont(font);
        label_51->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinGammaValue = new QDoubleSpinBox(groupParam_22);
        spinGammaValue->setObjectName(QString::fromUtf8("spinGammaValue"));
        spinGammaValue->setGeometry(QRect(122, 44, 85, 27));
        spinGammaValue->setFont(font4);
        spinGammaValue->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinGammaValue->setAlignment(Qt::AlignCenter);
        spinGammaValue->setMaximum(255.000000000000000);
        spinGammaValue->setSingleStep(0.100000000000000);
        spinGammaValue->setValue(1.000000000000000);
        stackedWidget->addWidget(page_23);
        page_24 = new QWidget();
        page_24->setObjectName(QString::fromUtf8("page_24"));
        groupParam_23 = new QGroupBox(page_24);
        groupParam_23->setObjectName(QString::fromUtf8("groupParam_23"));
        groupParam_23->setGeometry(QRect(6, 10, 427, 417));
        groupParam_23->setFont(font);
        groupParam_23->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnMulBack = new QPushButton(groupParam_23);
        btnMulBack->setObjectName(QString::fromUtf8("btnMulBack"));
        btnMulBack->setGeometry(QRect(352, 376, 70, 35));
        btnMulBack->setMinimumSize(QSize(70, 30));
        btnMulBack->setFont(font3);
        btnMulBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_52 = new QLabel(groupParam_23);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(22, 48, 83, 19));
        label_52->setFont(font);
        label_52->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMulValue = new QDoubleSpinBox(groupParam_23);
        spinMulValue->setObjectName(QString::fromUtf8("spinMulValue"));
        spinMulValue->setGeometry(QRect(106, 44, 85, 27));
        spinMulValue->setFont(font4);
        spinMulValue->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMulValue->setAlignment(Qt::AlignCenter);
        spinMulValue->setDecimals(3);
        spinMulValue->setMaximum(21.000000000000000);
        spinMulValue->setSingleStep(0.010000000000000);
        spinMulValue->setValue(0.001000000000000);
        stackedWidget->addWidget(page_24);
        page_25 = new QWidget();
        page_25->setObjectName(QString::fromUtf8("page_25"));
        groupParam_24 = new QGroupBox(page_25);
        groupParam_24->setObjectName(QString::fromUtf8("groupParam_24"));
        groupParam_24->setGeometry(QRect(6, 10, 427, 417));
        groupParam_24->setFont(font);
        groupParam_24->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnEmphasizeBack = new QPushButton(groupParam_24);
        btnEmphasizeBack->setObjectName(QString::fromUtf8("btnEmphasizeBack"));
        btnEmphasizeBack->setGeometry(QRect(352, 376, 70, 35));
        btnEmphasizeBack->setMinimumSize(QSize(70, 30));
        btnEmphasizeBack->setFont(font3);
        btnEmphasizeBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_53 = new QLabel(groupParam_24);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(22, 48, 131, 19));
        label_53->setFont(font);
        label_53->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinEmphasizeKSize = new QSpinBox(groupParam_24);
        spinEmphasizeKSize->setObjectName(QString::fromUtf8("spinEmphasizeKSize"));
        spinEmphasizeKSize->setGeometry(QRect(154, 44, 70, 27));
        spinEmphasizeKSize->setFont(font4);
        spinEmphasizeKSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinEmphasizeKSize->setAlignment(Qt::AlignCenter);
        spinEmphasizeKSize->setMinimum(1);
        spinEmphasizeKSize->setMaximum(101);
        spinEmphasizeKSize->setSingleStep(1);
        spinEmphasizeKSize->setValue(9);
        label_54 = new QLabel(groupParam_24);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(242, 48, 99, 19));
        label_54->setFont(font);
        label_54->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinEmphasizeValue = new QDoubleSpinBox(groupParam_24);
        spinEmphasizeValue->setObjectName(QString::fromUtf8("spinEmphasizeValue"));
        spinEmphasizeValue->setGeometry(QRect(340, 44, 70, 27));
        spinEmphasizeValue->setFont(font4);
        spinEmphasizeValue->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinEmphasizeValue->setAlignment(Qt::AlignCenter);
        spinEmphasizeValue->setDecimals(1);
        spinEmphasizeValue->setMaximum(20.000000000000000);
        spinEmphasizeValue->setSingleStep(0.100000000000000);
        spinEmphasizeValue->setValue(1.000000000000000);
        stackedWidget->addWidget(page_25);
        page_26 = new QWidget();
        page_26->setObjectName(QString::fromUtf8("page_26"));
        groupParam_25 = new QGroupBox(page_26);
        groupParam_25->setObjectName(QString::fromUtf8("groupParam_25"));
        groupParam_25->setGeometry(QRect(6, 10, 427, 417));
        groupParam_25->setFont(font);
        groupParam_25->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnUnevenLightBack = new QPushButton(groupParam_25);
        btnUnevenLightBack->setObjectName(QString::fromUtf8("btnUnevenLightBack"));
        btnUnevenLightBack->setGeometry(QRect(352, 376, 70, 35));
        btnUnevenLightBack->setMinimumSize(QSize(70, 30));
        btnUnevenLightBack->setFont(font3);
        btnUnevenLightBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label_55 = new QLabel(groupParam_25);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(22, 48, 131, 19));
        label_55->setFont(font);
        label_55->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinUnevenLightSize = new QSpinBox(groupParam_25);
        spinUnevenLightSize->setObjectName(QString::fromUtf8("spinUnevenLightSize"));
        spinUnevenLightSize->setGeometry(QRect(156, 44, 70, 27));
        spinUnevenLightSize->setFont(font4);
        spinUnevenLightSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinUnevenLightSize->setAlignment(Qt::AlignCenter);
        spinUnevenLightSize->setMinimum(1);
        spinUnevenLightSize->setMaximum(255);
        spinUnevenLightSize->setSingleStep(1);
        spinUnevenLightSize->setValue(32);
        stackedWidget->addWidget(page_26);
        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        groupCamera_9 = new QGroupBox(tab_4);
        groupCamera_9->setObjectName(QString::fromUtf8("groupCamera_9"));
        groupCamera_9->setGeometry(QRect(9, 18, 427, 73));
        groupCamera_9->setFont(font);
        groupCamera_9->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        checkUseROI = new QCheckBox(groupCamera_9);
        checkUseROI->setObjectName(QString::fromUtf8("checkUseROI"));
        checkUseROI->setGeometry(QRect(13, 37, 93, 27));
        sizePolicy.setHeightForWidth(checkUseROI->sizePolicy().hasHeightForWidth());
        checkUseROI->setSizePolicy(sizePolicy);
        checkUseROI->setFont(font);
        checkUseROI->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 17px;\n"
"    height: 17px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkUseROI->setIconSize(QSize(22, 22));
        comboROIShape = new QComboBox(groupCamera_9);
        comboROIShape->addItem(QString());
        comboROIShape->addItem(QString());
        comboROIShape->addItem(QString());
        comboROIShape->addItem(QString());
        comboROIShape->setObjectName(QString::fromUtf8("comboROIShape"));
        comboROIShape->setGeometry(QRect(130, 35, 95, 30));
        comboROIShape->setFont(font);
        comboROIShape->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 5em;\n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        btnAddROI = new QPushButton(groupCamera_9);
        btnAddROI->setObjectName(QString::fromUtf8("btnAddROI"));
        btnAddROI->setGeometry(QRect(270, 34, 66, 32));
        sizePolicy.setHeightForWidth(btnAddROI->sizePolicy().hasHeightForWidth());
        btnAddROI->setSizePolicy(sizePolicy);
        btnAddROI->setMinimumSize(QSize(60, 30));
        btnAddROI->setFont(font1);
        btnAddROI->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));
        btnDeleteROI = new QPushButton(groupCamera_9);
        btnDeleteROI->setObjectName(QString::fromUtf8("btnDeleteROI"));
        btnDeleteROI->setGeometry(QRect(350, 34, 66, 32));
        btnDeleteROI->setMinimumSize(QSize(60, 30));
        btnDeleteROI->setFont(font1);
        btnDeleteROI->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));
        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(frmImageMorphologyClass);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmImageMorphologyClass);
    } // setupUi

    void retranslateUi(QDialog *frmImageMorphologyClass)
    {
        frmImageMorphologyClass->setWindowTitle(QCoreApplication::translate("frmImageMorphologyClass", "\351\242\204\345\244\204\347\220\206", nullptr));
        label_3->setText(QCoreApplication::translate("frmImageMorphologyClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmImageMorphologyClass", "\346\211\247\350\241\214", nullptr));
        groupC_3->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmImageMorphologyClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmImageMorphologyClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmImageMorphologyClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        groupC->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\351\242\204\345\244\204\347\220\206\345\217\202\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetType->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("frmImageMorphologyClass", "\351\242\204\345\244\204\347\220\206\351\241\271\347\233\256", nullptr));
        btnAddType->setText(QCoreApplication::translate("frmImageMorphologyClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteType->setText(QCoreApplication::translate("frmImageMorphologyClass", "\345\210\240\351\231\244", nullptr));
        btnMoveUp->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\347\247\273", nullptr));
        btnMoveDown->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\213\347\247\273", nullptr));
        label->setText(QCoreApplication::translate("frmImageMorphologyClass", "\351\242\204\345\244\204\347\220\206\347\261\273\345\236\213\357\274\232", nullptr));
        lblType->setText(QString());
#if QT_CONFIG(tooltip)
        btnMenu->setToolTip(QCoreApplication::translate("frmImageMorphologyClass", "\346\267\273\345\212\240\351\242\204\345\244\204\347\220\206", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMenu->setText(QString());
        checkRealTime->setText(QCoreApplication::translate("frmImageMorphologyClass", "\345\256\236\346\227\266", nullptr));
        groupParam_30->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\351\242\234\350\211\262\347\251\272\351\227\264\345\217\230\346\215\242\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnChannelBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_62->setText(QCoreApplication::translate("frmImageMorphologyClass", "\351\242\234\350\211\262\347\251\272\351\227\264\345\217\230\346\215\242\347\261\273\345\236\213\357\274\232", nullptr));
        comboChannel->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "BGR2HSV", nullptr));
        comboChannel->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "BGR2HLS", nullptr));
        comboChannel->setItemText(2, QCoreApplication::translate("frmImageMorphologyClass", "BGR2Lab", nullptr));
        comboChannel->setItemText(3, QCoreApplication::translate("frmImageMorphologyClass", "BGR2Luv", nullptr));
        comboChannel->setItemText(4, QCoreApplication::translate("frmImageMorphologyClass", "BGR2XYZ", nullptr));
        comboChannel->setItemText(5, QCoreApplication::translate("frmImageMorphologyClass", "BGR2YUV", nullptr));
        comboChannel->setItemText(6, QCoreApplication::translate("frmImageMorphologyClass", "BGR2YCrCb", nullptr));

        groupC_2->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\350\276\223\345\207\272\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        radioImage->setText(QCoreApplication::translate("frmImageMorphologyClass", "3\351\200\232\351\201\223\345\233\276\345\203\217", nullptr));
        radioImageC1->setText(QCoreApplication::translate("frmImageMorphologyClass", "\351\200\232\351\201\2231\345\233\276\345\203\217", nullptr));
        radioImageC2->setText(QCoreApplication::translate("frmImageMorphologyClass", "\351\200\232\351\201\2232\345\233\276\345\203\217", nullptr));
        radioImageC3->setText(QCoreApplication::translate("frmImageMorphologyClass", "\351\200\232\351\201\2233\345\233\276\345\203\217", nullptr));
        groupParam_26->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "fill_up\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnFillUpBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_58->setText(QCoreApplication::translate("frmImageMorphologyClass", "\351\273\221\347\231\275\350\211\262\351\200\211\346\213\251\357\274\232", nullptr));
        comboFillUp->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "WHITE", nullptr));
        comboFillUp->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "BLACK", nullptr));

        groupParam_27->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "shape_trans\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnShapeTransBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_59->setText(QCoreApplication::translate("frmImageMorphologyClass", "\345\275\242\347\212\266\347\261\273\345\236\213\357\274\232", nullptr));
        comboShapeTrans->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "RECTANGLE", nullptr));
        comboShapeTrans->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "CIRCLE", nullptr));
        comboShapeTrans->setItemText(2, QCoreApplication::translate("frmImageMorphologyClass", "CONVER", nullptr));

        comboSTColor->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "WHITE", nullptr));
        comboSTColor->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "BLACK", nullptr));

        label_60->setText(QCoreApplication::translate("frmImageMorphologyClass", "\351\273\221\347\231\275\350\211\262\351\200\211\346\213\251\357\274\232", nullptr));
        groupParam->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\345\233\272\345\256\232\351\230\210\345\200\274\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_7->setText(QCoreApplication::translate("frmImageMorphologyClass", "\346\234\200\345\260\217\351\230\210\345\200\274\357\274\232", nullptr));
        btnThresholdBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_8->setText(QCoreApplication::translate("frmImageMorphologyClass", "\346\234\200\345\244\247\351\230\210\345\200\274\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("frmImageMorphologyClass", "\351\230\210\345\200\274\347\261\273\345\236\213\357\274\232", nullptr));
        comboThreshold->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "THRESH_BINARY", nullptr));
        comboThreshold->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "THRESH_BINARY_INV", nullptr));
        comboThreshold->setItemText(2, QCoreApplication::translate("frmImageMorphologyClass", "THRESH_TOZERO", nullptr));
        comboThreshold->setItemText(3, QCoreApplication::translate("frmImageMorphologyClass", "THRESH_TOZERO_INV", nullptr));
        comboThreshold->setItemText(4, QCoreApplication::translate("frmImageMorphologyClass", "THRESH_TRUNC", nullptr));
        comboThreshold->setItemText(5, QCoreApplication::translate("frmImageMorphologyClass", "THRESH_OTSU", nullptr));
        comboThreshold->setItemText(6, QCoreApplication::translate("frmImageMorphologyClass", "THRESH_TRIANGLE", nullptr));

        groupParam_28->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "threshold\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_56->setText(QCoreApplication::translate("frmImageMorphologyClass", "\346\234\200\345\260\217\351\230\210\345\200\274\357\274\232", nullptr));
        btnThreshBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_57->setText(QCoreApplication::translate("frmImageMorphologyClass", "\346\234\200\345\244\247\351\230\210\345\200\274\357\274\232", nullptr));
        groupParam_2->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "dyn_threshold\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_10->setText(QCoreApplication::translate("frmImageMorphologyClass", "\345\201\217\347\247\273\351\207\217\357\274\232", nullptr));
        btnAdaptiveBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_11->setText(QCoreApplication::translate("frmImageMorphologyClass", "\345\235\207\345\200\274\346\273\244\346\263\242\346\240\270\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinAdaptiveKSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_12->setText(QCoreApplication::translate("frmImageMorphologyClass", "\346\217\220\345\217\226\345\214\272\345\237\237\347\261\273\345\236\213\357\274\232", nullptr));
        comboAdaptiveType->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "LIGHT", nullptr));
        comboAdaptiveType->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "DARK", nullptr));
        comboAdaptiveType->setItemText(2, QCoreApplication::translate("frmImageMorphologyClass", "EQUAL", nullptr));
        comboAdaptiveType->setItemText(3, QCoreApplication::translate("frmImageMorphologyClass", "NOT_EQUAL", nullptr));

        groupParam_3->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\345\235\207\345\200\274\346\273\244\346\263\242\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnBlurBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_14->setText(QCoreApplication::translate("frmImageMorphologyClass", "\345\235\207\345\200\274\346\273\244\346\263\242\346\240\270\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinBlurKSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_4->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\255\345\200\274\346\273\244\346\263\242\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnMedianBlurBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_15->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\255\345\200\274\346\273\244\346\263\242\346\240\270\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinMedianBlurKSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_5->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\351\253\230\346\226\257\346\273\244\346\263\242\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnGaussianBlurBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_16->setText(QCoreApplication::translate("frmImageMorphologyClass", "\351\253\230\346\226\257\346\273\244\346\263\242\346\240\270\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinGaussianBlurKSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_6->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\345\217\214\350\276\271\346\273\244\346\263\242\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnBilateralBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_17->setText(QCoreApplication::translate("frmImageMorphologyClass", "\345\220\204\345\203\217\347\264\240\351\202\273\345\237\237\347\233\264\345\276\204\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinBilateralDSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_18->setText(QCoreApplication::translate("frmImageMorphologyClass", "sigma\345\200\274\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinBilateralSigma->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_7->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\346\226\271\346\241\206\346\273\244\346\263\242\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnBoxBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_19->setText(QCoreApplication::translate("frmImageMorphologyClass", "\346\226\271\346\241\206\346\273\244\346\263\242\346\240\270\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxKSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_8->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "sobel\346\273\244\346\263\242\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnSobelBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_20->setText(QCoreApplication::translate("frmImageMorphologyClass", "sobel\346\273\244\346\263\242\346\240\270\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinSobelKSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_9->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "canny\346\273\244\346\263\242\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_13->setText(QCoreApplication::translate("frmImageMorphologyClass", "\346\234\200\345\260\217\351\230\210\345\200\274\357\274\232", nullptr));
        btnCannyBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_21->setText(QCoreApplication::translate("frmImageMorphologyClass", "\346\234\200\345\244\247\351\230\210\345\200\274\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinCannyKSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_23->setText(QCoreApplication::translate("frmImageMorphologyClass", "canny\346\273\244\346\263\242\346\240\270\345\244\247\345\260\217\357\274\232", nullptr));
        groupParam_10->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "laplace\346\273\244\346\263\242\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnLaplaceBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_22->setText(QCoreApplication::translate("frmImageMorphologyClass", "laplace\346\273\244\346\263\242\346\240\270\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinLaplaceKSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_11->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\350\205\220\350\232\200\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnErodeBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_25->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\345\205\203\347\264\240\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinErodeSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_26->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\347\261\273\345\236\213\357\274\232", nullptr));
        comboErodeType->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "RECT", nullptr));
        comboErodeType->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "CROSS", nullptr));
        comboErodeType->setItemText(2, QCoreApplication::translate("frmImageMorphologyClass", "ELLIPSE", nullptr));

        label_27->setText(QCoreApplication::translate("frmImageMorphologyClass", "\350\277\255\344\273\243\346\254\241\346\225\260\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinErodeIterations->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_12->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\350\206\250\350\203\200\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnDilateBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_28->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\345\205\203\347\264\240\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinDilateSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_29->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\347\261\273\345\236\213\357\274\232", nullptr));
        comboDilateType->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "RECT", nullptr));
        comboDilateType->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "CROSS", nullptr));
        comboDilateType->setItemText(2, QCoreApplication::translate("frmImageMorphologyClass", "ELLIPSE", nullptr));

        label_30->setText(QCoreApplication::translate("frmImageMorphologyClass", "\350\277\255\344\273\243\346\254\241\346\225\260\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinDilateIterations->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_13->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\345\274\200\350\277\220\347\256\227\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnOpenBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_31->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\345\205\203\347\264\240\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinOpenSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_32->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\347\261\273\345\236\213\357\274\232", nullptr));
        comboOpenType->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "RECT", nullptr));
        comboOpenType->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "CROSS", nullptr));
        comboOpenType->setItemText(2, QCoreApplication::translate("frmImageMorphologyClass", "ELLIPSE", nullptr));

        label_33->setText(QCoreApplication::translate("frmImageMorphologyClass", "\350\277\255\344\273\243\346\254\241\346\225\260\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinOpenIterations->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_14->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\351\227\255\350\277\220\347\256\227\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnCloseBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_34->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\345\205\203\347\264\240\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinCloseSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_35->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\347\261\273\345\236\213\357\274\232", nullptr));
        comboCloseType->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "RECT", nullptr));
        comboCloseType->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "CROSS", nullptr));
        comboCloseType->setItemText(2, QCoreApplication::translate("frmImageMorphologyClass", "ELLIPSE", nullptr));

        label_36->setText(QCoreApplication::translate("frmImageMorphologyClass", "\350\277\255\344\273\243\346\254\241\346\225\260\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinCloseIterations->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_15->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\351\241\266\345\270\275\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnTophatBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_37->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\345\205\203\347\264\240\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinTophatSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_38->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\347\261\273\345\236\213\357\274\232", nullptr));
        comboTophatType->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "RECT", nullptr));
        comboTophatType->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "CROSS", nullptr));
        comboTophatType->setItemText(2, QCoreApplication::translate("frmImageMorphologyClass", "ELLIPSE", nullptr));

        label_39->setText(QCoreApplication::translate("frmImageMorphologyClass", "\350\277\255\344\273\243\346\254\241\346\225\260\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinTophatIterations->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_16->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\351\273\221\345\270\275\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnBlackhatBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_40->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\345\205\203\347\264\240\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinBlackhatSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_41->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\347\261\273\345\236\213\357\274\232", nullptr));
        comboBlackhatType->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "RECT", nullptr));
        comboBlackhatType->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "CROSS", nullptr));
        comboBlackhatType->setItemText(2, QCoreApplication::translate("frmImageMorphologyClass", "ELLIPSE", nullptr));

        label_42->setText(QCoreApplication::translate("frmImageMorphologyClass", "\350\277\255\344\273\243\346\254\241\346\225\260\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinBlackhatIterations->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_17->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\346\242\257\345\272\246\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnGradientBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_43->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\345\205\203\347\264\240\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinGradientSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_44->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\347\261\273\345\236\213\357\274\232", nullptr));
        comboGradientType->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "RECT", nullptr));
        comboGradientType->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "CROSS", nullptr));
        comboGradientType->setItemText(2, QCoreApplication::translate("frmImageMorphologyClass", "ELLIPSE", nullptr));

        label_45->setText(QCoreApplication::translate("frmImageMorphologyClass", "\350\277\255\344\273\243\346\254\241\346\225\260\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinGradientIterations->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_18->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\345\207\273\344\270\255/\345\207\273\344\270\215\344\270\255\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnHitmissBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_46->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\345\205\203\347\264\240\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinHitmissSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_47->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\273\223\346\236\204\347\261\273\345\236\213\357\274\232", nullptr));
        comboHitmissType->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "RECT", nullptr));
        comboHitmissType->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "CROSS", nullptr));
        comboHitmissType->setItemText(2, QCoreApplication::translate("frmImageMorphologyClass", "ELLIPSE", nullptr));

        label_48->setText(QCoreApplication::translate("frmImageMorphologyClass", "\350\277\255\344\273\243\346\254\241\346\225\260\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinHitmissIterations->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_19->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\344\272\256\345\272\246\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnLightBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_24->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\272\256\345\272\246\345\242\236\347\233\212\345\200\274\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinLightValue->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_20->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\351\224\220\345\214\226\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnLaplacianBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_49->setText(QCoreApplication::translate("frmImageMorphologyClass", "laplacian\346\240\270\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinLaplacianKSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_21->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\345\257\271\346\257\224\345\272\246\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnContrastBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_50->setText(QCoreApplication::translate("frmImageMorphologyClass", "\345\257\271\346\257\224\345\272\246\345\242\236\347\233\212\345\200\274\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinContrastValue->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        groupParam_22->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\344\274\275\351\251\254\346\240\241\346\255\243\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnGammaBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_51->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\274\275\351\251\254\346\240\241\346\255\243\345\200\274\357\274\232", nullptr));
        groupParam_23->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\345\233\276\345\203\217\347\233\270\344\271\230\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnMulBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_52->setText(QCoreApplication::translate("frmImageMorphologyClass", "\347\233\270\344\271\230\347\263\273\346\225\260\357\274\232", nullptr));
        groupParam_24->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "emphasize\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnEmphasizeBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_53->setText(QCoreApplication::translate("frmImageMorphologyClass", "\345\235\207\345\200\274\346\273\244\346\263\242\346\240\270\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinEmphasizeKSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_54->setText(QCoreApplication::translate("frmImageMorphologyClass", "\345\257\271\346\257\224\345\272\246\345\233\240\345\255\220\357\274\232", nullptr));
        groupParam_25->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\215\345\235\207\345\214\200\345\205\211\347\205\247\350\241\245\345\201\277\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnUnevenLightBack->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label_55->setText(QCoreApplication::translate("frmImageMorphologyClass", "\345\205\211\347\205\247\350\241\245\345\201\277\345\235\227\345\244\247\345\260\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinUnevenLightSize->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmImageMorphologyClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        groupCamera_9->setTitle(QCoreApplication::translate("frmImageMorphologyClass", "ROI\345\257\271\350\261\241", nullptr));
        checkUseROI->setText(QCoreApplication::translate("frmImageMorphologyClass", "\344\275\277\347\224\250ROI", nullptr));
        comboROIShape->setItemText(0, QCoreApplication::translate("frmImageMorphologyClass", "\347\237\251\345\275\242", nullptr));
        comboROIShape->setItemText(1, QCoreApplication::translate("frmImageMorphologyClass", "\346\227\213\350\275\254\347\237\251\345\275\242", nullptr));
        comboROIShape->setItemText(2, QCoreApplication::translate("frmImageMorphologyClass", "\345\234\206\345\275\242", nullptr));
        comboROIShape->setItemText(3, QCoreApplication::translate("frmImageMorphologyClass", "\345\244\232\350\276\271\345\275\242", nullptr));

        btnAddROI->setText(QCoreApplication::translate("frmImageMorphologyClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteROI->setText(QCoreApplication::translate("frmImageMorphologyClass", "\345\210\240\351\231\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("frmImageMorphologyClass", "ROI\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmImageMorphologyClass: public Ui_frmImageMorphologyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMIMAGEMORPHOLOGY_H
