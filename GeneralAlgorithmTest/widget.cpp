#include "widget.h"
#include "ui_widget.h"
#include "../GeneralAlgorithm/similarity.h"
#include <QDebug>
#include <string.h>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug()<<SimilarityED("test1", "test2");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_PB_Calc_clicked()
{
    int maxLength = qMax(strlen(ui->LE_Str1->text().toStdString().c_str()), strlen(ui->LE_Str2->text().toStdString().c_str()));
    if (maxLength == 0) {
        QMessageBox::warning(this, tr("警告"), tr("空字符串无法比较"));
        return;
    }
    int ed = SimilarityED(ui->LE_Str1->text().toStdString().c_str(), ui->LE_Str2->text().toStdString().c_str());
    ui->LE_ED->setText(QString("%1").arg(ed));
    ui->LE_SimilarityED->setText(QString("%1")
                               .arg(1.0-(float)ed/maxLength));

    ui->LE_SimilarityM->setText(QString("%1").arg(SimilarityMatrix(ui->LE_Str1->text().toStdString().c_str(), ui->LE_Str2->text().toStdString().c_str())));
}
