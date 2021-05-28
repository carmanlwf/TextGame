#ifndef COMBATWIDGET_H
#define COMBATWIDGET_H

#include <QWidget>

namespace Ui {
class ComBatWidget;
}

class Character;
class ComBatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ComBatWidget(QWidget *parent = nullptr);
    ~ComBatWidget();
    void  setRole(Character &role);
    void  setMapType(int mapType);
private slots:
    void on_toolButton_clicked();

private:
    Ui::ComBatWidget *ui;
    int m_mapType{};
};

#endif // COMBATWIDGET_H
