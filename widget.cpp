
#include "widget.h"
#include "ui_widget.h"

#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QTextStream>
#include <QStringConverter>
#include <QStringList>
#include <QTableWidgetItem>
#include <QMessageBox>

// 初始化視窗
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

// 關閉視窗
Widget::~Widget()
{
    delete ui;
}

// 新增資料
void Widget::on_insertButton_clicked()
{
    QTableWidgetItem *col1 =
        new QTableWidgetItem(ui->lineEdit_1->text());

    QTableWidgetItem *col2 =
        new QTableWidgetItem(ui->lineEdit_2->text());

    QTableWidgetItem *col3 =
        new QTableWidgetItem(ui->lineEdit_3->text());

    QTableWidgetItem *col4 =
        new QTableWidgetItem(ui->lineEdit_4->text());

    int row = ui->tableWidget->rowCount();

    ui->tableWidget->insertRow(row);

    ui->tableWidget->setItem(row, 0, col1);
    ui->tableWidget->setItem(row, 1, col2);
    ui->tableWidget->setItem(row, 2, col3);
    ui->tableWidget->setItem(row, 3, col4);
}

// 匯出 CSV
void Widget::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "匯出通訊錄",
        "myfile.csv",
        "CSV Files (*.csv)"
        );

    if(fileName.isEmpty())
        return;

    if(!fileName.endsWith(".csv", Qt::CaseInsensitive))
        fileName += ".csv";

    QFile outFile(fileName);

    if(!outFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(
            this, "錯誤", "無法儲存 CSV 檔案"
            );
        return;
    }

    QTextStream out(&outFile);

    // 使用 UTF-8，加入 BOM
    out.setEncoding(QStringConverter::Utf8);
    out.setGenerateByteOrderMark(true);

    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        QStringList rowData;

        for(int j = 0; j < 4; j++)
        {
            QTableWidgetItem *item =
                ui->tableWidget->item(i, j);

            QString value = item ? item->text() : "";

            // 處理 CSV 特殊字元
            if(value.contains(',') ||
                value.contains('"') ||
                value.contains('\n'))
            {
                value.replace("\"", "\"\"");
                value = "\"" + value + "\"";
            }

            rowData << value;
        }

        out << rowData.join(",") << "\n";
    }

    outFile.close();

    QMessageBox::information(
        this, "完成", "CSV 匯出成功！"
        );
}

// 匯入 CSV
void Widget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "匯入通訊錄",
        "",
        "CSV Files (*.csv)"
        );

    if(fileName.isEmpty())
        return;

    QFile inFile(fileName);

    if(!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(
            this, "錯誤", "無法開啟 CSV 檔案"
            );
        return;
    }

    QTextStream in(&inFile);

    // 使用 UTF-8 讀取
    in.setEncoding(QStringConverter::Utf8);

    // 清空原本表格資料
    ui->tableWidget->setRowCount(0);

    while(!in.atEnd())
    {
        QString line = in.readLine();

        if(line.trimmed().isEmpty())
            continue;

        // 解析 CSV 欄位及雙引號
        QStringList fields;
        QString field;
        bool inQuotes = false;

        for(int k = 0; k < line.length(); k++)
        {
            QChar ch = line[k];

            if(ch == '"')
            {
                if(inQuotes &&
                    k + 1 < line.length() &&
                    line[k + 1] == '"')
                {
                    field += '"';
                    k++;
                }
                else
                {
                    inQuotes = !inQuotes;
                }
            }
            else if(ch == ',' && !inQuotes)
            {
                fields << field;
                field.clear();
            }
            else
            {
                field += ch;
            }
        }

        fields << field;

        int row = ui->tableWidget->rowCount();

        ui->tableWidget->insertRow(row);

        for(int j = 0; j < 4 && j < fields.size(); j++)
        {
            QTableWidgetItem *item =
                new QTableWidgetItem(fields[j]);

            ui->tableWidget->setItem(row, j, item);
        }
    }

    inFile.close();

    QMessageBox::information(
        this, "完成", "CSV 匯入成功！"
        );
}
