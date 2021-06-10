#ifndef ROLEINFO_H
#define ROLEINFO_H

#include <QWidget>

namespace Ui {
class Roleinfo;
}
class Character;
class QToolButton;
class  ZBinfoWidget;
class Roleinfo : public QWidget
{
    Q_OBJECT

public:
    explicit Roleinfo(QWidget *parent = nullptr);
    ~Roleinfo();

    void  setRoleInfo(Character *role);
    void  init();
    void  showZB(int type );
private:
    Ui::Roleinfo *ui;
    QList<QToolButton*> mapList;
    Character *m_role;
    std::shared_ptr<ZBinfoWidget> sp_zbInfo;
};

#endif // ROLEINFO_H
