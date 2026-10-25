#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(4);

    QStringList colTotal;
    colTotal << "學號" << "班級" << "姓名" << "電話";
    ui->tableWidget->setHorizontalHeaderLabels(colTotal);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_insertButton_clicked()
{
    QTableWidgetItem *col1 = new QTableWidgetItem(ui->lineEdit_1->text());
    QTableWidgetItem *col2 = new QTableWidgetItem(ui->lineEdit_2->text());
    QTableWidgetItem *col3 = new QTableWidgetItem(ui->lineEdit_3->text());
    QTableWidgetItem *col4 = new QTableWidgetItem(ui->lineEdit_4->text());

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    ui->tableWidget->setItem(row, 0, col1);
    ui->tableWidget->setItem(row, 1, col2);
    ui->tableWidget->setItem(row, 2, col3);
    ui->tableWidget->setItem(row, 3, col4);
}

void CbWrite(QString fileName, QString str)
{
    QFile outFile(fileName);
    if(!outFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Open File failed!";
        return;
    }
    QTextStream out(&outFile);
    out.setEncoding(QStringConverter::System);
    out << str;
    outFile.flush();
    outFile.close();
}

void Widget::on_pushButton_2_clicked()
{
    QString saveStr;
    QString fileName = QFileDialog::getSaveFileName(this, "匯出通訊錄", ".", "CSV Files (*.csv);;Text Files (*.txt)");

    if (fileName.isEmpty()) {
        return;
    }

    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        for (int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            if (ui->tableWidget->item(i, j)) {
                saveStr += ui->tableWidget->item(i, j)->text() + ",";
            } else {
                saveStr += ",";
            }
        }
        saveStr += "\n";
    }

    CbWrite(fileName, saveStr);
}
void Widget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "匯入通訊錄", ".", "CSV Files (*.csv)");
    if (fileName.isEmpty()) {
        return;
    }

    QFile inFile(fileName);
    if (!inFile.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "無法開啟檔案進行讀取";
        return;
    }

    QTextStream in(&inFile);
    in.setEncoding(QStringConverter::System);

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.trimmed().isEmpty()) continue;

        QStringList fields = line.split(",");

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        for (int i = 0; i < fields.size() && i < 4; ++i) {
            QTableWidgetItem *item = new QTableWidgetItem(fields[i]);
            ui->tableWidget->setItem(row, i, item);
        }
    }
    inFile.close();
}

