#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}


class BagWidget;
class ComBatWidget;
class Character;
class  Roleinfo;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void  init();


    void  setRoleInfo(Character *role);
    void  findMap(int maptype);
    bool loadGame(const  QString &fileName );
    bool saveGame(const  QString &fileName ) const;
protected:
  void closeEvent(QCloseEvent* event) override;

private slots:
    void on_toolButtonCharacter_clicked();

    void on_toolButtonBackpack_clicked();

    void on_toolButtonEquipment_clicked();

    void on_toolButtonPets_clicked();

    void on_toolButtonSkill_clicked();

private:
    Ui::MainWidget *ui;
    std::shared_ptr<ComBatWidget> comBat;
    std::shared_ptr<Character> m_role;
     std::shared_ptr<BagWidget> m_bagZB;
     std::shared_ptr<Roleinfo> m_roleinfo;
};

#endif // MAINWIDGET_H
