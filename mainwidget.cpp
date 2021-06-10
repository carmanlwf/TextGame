#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "character.h"
#include "combatwidget.h"
#include "bagwidget.h"
#include "roleinfo.h"
#include<QFile>
#include<QJsonDocument>
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    comBat(std::make_shared<ComBatWidget>())
       , m_role(std::make_shared<Character>())
       ,m_bagZB(std::make_shared<BagWidget>())
       ,m_roleinfo(std::make_shared<Roleinfo>())
{
    ui->setupUi(this);
    CommonHelper::instance()->initHash();
    init();
    QFont font("Microsoft YaHei", 10, 75);
    this->setFont(font);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::init()
{
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

    connect(comBat.get(), &ComBatWidget::getZB, m_bagZB.get(),   &BagWidget::getNewZB);
    connect(m_bagZB.get(), &BagWidget::changedZB, m_role.get(), &Character::changedZBList);
}



void MainWidget::setRoleInfo(Character *role)
{
    if(role != nullptr)
    {
        m_role.get()->setName(role->name());
        m_role.get()->setClassType(role->classType());
        m_role.get()->setLevel(role->level());
        m_role.get()->addExp(role->getExp());
        m_role.get()->changedZBList(role->getZBList());
        comBat.get()->setRole(m_role.get());
    }

}

void MainWidget::findMap(int maptype)
{
    comBat.get()->setMapType(maptype);
    comBat.get()->show();
}

bool MainWidget::loadGame(const QString &fileName)
{
    QFile loadFile(fileName);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc( QJsonDocument::fromJson(saveData));
    m_role->read(loadDoc.object());
    setRoleInfo(m_role.get());
    return true;
}

bool MainWidget::saveGame(const QString &fileName) const
{
    QFile saveFile(fileName);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QJsonObject gameObject;
    m_role->write(gameObject);
    saveFile.write(QJsonDocument(gameObject).toJson());
    return true;
}

void MainWidget::closeEvent(QCloseEvent *event)
{
    qDebug()<<"MainWidget::closeEvent " <<  saveGame("save.json");
    this->close();
}

void MainWidget::on_toolButtonCharacter_clicked()
{
    m_roleinfo->setRoleInfo(m_role.get());
    m_roleinfo.get()->show();
}

void MainWidget::on_toolButtonBackpack_clicked()
{

}

void MainWidget::on_toolButtonEquipment_clicked()
{
    m_bagZB.get()->show();
}

void MainWidget::on_toolButtonPets_clicked()
{

}

void MainWidget::on_toolButtonSkill_clicked()
{

}
