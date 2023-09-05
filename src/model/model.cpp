#include "model.h"

QMap<team, QMap<map, QVector<winRates>>> mapWinRates;

Model::Model()
{

}

int Model::getElo(const QString &playerName)
{
    UserParser userInfo = getUserParserObject(playerName);
    return userInfo.getFaceitElo();

}

int Model::getSkilLevel(const QString &playerName)
{
    UserParser userInfo = getUserParserObject(playerName);
    return userInfo.getSkillLevel();
}

QMap<QString, QString> Model::getMapWinRates(QString &matchUrl)
{
    MatchUrlBreaker UrlBreaker(matchUrl);
    QString matchId = UrlBreaker.getMatchId();
    UrlCreator urlCreator;
    Networker networker;

    QUrl url = urlCreator.createMatchUrl(matchId);
    QString json = networker.requestData(url);

    MatchParser matchParser;
    QMap<QString, QVector<QString>> teams = matchParser.getMatchPlayersPerTeam(json);

    for (QVector<QString> team : teams)
    {

    }

}

UserParser Model::getUserParserObject(const QString &playerName)
{
    UrlCreator urlCreator;
    Networker networker;

    QUrl url = urlCreator.createUserUrl(playerName);
    QString json = networker.requestData(url);
    UserParser userInfo(json);
    return userInfo;
}
