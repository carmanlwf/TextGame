#include "createrole.h"
#include "ui_createrole.h"

CreateRole::CreateRole(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateRole)
{
    ui->setupUi(this);
}

CreateRole::~CreateRole()
{
    delete ui;
}

void CreateRole::on_pushButtonOK_clicked()
{
    auto  name = ui->lineEditName->text().trimmed();

    auto type   = 0;
    if(ui->radioButtonF->isChecked())
        type = 1;
    if(ui->radioButtonM->isChecked())
        type = 2;
    if( !name.isEmpty())
    {

        emit  signalRole(name, type );

        ui->lineEditName->clear();
        close();
    }

}

void CreateRole::on_pushButtonCancel_clicked()
{
      close();
}
