#include "combatwidget.h"
#include "ui_combatwidget.h"

ComBatWidget::ComBatWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComBatWidget),m_mapType(0)
{
    ui->setupUi(this);
}

ComBatWidget::~ComBatWidget()
{
    delete ui;
}

void ComBatWidget::setRole(Character &role)
{

}

void ComBatWidget::setMapType(int mapType)
{
    m_mapType =mapType;

    ui->labelMapTitle->setText(QString("Map%1").arg(mapType));
    ui->textBrowser->clear();
}

void ComBatWidget::on_toolButton_clicked()
{

}
