#include "roleinfo.h"
#include "ui_roleinfo.h"
#include "character.h"
#include "zbinfowidget.h"
Roleinfo::Roleinfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Roleinfo), sp_zbInfo(std::make_shared<ZBinfoWidget>())
{
    ui->setupUi(this);
    init();
}

Roleinfo::~Roleinfo()
{
    delete ui;
}

void Roleinfo::setRoleInfo(Character *role)
{
    if(role != nullptr)
    {
        m_role = role;
        ui->label->setText(role->name());
        auto list = role->getZBList();
        QHash<int , QString> colorHash;
        colorHash.insert(1, "white");
        colorHash.insert(2, "green");
        colorHash.insert(3, "blue");
        colorHash.insert(4, "magenta");
        colorHash.insert(5, "red");
        foreach ( auto  &zb , list) {
            mapList.at(zb.type-1)->setText(zb.name);
            QString color =colorHash.value(zb.quality);
            mapList.at(zb.type-1)->setStyleSheet(QString("QToolButton{color:%1}").arg(color));
        }
    }
}

void Roleinfo::init()
{
    // QList<QToolButton*> mapList;
    mapList.append(ui->toolButton);
    mapList.append(ui->toolButton_2);
    mapList.append(ui->toolButton_3);
    mapList.append(ui->toolButton_4);
    mapList.append(ui->toolButton_5);
    mapList.append(ui->toolButton_6);
    for (int i = 0; i < mapList.size(); ++i) {
        auto index = i+1;
        connect(mapList.at(i), &QToolButton::clicked, [this, index] { showZB(index); });
    }
}

void Roleinfo::showZB(int type)
{
    if (m_role !=nullptr)
    {
        auto list = m_role->getZBList();

        foreach (auto  &zb, list ) {
              qDebug()<<"show zb"<< type<< zb.type;
            if(zb.type ==  type)
            {
                sp_zbInfo->setZBinfo(zb);
                sp_zbInfo->show();
                return;
            }
        }

    }

     //sp_zbInfo
}
