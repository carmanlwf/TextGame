#include "model.h"
#include "ui_model.h"
#include<QDebug>
Model::Model(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Model)
{
    ui->setupUi(this);
}

Model::~Model()
{
    delete ui;
}

void Model::setInitData(const QList<QString> &dataInfo)
{
   // qDebug()<< "Model::setInitData "<<dataInfo;
    if(dataInfo.size() >= 5)
    {
        ui->labelName->setText(dataInfo.at(0));
        ui->labelLevel->setText(dataInfo.at(1));
        ui->progressBarRed->setMaximum(dataInfo.at(2).toInt());
        ui->progressBarRed->setValue(dataInfo.at(2).toInt());
         ui->progressBarRed->setFormat(QString("Health：%1/%2").arg(dataInfo.at(2),dataInfo.at(2)));
         ui->progressBarRed->setAlignment(Qt::AlignCenter);  // 对齐方式
         ui->labelAD->setText(dataInfo.at(3));
         ui->labelDEF->setText(dataInfo.at(4));
    }

}

void Model::adjustPross(qint64 value, int type)
{
    if(type == 0 )
    {
        auto  tmp = ui->progressBarRed->value() ;
        if(tmp >= value)
        {
            ui->progressBarRed->setValue(tmp-value);
        }
        else{
            ui->progressBarRed->setValue(0);
        }
    }


}

qint64 Model::getValue(int type)
{
    return     ui->progressBarRed->value();
}
