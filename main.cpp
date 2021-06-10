#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("Microsoft YaHei", 10, 75);
    qApp->setFont(font);
    Widget w;
    w.show();
    return a.exec();
}
