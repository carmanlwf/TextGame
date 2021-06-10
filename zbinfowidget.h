#ifndef ZBINFOWIDGET_H
#define ZBINFOWIDGET_H

#include <QWidget>
#include "commonhelper.h"
namespace Ui {
class ZBinfoWidget;
}

class ZBinfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ZBinfoWidget(QWidget *parent = nullptr);
    ~ZBinfoWidget();
    void  setZBinfo(const  CommonHelper::BasicEquipment &zb );
private:
    Ui::ZBinfoWidget *ui;
};

#endif // ZBINFOWIDGET_H
