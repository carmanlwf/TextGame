#ifndef COMMONHELPER_H
#define COMMONHELPER_H

#include <QObject>
#include<QTime>
#include<QRandomGenerator>
#include <QJsonObject>
class CommonHelper: public QObject
{
    Q_OBJECT
public:

    struct BasicRole {
        qint64 HP{500};
        qint64 AD{100};
        qint64 DEF{50}; //防御力
    };

    struct BasicEquipment {
        qint64 HP{100};
        qint64 AD{20};
        qint64 DEF{10}; //防御力
        int type{0};
        int level{0};
        int quality{0};  //
        bool bload{0};  //  是否穿戴
        qint64  zbid;
        QString  name;
        QList<QPair<QString , int>> addList; // 附加能力
    };



    static CommonHelper* instance();

   static   BasicEquipment readZB(const QJsonObject &json);

   static  void writeZB(const BasicEquipment zb, QJsonObject &json) ;

     int getGWlevel(int m_mapType);

     int getGWtype();

    QList<BasicEquipment> getZBlist( int m_mapType ,int GWtype);

    void  initHash();
    QString getHashName(int key , int type =0);
private:
    QHash<int, QString> GWhash;
    QHash<int, QString> ZBtypehash;
    QHash<int, QString> ZBlevelhash;
    QHash<int, QString> ZBqualityhash;
};



#endif // COMMONHELPER_H
