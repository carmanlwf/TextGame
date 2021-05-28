#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class ComBatWidget;
class Character;
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void  setRoleInfo(const Character &role);

    void  findMap(int maptype);
private slots:
    void on_toolButtonCharacter_clicked();

    void on_toolButtonBackpack_clicked();

    void on_toolButtonEquipment_clicked();

    void on_toolButtonPets_clicked();

    void on_toolButtonSkill_clicked();

private:
    Ui::MainWidget *ui;
       std::shared_ptr<ComBatWidget> comBat;

};

#endif // MAINWIDGET_H
