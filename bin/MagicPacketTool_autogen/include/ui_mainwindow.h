/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *Sendpacket;
    QPushButton *Listen;
    QLabel *label;
    QTextEdit *textEditOutput;
    QComboBox *comboBox;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(190, 280, 441, 41));
        Sendpacket = new QPushButton(centralwidget);
        Sendpacket->setObjectName("Sendpacket");
        Sendpacket->setGeometry(QRect(190, 330, 101, 29));
        Listen = new QPushButton(centralwidget);
        Listen->setObjectName("Listen");
        Listen->setGeometry(QRect(190, 370, 101, 29));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 250, 351, 20));
        textEditOutput = new QTextEdit(centralwidget);
        textEditOutput->setObjectName("textEditOutput");
        textEditOutput->setGeometry(QRect(190, 44, 441, 151));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(550, 330, 82, 28));
        comboBox->setEditable(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(470, 330, 81, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit->setText(QString());
        Sendpacket->setText(QCoreApplication::translate("MainWindow", "Send Packet", nullptr));
        Listen->setText(QCoreApplication::translate("MainWindow", "Listen ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter Target MAC address", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "9", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "7", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Select Port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
