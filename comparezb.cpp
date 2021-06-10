#include "comparezb.h"
#include "ui_comparezb.h"

compareZB::compareZB(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::compareZB)
{
    ui->setupUi(this);
}

compareZB::~compareZB()
{
    delete ui;
}

void compareZB::hideRoleZB()
{
    ui->ZBRole->setVisible(false);
}

void compareZB::setRoleZB(const CommonHelper::BasicEquipment &zb)
{
    ui->ZBRole->setZBinfo(zb);
    ui->ZBRole->setVisible(true);
}

void compareZB::setTmpZb(const CommonHelper::BasicEquipment &zb)
{
    ui->ZBTmp->setZBinfo(zb);
}

void compareZB::setTmpZbIndex(qint64 zbindex)
{
    m_zbindex = zbindex;
}

void compareZB::on_pushButtonZB_clicked()
{
    emit  zb(m_zbindex);
}

void compareZB::on_pushButtonMC_clicked()
{
    emit  mc(m_zbindex);
}
