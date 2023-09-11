#include "matchparser.h"


MatchParser::MatchParser()
{

}

QMap<QString, QVector<QString>> MatchParser::getMatchPlayersPerTeam(QString &file)
{
    QMap<QString, QVector<QString>> playersPerTeam;
    QJsonDocument document = QJsonDocument::fromJson(file.toUtf8());
    QJsonObject jsonObject = document.object();
    QJsonObject teams = jsonObject.value("teams").toObject();
    QJsonObject faction1 = teams.value("faction1").toObject();
    QJsonObject faction2 = teams.value("faction2").toObject();
    QVector<QString> team1 = getPlayersId(faction1);
    QVector<QString> team2 = getPlayersId(faction2);
    playersPerTeam.insert("team 1", team1);
    playersPerTeam.insert("team 2", team2);
    return playersPerTeam;
}

QVector<QString> MatchParser::getPlayersId(QJsonObject &faction)
{
    QVector<QString> playersIds;
    QJsonArray roster = faction.value("roster").toArray();
    foreach (const QJsonValue player, roster)
    {
        QJsonObject playerData = player.toObject();
        QString playerId = playerData.find("player_id")->toString();
        playersIds.append(playerId);
    }
    return playersIds;
}

