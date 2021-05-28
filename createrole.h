#ifndef CREATEROLE_H
#define CREATEROLE_H

#include <QWidget>

namespace Ui {
class CreateRole;
}

class CreateRole : public QWidget
{
    Q_OBJECT

public:
    explicit CreateRole(QWidget *parent = nullptr);
    ~CreateRole();
signals:
    void  signalRole(const QString &name,  int roleType = 0);
private slots:
    void on_pushButtonOK_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::CreateRole *ui;
};

#endif // CREATEROLE_H
