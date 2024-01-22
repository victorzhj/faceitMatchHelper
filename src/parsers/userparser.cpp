#include "userparser.h"

UserParser::UserParser(const QString &file)
{
    document_ = QJsonDocument::fromJson(file.toUtf8());
    jsonObject_ = document_.object();
}
QString UserParser::getImageUrl()
{
    return jsonObject_.value("avatar").toString();
}

int UserParser::getSkillLevel()
{
    QJsonObject cs2 = getCsgoStats();
    return cs2.value("skill_level").toInt();
}

int UserParser::getFaceitElo()
{
    QJsonObject cs2 = getCsgoStats();
    return cs2.value("faceit_elo").toInt();
}

QJsonObject UserParser::getCsgoStats()
{
    QJsonObject games = jsonObject_.value("games").toObject();
    return games.value("cs2").toObject();
}
