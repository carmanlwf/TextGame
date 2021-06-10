#include "widget.h"
#include "ui_widget.h"
#include "createrole.h"
#include "character.h"
#include <QDebug>
#include"mainwidget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , role(std::make_shared<CreateRole>())
   , mainWidget(std::make_shared<MainWidget>())
{
    ui->setupUi(this);

    connect(role.get(), &CreateRole::signalRole, this, &Widget::recvRoleInfo);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::recvRoleInfo(const QString &name, int roleType)
{
    qDebug()<<"Widget::recvRoleInfo" <<name << roleType ;

    Character  role;
    role.setName(name);
    role.setClassType(Character::ClassType(roleType));
    role.setLevel(1);
        // role
    //game_->newGame(name, roleType);
    mainWidget->setRoleInfo(&role);
    mainWidget->show();

}


void Widget::on_pushButtonNew_clicked()
{
    // 1.  create

    role.get()->show();
    hide();
    // 2. save

    // 3 main
}

void Widget::on_pushButtonLoad_clicked()
{
    mainWidget->loadGame("save.json");
     mainWidget->show();
      hide();
}

void Widget::on_pushButtonAbout_clicked()
{

}
