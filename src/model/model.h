#ifndef MODEL_H
#define MODEL_H

#include "../utils/matchurlbreaker.h"
#include "../utils/networker.h"
#include "../utils/urlcreator.h"
#include "../parsers/matchparser.h"
#include "../parsers/userparser.h"
#include "../parsers/userstatsparser.h""

#include <QMap>
#include <QString>
#include <QVector>

class Model
{
public:
    Model();

private:
    int getElo(const QString &playerName);
    int getSkilLevel(const QString &playerName);
    QMap<QString, QString> getMapWinRates(QString &matchUrl);
    UserParser getUserParserObject(const QString &playerName);
};

#endif // MODEL_H
