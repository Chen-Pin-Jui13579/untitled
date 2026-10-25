/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *insertButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(683, 588);
        verticalLayout_3 = new QVBoxLayout(Widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(Widget);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_6 = new QLabel(Widget);
        label_6->setObjectName("label_6");

        horizontalLayout_4->addWidget(label_6);

        lineEdit_3 = new QLineEdit(Widget);
        lineEdit_3->setObjectName("lineEdit_3");

        horizontalLayout_4->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(Widget);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        lineEdit_1 = new QLineEdit(Widget);
        lineEdit_1->setObjectName("lineEdit_1");

        horizontalLayout_2->addWidget(lineEdit_1);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_7 = new QLabel(Widget);
        label_7->setObjectName("label_7");

        horizontalLayout_5->addWidget(label_7);

        lineEdit_4 = new QLineEdit(Widget);
        lineEdit_4->setObjectName("lineEdit_4");

        horizontalLayout_5->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        insertButton = new QPushButton(Widget);
        insertButton->setObjectName("insertButton");

        horizontalLayout->addWidget(insertButton);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_6->addLayout(verticalLayout_2);


        horizontalLayout_7->addLayout(horizontalLayout_6);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        horizontalLayout_9->addLayout(horizontalLayout_8);


        verticalLayout_3->addLayout(horizontalLayout_9);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\345\255\270\350\231\237:", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\347\217\255\347\264\232:", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\247\223\345\220\215:", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\351\233\273\350\251\261:", nullptr));
        insertButton->setText(QCoreApplication::translate("Widget", "\346\226\260\345\242\236", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\345\214\257\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
