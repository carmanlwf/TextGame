#ifndef BAGWIDGET_H
#define BAGWIDGET_H

#include <QWidget>
#include "commonhelper.h"
namespace Ui {
class BagWidget;
}

class QToolButton;
class  CommonHelper;
class  compareZB;
class BagWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BagWidget(QWidget *parent = nullptr);
    ~BagWidget();

    void  setBagNum(int newNumber );
    int     getBagNum()const ;

    void   updateList() ;
    void   updateRoleZB(const QList<CommonHelper::BasicEquipment> &list);

    void  initBag(int number = 36);
    void  getNewZB(const QList<CommonHelper::BasicEquipment> &list);

    void  dealZB(const QList<CommonHelper::BasicEquipment> &list , int  action = 0);


    void  findZB(int index =0 );

    void  zbZB(qint64  index);
    void  mcZB(qint64 index);

signals :
    void  changedZB(const QList<CommonHelper::BasicEquipment> &list  );
private:
    Ui::BagWidget *ui;
    QList<CommonHelper::BasicEquipment> zbList;
    QList<CommonHelper::BasicEquipment> roleList;
    QList<QToolButton*> btnList;
    int  number;
    std::shared_ptr<compareZB> sp_zbInfo;
};

#endif // BAGWIDGET_H
