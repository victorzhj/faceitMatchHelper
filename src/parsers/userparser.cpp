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
    QJsonObject csgo = getCsgoStats();
    return csgo.value("skill_level").toInt();
}

int UserParser::getFaceitElo()
{
    QJsonObject csgo = getCsgoStats();
    return csgo.value("faceit_elo").toInt();
}

QJsonObject UserParser::getCsgoStats()
{
    QJsonObject games = jsonObject_.value("games").toObject();
    return games.value("csgo").toObject();
}
