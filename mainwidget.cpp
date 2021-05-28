#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "character.h"
#include "combatwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    comBat(std::make_shared<ComBatWidget>())
{
    ui->setupUi(this);


    QList<QToolButton*> mapList;
    mapList.append(ui->toolButtonMap1);
     mapList.append(ui->toolButtonMap2);
      mapList.append(ui->toolButtonMap3);
      mapList.append(ui->toolButtonMap4);
      mapList.append(ui->toolButtonMap5);
      mapList.append(ui->toolButtonMap6);
      mapList.append(ui->toolButtonMap7);
      mapList.append(ui->toolButtonMap8);
      mapList.append(ui->toolButtonMap9);
    for (int i = 0; i < mapList.size(); ++i) {
        auto index = i+1;
        connect(mapList.at(i), &QToolButton::clicked, [this, index] { findMap(index); });
    }
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::setRoleInfo(const Character &role)
{

}

void MainWidget::findMap(int maptype)
{
    comBat.get()->setMapType(maptype);
    comBat.get()->show();
}

void MainWidget::on_toolButtonCharacter_clicked()
{

}

void MainWidget::on_toolButtonBackpack_clicked()
{

}

void MainWidget::on_toolButtonEquipment_clicked()
{

}

void MainWidget::on_toolButtonPets_clicked()
{

}

void MainWidget::on_toolButtonSkill_clicked()
{

}
