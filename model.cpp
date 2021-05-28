#include "model.h"
#include "ui_model.h"

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
    if(dataInfo.size() >= 3)
    {
        ui->labelName->setText(dataInfo.at(0));
        ui->progressBarRed->setMaximum(dataInfo.at(1).toInt());
        ui->progressBarRed->setValue(dataInfo.at(1).toInt());
        ui->progressBarBlue->setMaximum(dataInfo.at(2).toInt());
        ui->progressBarBlue->setValue(dataInfo.at(2).toInt());
         ui->progressBarRed->setFormat(QString("Health：%1/%2").arg(dataInfo.at(1),dataInfo.at(1)));
         ui->progressBarBlue->setFormat(QString("Mana：%1/%2").arg(dataInfo.at(2),dataInfo.at(2)));
         ui->progressBarRed->setAlignment(Qt::AlignCenter);  // 对齐方式
         ui->progressBarBlue->setAlignment(Qt::AlignCenter);  // 对齐方式
    }

}

void Model::adjustPross(qint64 value, int type)
{
    if(type>0 )
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
    else{
         auto  tmp = ui->progressBarBlue->value() ;
        if(tmp >= value)
        {
            ui->progressBarBlue->setValue(tmp-value);
        }
    }

}

qint64 Model::getValue(int type)
{
    return   type>0 ?  ui->progressBarRed->value() : ui->progressBarBlue->value()  ;
}
