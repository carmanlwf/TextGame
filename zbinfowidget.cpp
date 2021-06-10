#include "zbinfowidget.h"
#include "ui_zbinfowidget.h"

ZBinfoWidget::ZBinfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZBinfoWidget)
{
    ui->setupUi(this);
}

ZBinfoWidget::~ZBinfoWidget()
{
    delete ui;
}

void ZBinfoWidget::setZBinfo(const CommonHelper::BasicEquipment &zb)
{
    ui->labelName->setText(zb.name);
    ui->labelType->setText( CommonHelper::instance()-> getHashName(zb.type, 1));
    ui->labelLevel->setText( QString::number(zb.level));
    ui->labelQuality->setText( CommonHelper::instance()-> getHashName(zb.quality,3));

    ui->labelHp->setText( QString::number(zb.HP));
    ui->labelAD->setText( QString::number(zb.AD));
    ui->labelDEF->setText( QString::number(zb.DEF));

    bool  bAD =false;
    bool  bHP =false;
    bool  bDEF = false;

    auto  tmpType = zb.type%3;
    if(tmpType == 0)
    {
        bHP = true;
    }
    if(tmpType == 1)
    {
        bAD  = true;
    }
    if(tmpType == 2)
    {
        bDEF  =true;
    }

    ui->labAD->setVisible(bAD);
    ui->labelAD->setVisible(bAD);
    ui->labelDEF->setVisible(bDEF );
    ui->labDEF->setVisible(bDEF );
    ui->labelHp->setVisible(bHP );
    ui->labHp->setVisible(bHP );


    QList<QPair<QLabel*, QLabel*>> addlabelList;
    addlabelList.append(qMakePair(ui->labADD1, ui->labelADD1));
    addlabelList.append(qMakePair(ui->labADD2, ui->labelADD2));
    addlabelList.append(qMakePair(ui->labADD3, ui->labelADD3));
    addlabelList.append(qMakePair(ui->labADD4, ui->labelADD4));

    foreach (auto var, addlabelList) {
        var.first->setVisible(false);
        var.second->setVisible(false);
    }

    int i= 0;
    foreach (auto  &add, zb.addList) {
        auto str = QString("%1:%2").arg(add.first).arg(add.second);
        addlabelList.at(i).first->setVisible(true);
        addlabelList.at(i).second->setVisible(true);
        addlabelList.at(i).second->setText(str);
        ++i;
    }
}
