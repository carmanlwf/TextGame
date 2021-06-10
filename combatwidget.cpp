#include "combatwidget.h"
#include "ui_combatwidget.h"
#include<QTimer>
#include"character.h"

ComBatWidget::ComBatWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComBatWidget),m_mapType(0),b_stop(true)
{
    ui->setupUi(this);


}

ComBatWidget::~ComBatWidget()
{
    delete ui;
}




void ComBatWidget::loadData()
{
    if(mrole ==nullptr )
    {
        return;
    }
    currentGW.clear();
    currentGW = loadDataInfo(false);
    ui->ModelRingt->setInitData(currentGW);

    currentRole.clear();
    currentRole = loadDataInfo(true);
    ui->widgetRole->setInitData(currentRole);
}

void ComBatWidget::setRole(Character *role)
{
    if(role !=nullptr)
    {
        mrole = role;
    }
}

void ComBatWidget::setMapType(int mapType)
{
    m_mapType =mapType;

    ui->labelMapTitle->setText(QString("Map%1").arg(mapType));
    ui->textBrowser->clear();

    loadData();
}

void ComBatWidget::startComBat()
{
    if(!b_stop && (mrole!=nullptr))
    {

       if (currentGW.isEmpty() || currentRole.isEmpty())
           return;
        auto gwName  = currentGW.first();
        auto gwlevel = currentGW.at(1).toInt();
        auto gwHP  = currentGW.at(2).toInt();
        auto GWdamage = currentGW.at(3).toInt();
        auto GWFY= currentGW.last().toInt();

        auto  roleName  = currentRole.first();
        auto roledamage = currentRole.at(3).toInt();
        auto roleFY= currentRole.last().toInt();
        //人物攻击
        auto  damageA  = (roledamage *(roledamage/(roledamage +GWFY *0.5)) ) * QRandomGenerator::global()->bounded(80, 120) /100;
        if  (damageA <= 0)
            damageA  =1;

        // gw  攻击
        auto  damageB  = (GWdamage * (GWdamage/(GWdamage +roleFY*0.8 )))*QRandomGenerator::global()->bounded(80, 120) /100;
        if  (damageB <= 0)
            damageB  =1;


        ui->ModelRingt->adjustPross(damageA );
        ui->textBrowser->append(QString("%1  ComBat %2  damage %3 \n" ).arg(roleName , gwName , QString::number(damageA )));

        if(ui->ModelRingt->getValue() >0)
        {
            ui->widgetRole->adjustPross(damageB );
            ui->textBrowser->append(QString("%1  ComBat %2  damage %3 \n" ).arg(gwName, roleName, QString::number(damageB )));
        }

        // stop
        if(ui->ModelRingt->getValue() == 0  ||  ui->widgetRole->getValue() == 0)
        {
            bool   bWin =  ui->ModelRingt->getValue()==0;
            if(bWin)
            {
                CommonHelper::BasicRole  basic;

                auto  factor =   ((gwHP/0.4)/basic.HP);
                auto tmpType =   factor/gwlevel;
                auto  exp = factor  *100;
                auto  money = factor  *50;
                qDebug()<<"win  "<<currentGW  << factor <<gwHP << gwlevel << tmpType;
                mrole->addExp(exp);
                ui->textBrowser->append(QString("--------------------- ComBat  Win ------------------- \n"));
                ui->textBrowser->append(QString(" get exp %1  and  money %2 \n" ).arg(exp).arg(money));

                // 装备掉落 设置
                auto  list  =   CommonHelper ::instance()->getZBlist(m_mapType, tmpType);
                emit  getZB(list);
                foreach (auto &var, list) {
                    ui->textBrowser->append(QString(" get zb  type %1  lv: %2  and  qualit %3  \n" ).arg(var.type).arg(var.level).arg(var.quality));
                }
                ui->textBrowser->append(QString("----------------------------------------------- \n"));

            }else{
                ui->textBrowser->append(QString("--------------------- ComBat  fail ------------------- \n"));
                ui->textBrowser->append(QString("----------------------------------------------- \n"));
            }

            loadData();
            QTimer::singleShot(800, this, &ComBatWidget::startComBat);

        }else{
            QTimer::singleShot(500, this, &ComBatWidget::startComBat);
        }

    }
}

QList<QString> ComBatWidget::loadDataInfo(bool brole)
{
    CommonHelper::BasicRole   tmpRole;  //
    QStringList   strList;
    if(!brole)
    {
        auto  tmpLevel  = CommonHelper::instance()->getGWlevel(m_mapType);
        auto  tmpType =  CommonHelper::instance()->getGWtype();
        auto  factor = tmpLevel * tmpType ;
        auto  GWHp =  tmpRole.HP *factor * 0.4;
        auto GWdamage = factor  *tmpRole.AD *0.3;
        auto GWFY= factor  *tmpRole.DEF*0.3;

        auto name  =  QString("%1 guaiwu %2").arg(CommonHelper::instance()->getHashName(tmpType )).arg(tmpLevel );
        strList<< name  << QString::number(tmpLevel)<< QString::number( GWHp)<<QString::number(GWdamage )<<QString::number(GWFY);
        return  std::move(strList);

    }

    auto roleHP = mrole->level() *tmpRole.HP;
    auto roledamage = mrole->level() *tmpRole.AD;
    auto roleFY= mrole->level() *tmpRole.DEF;

    auto  zbList =  mrole->getZBList();
    foreach (auto  &zb,  zbList)
    {
        // base
        auto  tmpType =  zb.type %3;
        if(tmpType  ==1)
        {
            roledamage += zb.AD;
        }
        if(tmpType ==  2)
        {
            roleFY += zb.DEF;
        }
        if(tmpType ==  3 )
        {
            roleHP  += zb.HP;
        }

        // addlist
        foreach (auto  &add, zb.addList) {
            if(add.first.contains("AD") )
            {
                roledamage += add.second;
            }
            if(add.first.contains("HP") )
            {
                roleHP += add.second;
            }
            if(add.first.contains("EDF ") )
            {
                roleFY += add.second;
            }
        }
    }

    strList<< mrole->name()  << QString::number(mrole->level())<< QString::number( roleHP)<<QString::number(roledamage )<<QString::number(roleFY );
    return  std::move(strList);

}



void ComBatWidget::on_toolButton_clicked()
{

    if(b_stop)
    {
        b_stop =false ;
        ui->toolButton->setText(tr("Stop"));
        startComBat();
    }
    else
    {
        b_stop =true ;
        ui->toolButton->setText(tr("Start"));
    }

}
