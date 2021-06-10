#ifndef COMPAREZB_H
#define COMPAREZB_H

#include <QWidget>
#include "commonhelper.h"
namespace Ui {
class compareZB;
}

class compareZB : public QWidget
{
    Q_OBJECT

public:
    explicit compareZB(QWidget *parent = nullptr);
    ~compareZB();

    void  hideRoleZB();
    void  setRoleZB(const CommonHelper::BasicEquipment &zb);
    void  setTmpZb(const CommonHelper::BasicEquipment &zb);
     void  setTmpZbIndex( qint64  zbindex);
signals:

    void  zb(qint64 zbid);
    void  mc(qint64 zbid);
private slots:
    void on_pushButtonZB_clicked();

    void on_pushButtonMC_clicked();

private:
    Ui::compareZB *ui;
    qint64  m_zbindex;
};

#endif // COMPAREZB_H
