#include "commonhelper.h"
Q_GLOBAL_STATIC(CommonHelper, commonHelper)

CommonHelper* CommonHelper::instance() {
    return commonHelper();
}

CommonHelper::BasicEquipment CommonHelper::readZB(const QJsonObject &json)
{

    BasicEquipment ZB;
    if (json.contains("name") && json["name"].isString())
        ZB.name = json["name"].toString();
    if (json.contains("type") && json["type"].isDouble())
        ZB.type = json["name"].toInt();
    if (json.contains("level") && json["level"].isDouble())
        ZB.level = json["level"].toInt();
    if (json.contains("quality") && json["quality"].isDouble())
        ZB.quality = json["quality"].toInt();
    if (json.contains("bload") && json["bload"].isBool())
        ZB.bload = json["bload"].toBool();

    QString  tmpstr;
     if (json.contains("addList") && json["addList"].isString())
        tmpstr = json["addList"].toString();
     QStringList list =  tmpstr.split(";");
     foreach(auto  var, list)
     {
         if(!var.isEmpty())
         {
             auto  tmplist  = var.split(":");
             ZB.addList.append(qMakePair(tmplist.at(0) , tmplist.at(1).toInt() ));
         }
     }

     return   ZB;
}

void CommonHelper::writeZB(const CommonHelper::BasicEquipment zb, QJsonObject &json)
{
    json["name"] = zb.name;
    json["type"] = zb.type;
    json["level"] = zb.level;
    json["quality"] =zb.quality;
    json["bload"]=zb.bload;

    QString  addList;
    for (int i = 0; i < zb.addList.size(); ++i) {
        auto  tmp  =  zb.addList.at(i);
        QString tmpstr = QString("%1:%2").arg(tmp.first).arg(tmp.second);
        addList.append(tmpstr);
            addList.append(";");
    }
    json["addList"]  = addList;
}

int CommonHelper::getGWlevel(int m_mapType)
{
    auto  tmpLevel  =  QRandomGenerator::global()->bounded(1, 5) +  (m_mapType -1)* 5;
    return  tmpLevel ;
}

int CommonHelper::getGWtype()
{
    auto  tmpLevel  = QRandomGenerator::global()->bounded(1, 100) ;
    int  type =1;
    if(tmpLevel<= 50)
        return   type = 1;
    if(tmpLevel<= 80)
        return  type = 2;
    if(tmpLevel<= 95)
        return type = 3;
    if(tmpLevel<= 100)
        return  type = 4;
}

QList<CommonHelper::BasicEquipment> CommonHelper::getZBlist(int m_mapType, int GWtype)
{
    auto  randNum =  QRandomGenerator::global()->bounded(1, 100);
    auto limitNum  =  20 + 20*GWtype;
    QList<CommonHelper::BasicEquipment> list;
    // 掉落
    if(randNum <= limitNum)
    {
        //数量
        auto   zbNum  =   GWtype >1 ? QRandomGenerator::global()->bounded(1, GWtype) : 1;
        for (int i = 0; i < zbNum ; ++i) {
            CommonHelper::BasicEquipment  zb;
            zb.level  =   getGWlevel(m_mapType);
            zb.quality =GWtype >1 ? QRandomGenerator::global()->bounded(1, GWtype):1 ;
            zb.type =    QRandomGenerator::global()->bounded(1, 6);
            zb.name =   QString("%1%2 %3").arg( ZBqualityhash.value(zb.quality))
                          .arg(ZBlevelhash.value(zb.level/10))
                          .arg(ZBtypehash.value(zb.type) );

            for(int j=0; j<zb.quality ; ++j )
            {
                auto add =  QRandomGenerator::global()->bounded(1,3);
                if(add == 1 )
                {
                    zb.addList.append(qMakePair(tr("HP"), zb.HP *zb.quality));
                }
                if(add == 2 )
                {
                    zb.addList.append(qMakePair(tr("AD"), zb.AD *zb.quality));
                }
                if(add == 3)
                {
                    zb.addList.append(qMakePair(tr("DEF"), zb.DEF *zb.quality));
                }
            }
            list.append(zb);
        }

    }
    return   list;
}

void CommonHelper::initHash()
{
    GWhash.insert(1, tr("PT"));
    GWhash.insert(2, tr("JY"));
    GWhash.insert(3, tr("LZ"));
    GWhash.insert(4, tr("Boos"));

    ZBtypehash.insert(1, tr("Main weapon"));
    ZBtypehash.insert(2, tr("Main armor"));
    ZBtypehash.insert(3, tr("Main accessory"));
    ZBtypehash.insert(4, tr("Secondary weapon"));
    ZBtypehash.insert(5, tr("Secondary armor"));
    ZBtypehash.insert(6, tr("Secondary accessory"));


    ZBlevelhash.insert(0, tr("SQ"));
    ZBlevelhash.insert(1, tr("QT"));
    ZBlevelhash.insert(2, tr("TQ"));
    ZBlevelhash.insert(3, tr("HJ"));
    ZBlevelhash.insert(4, tr("WL"));

    ZBqualityhash.insert(1, tr("PT"));
    ZBqualityhash.insert(2, tr("YX"));
    ZBqualityhash.insert(3, tr("WM"));
    ZBqualityhash.insert(4, tr("SS"));
    ZBqualityhash.insert(5, tr("CS"));
}

QString CommonHelper::getHashName(int key, int type)
{
    if(type ==0 )
        return GWhash.value(key);
    if(type ==1 )
        return ZBtypehash.value(key);
    if(type ==2 )
        return ZBlevelhash.value(key);
    if(type ==3 )
        return ZBqualityhash.value(key);
}

