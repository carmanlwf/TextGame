#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class  Game;
class  CreateRole;
class  MainWidget;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void  recvRoleInfo(const QString &name,  int roleType=0);

private slots:
    void on_pushButtonNew_clicked();

    void on_pushButtonLoad_clicked();

    void on_pushButtonAbout_clicked();

private:
    Ui::Widget *ui;
     std::shared_ptr<Game> game_;
     std::shared_ptr<CreateRole> role;
     std::shared_ptr<MainWidget> mainWidget;
};
#endif // WIDGET_H
