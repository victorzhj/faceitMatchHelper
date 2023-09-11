#include "userWinRateParser.h"

UserWinRateParser::UserWinRateParser(const QString &file)
{
    document_ = QJsonDocument::fromJson(file.toUtf8());
    jsonObject_ = document_.object();
}

QMap<QString, double> UserWinRateParser::getWinpercentage()
{
    QSet<QString> mapList = {"de_train", "de_nuke", "de_overpass", "de_cbble", "de_inferno", "de_dust2", "de_vertigo", "de_ancient", "de_mirage"};

    QMap<QString, double> winRates;
    QJsonArray segments = jsonObject_.value("segments").toArray();
    // qDebug() << segments;
    foreach (const QJsonValue mapStats, segments)
    {
        QJsonObject tempObject = mapStats.toObject();
        QString mapName = tempObject.value("label").toString();
        if (!mapList.contains(mapName))
        {
            continue;
        }
        else if (tempObject.value("mode").toString() != "5v5")
        {
            continue;
        }
        QJsonObject stats = tempObject.value("stats").toObject();
        double winRate = stats.value("Win Rate %").toDouble()/100;
        // qDebug() << mapName;
        // qDebug() << winRate;
        winRates.insert(mapName, winRate);
    }
    return winRates;
}
