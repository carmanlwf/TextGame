#ifndef COMBATWIDGET_H
#define COMBATWIDGET_H

#include <QWidget>
#include "commonhelper.h"
namespace Ui {
class ComBatWidget;
}

class Character;
class  CommonHelper;
class ComBatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ComBatWidget(QWidget *parent = nullptr);
    ~ComBatWidget();
    void  loadData();
    void  setRole(Character *role);
    void  setMapType(int mapType);
    void  startComBat();

    QList<QString> loadDataInfo(bool brole = true);
signals  :
    void  getExp(qint64 exp);
    void  getZB(const QList<CommonHelper::BasicEquipment> &list);
    void  getWP(const QList<QString> &list);
private slots:
    void on_toolButton_clicked();

private:
    Ui::ComBatWidget *ui;
    int m_mapType{};
    bool  b_stop;
    Character *mrole{};
    QList<QString> currentGW;
    QList<QString> currentRole;

};

#endif // COMBATWIDGET_H
