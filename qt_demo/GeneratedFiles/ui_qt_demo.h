/********************************************************************************
** Form generated from reading UI file 'qt_demo.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_DEMO_H
#define UI_QT_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_demoClass
{
public:
    QWidget *centralWidget;
    QComboBox *comboBox;
    QLabel *labelDev;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonArp;
    QPushButton *pushButtonIp;
    QPushButton *pushButtonUdp;
    QPushButton *pushButtonTcp;
    QPushButton *pushButtonIcmp;
    QPushButton *pushButtonHttp;
    QTableWidget *tableWidgetArp;
    QTableWidget *tableWidgetIp;
    QTableWidget *tableWidgetUdp;
    QTableWidget *tableWidgetTcp;
    QTableWidget *tableWidgetHttp;
    QTableWidget *tableWidgetIcmp;
    QLabel *labelStatus;
    QLabel *labelProtoType;
    QLabel *labelPacket;
    QLabel *labelPacketNum;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qt_demoClass)
    {
        if (qt_demoClass->objectName().isEmpty())
            qt_demoClass->setObjectName(QStringLiteral("qt_demoClass"));
        qt_demoClass->resize(927, 591);
        centralWidget = new QWidget(qt_demoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(70, 10, 601, 22));
        labelDev = new QLabel(centralWidget);
        labelDev->setObjectName(QStringLiteral("labelDev"));
        labelDev->setGeometry(QRect(10, 10, 51, 20));
        pushButtonStart = new QPushButton(centralWidget);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));
        pushButtonStart->setGeometry(QRect(700, 10, 51, 23));
        pushButtonStop = new QPushButton(centralWidget);
        pushButtonStop->setObjectName(QStringLiteral("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(780, 10, 51, 23));
        pushButtonArp = new QPushButton(centralWidget);
        pushButtonArp->setObjectName(QStringLiteral("pushButtonArp"));
        pushButtonArp->setGeometry(QRect(70, 40, 75, 23));
        pushButtonIp = new QPushButton(centralWidget);
        pushButtonIp->setObjectName(QStringLiteral("pushButtonIp"));
        pushButtonIp->setGeometry(QRect(160, 40, 75, 23));
        pushButtonUdp = new QPushButton(centralWidget);
        pushButtonUdp->setObjectName(QStringLiteral("pushButtonUdp"));
        pushButtonUdp->setGeometry(QRect(250, 40, 75, 23));
        pushButtonTcp = new QPushButton(centralWidget);
        pushButtonTcp->setObjectName(QStringLiteral("pushButtonTcp"));
        pushButtonTcp->setGeometry(QRect(340, 40, 75, 23));
        pushButtonIcmp = new QPushButton(centralWidget);
        pushButtonIcmp->setObjectName(QStringLiteral("pushButtonIcmp"));
        pushButtonIcmp->setGeometry(QRect(520, 40, 75, 23));
        pushButtonHttp = new QPushButton(centralWidget);
        pushButtonHttp->setObjectName(QStringLiteral("pushButtonHttp"));
        pushButtonHttp->setGeometry(QRect(430, 40, 75, 23));
        tableWidgetArp = new QTableWidget(centralWidget);
        if (tableWidgetArp->columnCount() < 9)
            tableWidgetArp->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetArp->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetArp->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetArp->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetArp->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetArp->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetArp->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetArp->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetArp->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetArp->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableWidgetArp->setObjectName(QStringLiteral("tableWidgetArp"));
        tableWidgetArp->setEnabled(true);
        tableWidgetArp->setGeometry(QRect(10, 70, 901, 461));
        tableWidgetArp->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetIp = new QTableWidget(centralWidget);
        if (tableWidgetIp->columnCount() < 8)
            tableWidgetIp->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetIp->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetIp->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetIp->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidgetIp->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidgetIp->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidgetIp->setHorizontalHeaderItem(5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidgetIp->setHorizontalHeaderItem(6, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidgetIp->setHorizontalHeaderItem(7, __qtablewidgetitem16);
        tableWidgetIp->setObjectName(QStringLiteral("tableWidgetIp"));
        tableWidgetIp->setGeometry(QRect(10, 70, 901, 461));
        tableWidgetIp->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetUdp = new QTableWidget(centralWidget);
        if (tableWidgetUdp->columnCount() < 6)
            tableWidgetUdp->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidgetUdp->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidgetUdp->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidgetUdp->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidgetUdp->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidgetUdp->setHorizontalHeaderItem(4, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidgetUdp->setHorizontalHeaderItem(5, __qtablewidgetitem22);
        tableWidgetUdp->setObjectName(QStringLiteral("tableWidgetUdp"));
        tableWidgetUdp->setGeometry(QRect(10, 70, 901, 461));
        tableWidgetUdp->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetUdp->horizontalHeader()->setMinimumSectionSize(21);
        tableWidgetUdp->verticalHeader()->setDefaultSectionSize(30);
        tableWidgetTcp = new QTableWidget(centralWidget);
        if (tableWidgetTcp->columnCount() < 9)
            tableWidgetTcp->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidgetTcp->setHorizontalHeaderItem(0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidgetTcp->setHorizontalHeaderItem(1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidgetTcp->setHorizontalHeaderItem(2, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidgetTcp->setHorizontalHeaderItem(3, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidgetTcp->setHorizontalHeaderItem(4, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidgetTcp->setHorizontalHeaderItem(5, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidgetTcp->setHorizontalHeaderItem(6, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidgetTcp->setHorizontalHeaderItem(7, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidgetTcp->setHorizontalHeaderItem(8, __qtablewidgetitem31);
        tableWidgetTcp->setObjectName(QStringLiteral("tableWidgetTcp"));
        tableWidgetTcp->setGeometry(QRect(10, 70, 901, 461));
        tableWidgetTcp->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetHttp = new QTableWidget(centralWidget);
        if (tableWidgetHttp->columnCount() < 6)
            tableWidgetHttp->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidgetHttp->setHorizontalHeaderItem(0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidgetHttp->setHorizontalHeaderItem(1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidgetHttp->setHorizontalHeaderItem(2, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidgetHttp->setHorizontalHeaderItem(3, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidgetHttp->setHorizontalHeaderItem(4, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidgetHttp->setHorizontalHeaderItem(5, __qtablewidgetitem37);
        tableWidgetHttp->setObjectName(QStringLiteral("tableWidgetHttp"));
        tableWidgetHttp->setGeometry(QRect(10, 70, 901, 461));
        tableWidgetHttp->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetIcmp = new QTableWidget(centralWidget);
        if (tableWidgetIcmp->columnCount() < 4)
            tableWidgetIcmp->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidgetIcmp->setHorizontalHeaderItem(0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidgetIcmp->setHorizontalHeaderItem(1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidgetIcmp->setHorizontalHeaderItem(2, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidgetIcmp->setHorizontalHeaderItem(3, __qtablewidgetitem41);
        tableWidgetIcmp->setObjectName(QStringLiteral("tableWidgetIcmp"));
        tableWidgetIcmp->setGeometry(QRect(10, 70, 901, 461));
        tableWidgetIcmp->setEditTriggers(QAbstractItemView::NoEditTriggers);
        labelStatus = new QLabel(centralWidget);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));
        labelStatus->setGeometry(QRect(700, 40, 131, 21));
        labelStatus->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        labelProtoType = new QLabel(centralWidget);
        labelProtoType->setObjectName(QStringLiteral("labelProtoType"));
        labelProtoType->setGeometry(QRect(10, 40, 61, 20));
        labelPacket = new QLabel(centralWidget);
        labelPacket->setObjectName(QStringLiteral("labelPacket"));
        labelPacket->setGeometry(QRect(10, 540, 81, 16));
        labelPacketNum = new QLabel(centralWidget);
        labelPacketNum->setObjectName(QStringLiteral("labelPacketNum"));
        labelPacketNum->setGeometry(QRect(90, 540, 101, 16));
        qt_demoClass->setCentralWidget(centralWidget);
        comboBox->raise();
        labelDev->raise();
        pushButtonStart->raise();
        pushButtonStop->raise();
        pushButtonArp->raise();
        pushButtonIp->raise();
        pushButtonUdp->raise();
        pushButtonTcp->raise();
        pushButtonIcmp->raise();
        pushButtonHttp->raise();
        labelStatus->raise();
        labelProtoType->raise();
        labelPacket->raise();
        labelPacketNum->raise();
        tableWidgetArp->raise();
        tableWidgetHttp->raise();
        tableWidgetIcmp->raise();
        tableWidgetIp->raise();
        tableWidgetUdp->raise();
        tableWidgetTcp->raise();
        mainToolBar = new QToolBar(qt_demoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qt_demoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(qt_demoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qt_demoClass->setStatusBar(statusBar);

        retranslateUi(qt_demoClass);

        QMetaObject::connectSlotsByName(qt_demoClass);
    } // setupUi

    void retranslateUi(QMainWindow *qt_demoClass)
    {
        qt_demoClass->setWindowTitle(QApplication::translate("qt_demoClass", "\345\237\272\344\272\216\345\215\217\350\256\256\345\210\206\346\236\220\347\232\204\347\275\221\347\273\234\345\217\226\350\257\201\345\267\245\345\205\267", 0));
        labelDev->setText(QApplication::translate("qt_demoClass", "\347\275\221\345\215\241\346\216\245\345\217\243:", 0));
        pushButtonStart->setText(QApplication::translate("qt_demoClass", "\345\274\200\345\247\213", 0));
        pushButtonStop->setText(QApplication::translate("qt_demoClass", "\345\201\234\346\255\242", 0));
        pushButtonArp->setText(QApplication::translate("qt_demoClass", "ARP", 0));
        pushButtonIp->setText(QApplication::translate("qt_demoClass", "IPv4", 0));
        pushButtonUdp->setText(QApplication::translate("qt_demoClass", "UDP", 0));
        pushButtonTcp->setText(QApplication::translate("qt_demoClass", "TCP", 0));
        pushButtonIcmp->setText(QApplication::translate("qt_demoClass", "ICMP", 0));
        pushButtonHttp->setText(QApplication::translate("qt_demoClass", "HTTP", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetArp->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("qt_demoClass", "\347\241\254\344\273\266\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetArp->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("qt_demoClass", "\345\215\217\350\256\256\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetArp->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("qt_demoClass", "\347\241\254\344\273\266\351\225\277\345\272\246", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetArp->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("qt_demoClass", "\345\215\217\350\256\256\351\225\277\345\272\246", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetArp->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("qt_demoClass", "op", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetArp->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("qt_demoClass", "\346\272\220MAC", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetArp->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("qt_demoClass", "\346\272\220ip", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetArp->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("qt_demoClass", "\347\233\256\347\232\204MAC", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetArp->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("qt_demoClass", "\347\233\256\347\232\204ip", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetIp->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("qt_demoClass", "\346\272\220ip", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetIp->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("qt_demoClass", "\347\233\256\347\232\204ip", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetIp->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("qt_demoClass", "\346\234\215\345\212\241\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetIp->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QApplication::translate("qt_demoClass", "ip\346\212\245\346\226\207\351\225\277\345\272\246", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetIp->horizontalHeaderItem(4);
        ___qtablewidgetitem13->setText(QApplication::translate("qt_demoClass", "\346\240\207\350\257\206", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetIp->horizontalHeaderItem(5);
        ___qtablewidgetitem14->setText(QApplication::translate("qt_demoClass", "TTL", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidgetIp->horizontalHeaderItem(6);
        ___qtablewidgetitem15->setText(QApplication::translate("qt_demoClass", "\345\215\217\350\256\256", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidgetIp->horizontalHeaderItem(7);
        ___qtablewidgetitem16->setText(QApplication::translate("qt_demoClass", "\351\246\226\351\203\250\346\243\200\351\252\214\345\222\214", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidgetUdp->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QApplication::translate("qt_demoClass", "\346\272\220ip", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidgetUdp->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QApplication::translate("qt_demoClass", "\346\272\220\347\253\257\345\217\243", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidgetUdp->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QApplication::translate("qt_demoClass", "\347\233\256\347\232\204ip", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidgetUdp->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QApplication::translate("qt_demoClass", "\347\233\256\347\232\204\347\253\257\345\217\243", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidgetUdp->horizontalHeaderItem(4);
        ___qtablewidgetitem21->setText(QApplication::translate("qt_demoClass", "udp\346\212\245\346\226\207\351\225\277\345\272\246", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidgetUdp->horizontalHeaderItem(5);
        ___qtablewidgetitem22->setText(QApplication::translate("qt_demoClass", "udp\346\243\200\351\252\214\345\222\214", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidgetTcp->horizontalHeaderItem(0);
        ___qtablewidgetitem23->setText(QApplication::translate("qt_demoClass", "\346\272\220ip", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidgetTcp->horizontalHeaderItem(1);
        ___qtablewidgetitem24->setText(QApplication::translate("qt_demoClass", "\346\272\220\347\253\257\345\217\243", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidgetTcp->horizontalHeaderItem(2);
        ___qtablewidgetitem25->setText(QApplication::translate("qt_demoClass", "\347\233\256\347\232\204ip", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidgetTcp->horizontalHeaderItem(3);
        ___qtablewidgetitem26->setText(QApplication::translate("qt_demoClass", "\347\233\256\347\232\204\347\253\257\345\217\243", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidgetTcp->horizontalHeaderItem(4);
        ___qtablewidgetitem27->setText(QApplication::translate("qt_demoClass", "seq", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidgetTcp->horizontalHeaderItem(5);
        ___qtablewidgetitem28->setText(QApplication::translate("qt_demoClass", "ack", 0));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidgetTcp->horizontalHeaderItem(6);
        ___qtablewidgetitem29->setText(QApplication::translate("qt_demoClass", "\347\252\227\345\217\243\345\244\247\345\260\217", 0));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidgetTcp->horizontalHeaderItem(7);
        ___qtablewidgetitem30->setText(QApplication::translate("qt_demoClass", "tcp\346\243\200\351\252\214\345\222\214", 0));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidgetTcp->horizontalHeaderItem(8);
        ___qtablewidgetitem31->setText(QApplication::translate("qt_demoClass", "\347\264\247\346\200\245\346\214\207\351\222\210", 0));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidgetHttp->horizontalHeaderItem(0);
        ___qtablewidgetitem32->setText(QApplication::translate("qt_demoClass", "Http\350\257\267\346\261\202\345\244\264\351\203\250", 0));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidgetHttp->horizontalHeaderItem(1);
        ___qtablewidgetitem33->setText(QApplication::translate("qt_demoClass", "\346\272\220ip", 0));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidgetHttp->horizontalHeaderItem(2);
        ___qtablewidgetitem34->setText(QApplication::translate("qt_demoClass", "\346\272\220\347\253\257\345\217\243", 0));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidgetHttp->horizontalHeaderItem(3);
        ___qtablewidgetitem35->setText(QApplication::translate("qt_demoClass", "\347\233\256\347\232\204ip", 0));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidgetHttp->horizontalHeaderItem(4);
        ___qtablewidgetitem36->setText(QApplication::translate("qt_demoClass", "\347\233\256\347\232\204\347\253\257\345\217\243", 0));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidgetHttp->horizontalHeaderItem(5);
        ___qtablewidgetitem37->setText(QApplication::translate("qt_demoClass", "\350\241\250\345\215\225\346\225\260\346\215\256", 0));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidgetIcmp->horizontalHeaderItem(0);
        ___qtablewidgetitem38->setText(QApplication::translate("qt_demoClass", "\346\272\220ip", 0));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidgetIcmp->horizontalHeaderItem(1);
        ___qtablewidgetitem39->setText(QApplication::translate("qt_demoClass", "\347\233\256\347\232\204ip", 0));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidgetIcmp->horizontalHeaderItem(2);
        ___qtablewidgetitem40->setText(QApplication::translate("qt_demoClass", "\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidgetIcmp->horizontalHeaderItem(3);
        ___qtablewidgetitem41->setText(QApplication::translate("qt_demoClass", "\344\273\243\347\240\201", 0));
        labelStatus->setText(QString());
        labelProtoType->setText(QApplication::translate("qt_demoClass", "\345\215\217\350\256\256\347\261\273\345\236\213:", 0));
        labelPacket->setText(QApplication::translate("qt_demoClass", "\345\267\262\350\216\267\345\217\226\346\225\260\346\215\256\345\214\205:", 0));
        labelPacketNum->setText(QApplication::translate("qt_demoClass", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class qt_demoClass: public Ui_qt_demoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_DEMO_H
