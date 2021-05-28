#include "widget.h"
#include "ui_widget.h"
#include "createrole.h"
#include "game.h"
#include <QDebug>
#include"mainwidget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , game_(std::make_shared<Game>())
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
    game_->newGame();

    mainWidget.get()->show();
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

}

void Widget::on_pushButtonAbout_clicked()
{

}
