#ifndef MODEL_H
#define MODEL_H

#include "../utils/matchurlbreaker.h"
#include "../utils/networker.h"
#include "../utils/urlcreator.h"
#include "../parsers/matchparser.h"
#include "../parsers/userparser.h"
#include "../parsers/userWinRateParser.h""

#include <QMap>
#include <QString>
#include <QVector>
#include <thread>

using team = QString;
using map = QString;
using winRates = double;

class Model
{
public:
    Model();
    void updateMatchWinRates(QString &matchUrl);

private:
    int getElo(const QString &playerName);
    int getSkilLevel(const QString &playerName);
    QMap<QString, QString> getMapWinRates(QString &matchUrl);
    UserParser getUserParserObject(const QString &playerName);

private slots:

};

#endif // MODEL_H
