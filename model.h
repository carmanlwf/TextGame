#ifndef MODEL_H
#define MODEL_H

#include <QWidget>

namespace Ui {
class Model;
}

class Model : public QWidget
{
    Q_OBJECT

public:
    explicit Model(QWidget *parent = nullptr);
    ~Model();

    void  setInitData(const QList<QString> &dataInfo);

    void  adjustPross(qint64 value, int type = 0);

    qint64 getValue(int type = 0);

private:
    Ui::Model *ui;
};

#endif // MODEL_H
