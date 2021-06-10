#include "bagwidget.h"
#include "ui_bagwidget.h"
#include<QToolButton>
#include <QtMath>
#include "zbinfowidget.h"
#include "comparezb.h"
BagWidget::BagWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BagWidget),number(36),sp_zbInfo(std::make_shared<compareZB>())
{
    ui->setupUi(this);
    initBag();

    connect(sp_zbInfo.get(), &compareZB::zb, this, &BagWidget::zbZB);
    connect(sp_zbInfo.get(), &compareZB::mc, this, &BagWidget::mcZB);
}

BagWidget::~BagWidget()
{
    delete ui;
}

void BagWidget::setBagNum(int newNumber)
{
    number = newNumber;
}

int BagWidget::getBagNum() const
{
    return  number;
}

void BagWidget::updateList()
{

    foreach (auto btn, btnList) {
        btn->setText("");
    }
    QHash<int , QString> colorHash;
    colorHash.insert(1, "white");
    colorHash.insert(2, "green");
    colorHash.insert(3, "blue");
    colorHash.insert(4, "magenta");
    colorHash.insert(5, "red");

    auto  max = qMin(zbList.size(), btnList.size());
    for (int i = 0; i < max ; ++i) {
        auto  tmp = zbList.at(i);
        btnList.at(i)->setText(tmp.name);
        QString color =colorHash.value(tmp.quality);
        btnList.at(i)->setStyleSheet(QString("QToolButton{color:%1}").arg(color));
    }
}

void BagWidget::updateRoleZB(const QList<CommonHelper::BasicEquipment> &list)
{
    roleList = list;
}

void BagWidget::initBag(int number)
{
    ui->gridLayout_2->setSpacing(1);
    int  max = qSqrt(number);
    for (int i = 0; i < number; ++i)
    {
        auto btn = new QToolButton(this);
        btn->setMinimumSize(40, 40);
        btn->setText("");
        btnList.append(btn);
        ui->gridLayout_2->addWidget(btn,  i /max, i%max);
        connect(btn, &QToolButton::clicked, [this, i] { findZB(i); });
    }
}

void BagWidget::getNewZB(const QList<CommonHelper::BasicEquipment> &list)
{
    if(!list.isEmpty() )
    {
        zbList.append(list);
        updateList();
    }
}

void BagWidget::findZB(int index)
{
    auto  tmpZB = zbList.at(index);
    int tmp = -1;
    // 已找到对应zb
    for (int i = 0; i < roleList.size(); ++i) {
        if(roleList.at(i).type  == tmpZB.type )
        {
            tmp = i;
            break;
        }
    }
    if(tmp  >=0 )
    {
        sp_zbInfo->setRoleZB(roleList.at(tmp ));
    }
    else
    {
        sp_zbInfo->hideRoleZB();
    }
    sp_zbInfo->setTmpZb(tmpZB );
    sp_zbInfo->setTmpZbIndex(index);
    sp_zbInfo->show();
}

void BagWidget::zbZB(qint64 index)
{
    qDebug()<<"zbList "<<zbList.size() << index;
    if(index >= zbList.size())
        return;
    auto  tmpZB = zbList.at(index);
    tmpZB.bload = true ;

    int tmp = -1;
    for (int i = 0; i < roleList.size(); ++i) {
        if(roleList.at(i).type  == tmpZB.type )
        {
            tmp = i;
            break;
        }
    }
    qDebug()<<"BagWidget::zbZB " <<index   << tmp <<tmpZB.type ;
    // 已找到对应zb
    if(tmp  >=0 )
    {
        auto  rolezb  =  roleList.at(tmp);
        rolezb.bload = false;
        zbList.replace(index, rolezb);
        roleList.replace(tmp, tmpZB);
    }
    else
    {
        zbList.removeAt(index);
        roleList.append(tmpZB);
    }
    sp_zbInfo->hide();
    updateList();
    emit  changedZB(roleList);
}

void BagWidget::mcZB(qint64 index)
{
    auto  tmpZB = zbList.at(index);

}
