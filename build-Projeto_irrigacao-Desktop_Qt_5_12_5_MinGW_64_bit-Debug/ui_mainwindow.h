/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label;
    QFrame *frame_3;
    QGroupBox *groupBox;
    QLabel *txt_portaSerial;
    QComboBox *box_serial;
    QLabel *txt_velocidade;
    QComboBox *box_velocidade;
    QLabel *txt_status;
    QLabel *status_conexao;
    QPushButton *btnPlug;
    QGroupBox *groupBox_2;
    QComboBox *combo_Sistema;
    QLabel *label_8;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QLabel *label_5;
    QFrame *frame_2;
    QFrame *frame_4;
    QLabel *lbl_LDR;
    QFrame *frame_5;
    QFrame *frame_8;
    QLabel *lbl_umidade_solo;
    QLabel *label_3;
    QPushButton *btn_desligarsist;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(46, 52, 54);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 60, 781, 16));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 181, 223);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 10, 631, 31));
        label->setStyleSheet(QString::fromUtf8("font: 57 18pt \"Ubuntu\";"));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 80, 781, 471));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(frame_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, 30, 331, 241));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 37, 53);\n"
"color: rgb(255, 255, 255);\n"
""));
        txt_portaSerial = new QLabel(groupBox);
        txt_portaSerial->setObjectName(QString::fromUtf8("txt_portaSerial"));
        txt_portaSerial->setGeometry(QRect(20, 50, 81, 21));
        txt_portaSerial->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        box_serial = new QComboBox(groupBox);
        box_serial->setObjectName(QString::fromUtf8("box_serial"));
        box_serial->setGeometry(QRect(110, 50, 191, 24));
        box_serial->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        txt_velocidade = new QLabel(groupBox);
        txt_velocidade->setObjectName(QString::fromUtf8("txt_velocidade"));
        txt_velocidade->setGeometry(QRect(20, 90, 81, 21));
        txt_velocidade->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        box_velocidade = new QComboBox(groupBox);
        box_velocidade->setObjectName(QString::fromUtf8("box_velocidade"));
        box_velocidade->setGeometry(QRect(110, 90, 191, 24));
        box_velocidade->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        txt_status = new QLabel(groupBox);
        txt_status->setObjectName(QString::fromUtf8("txt_status"));
        txt_status->setGeometry(QRect(20, 190, 58, 16));
        txt_status->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        status_conexao = new QLabel(groupBox);
        status_conexao->setObjectName(QString::fromUtf8("status_conexao"));
        status_conexao->setGeometry(QRect(110, 180, 181, 31));
        status_conexao->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        btnPlug = new QPushButton(groupBox);
        btnPlug->setObjectName(QString::fromUtf8("btnPlug"));
        btnPlug->setGeometry(QRect(110, 130, 191, 24));
        btnPlug->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(400, 310, 221, 91));
        groupBox_2->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(138, 226, 52);\n"
"color: rgb(0, 0, 0);\n"
"font: 57 12pt \"Ubuntu\";"));
        combo_Sistema = new QComboBox(groupBox_2);
        combo_Sistema->addItem(QString());
        combo_Sistema->addItem(QString());
        combo_Sistema->setObjectName(QString::fromUtf8("combo_Sistema"));
        combo_Sistema->setGeometry(QRect(20, 40, 191, 31));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(220, -55, 191, 71));
        label_8->setStyleSheet(QString::fromUtf8(""));
        groupBox_3 = new QGroupBox(frame_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(50, 290, 331, 151));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(171, 232, 230);\n"
"color: rgb(0, 0, 0);"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 30, 101, 21));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(190, 30, 111, 21));
        frame_2 = new QFrame(groupBox_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(20, 60, 141, 61));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 181, 223);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(10, 10, 120, 41));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        lbl_LDR = new QLabel(frame_4);
        lbl_LDR->setObjectName(QString::fromUtf8("lbl_LDR"));
        lbl_LDR->setGeometry(QRect(0, 0, 121, 41));
        lbl_LDR->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 57 16pt \"Ubuntu\";"));
        frame_5 = new QFrame(groupBox_3);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(170, 60, 141, 61));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 181, 223);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_8 = new QFrame(frame_5);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(10, 10, 120, 41));
        frame_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        lbl_umidade_solo = new QLabel(frame_8);
        lbl_umidade_solo->setObjectName(QString::fromUtf8("lbl_umidade_solo"));
        lbl_umidade_solo->setGeometry(QRect(7, 0, 111, 41));
        lbl_umidade_solo->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 57 16pt \"Ubuntu\";"));
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(640, 310, 101, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 57 10pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);"));
        btn_desligarsist = new QPushButton(frame_3);
        btn_desligarsist->setObjectName(QString::fromUtf8("btn_desligarsist"));
        btn_desligarsist->setGeometry(QRect(630, 340, 111, 61));
        btn_desligarsist->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagens/Imagens/valvula bnt.png);\n"
""));
        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(430, 30, 301, 241));
        label_9->setStyleSheet(QString::fromUtf8("image: url(:/Imagens/Imagens/CASIE.png);"));
        groupBox_2->raise();
        groupBox->raise();
        groupBox_3->raise();
        label_3->raise();
        btn_desligarsist->raise();
        label_9->raise();
        MainWindow->setCentralWidget(centralwidget);
        frame_3->raise();
        frame->raise();
        label->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Controle Autom\303\241tico Sistema de Irriga\303\247\303\243o Eficiente - CASIE", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Serial:", nullptr));
        txt_portaSerial->setText(QApplication::translate("MainWindow", "Porta Serial:", nullptr));
        txt_velocidade->setText(QApplication::translate("MainWindow", "Velocidade:", nullptr));
        txt_status->setText(QApplication::translate("MainWindow", "Status:", nullptr));
        status_conexao->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        btnPlug->setText(QApplication::translate("MainWindow", "Conex\303\243o", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Sele\303\247\303\243o do Sistema", nullptr));
        combo_Sistema->setItemText(0, QApplication::translate("MainWindow", "Automatico", nullptr));
        combo_Sistema->setItemText(1, QApplication::translate("MainWindow", "Manual", nullptr));

        label_8->setText(QApplication::translate("MainWindow", "Desacionamento da v\303\241lvula", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Dados Sensores", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Luminosidade", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Umidade do solo", nullptr));
        lbl_LDR->setText(QString());
        lbl_umidade_solo->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Liga/desliga", nullptr));
        btn_desligarsist->setText(QString());
        label_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
