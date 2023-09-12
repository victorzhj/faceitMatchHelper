#include "model.h"



Model::Model()
{

}

void Model::updateMatchWinRates(QString matchUrl)
{
    getMapWinRates(matchUrl);
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

QMap<team, QMap<map, winRates>> Model::getMapWinRates(QString &matchUrl)
{
    QMap<team, QMap<map, winRates>> mapWinRates;
    MatchUrlBreaker UrlBreaker(matchUrl);
    QString matchId = UrlBreaker.getMatchId();
    UrlCreator urlCreator;
    Networker networker;

    QUrl url = urlCreator.createMatchUrl(matchId);
    QString json = networker.requestData(url);

    MatchParser matchParser;
    QMap<QString, QVector<QString>> teams = matchParser.getMatchPlayersPerTeam(json);
    // Go through each team
    for (auto team = teams.cbegin(), end = teams.cend(); team != end; team++)
    {
        // QMap<map, QVector<winRates>> tempMap;
        QMap<map, winRates> tempMapWinRate;
        // Go through each player on that team
        for (QString player : team.value())
        {
            QUrl playerUrl = urlCreator.createUserWinRateUrl(player);
            QString playerWinRateJson = networker.requestData(playerUrl);
            UserWinRateParser userWinRateParser(playerWinRateJson);
            QMap<QString, winRates> playerWinRatePerMap = userWinRateParser.getWinpercentage();
            // Go through that players winrates per map
            for (auto map = playerWinRatePerMap.cbegin(), end = playerWinRatePerMap.cend(); map != end; map++)
            {
                tempMapWinRate[map.key()] += map.value();
                //tempMap[map.key()].append(map.value());
                /**
                if (tempMap.find(map.key()) != tempMap.end())
                {
                    tempMap.value(map.key()).append(map.value());
                }
                else
                {

                }
                */
            }
        }
        // Go through each map winrate of the team and get the average
        for (auto map = tempMapWinRate.cbegin(), end = tempMapWinRate.cend(); map != end; map++)
        {
            tempMapWinRate[map.key()] = map.value() / 5 * 100;
            qDebug() << map.key();
            qDebug() << tempMapWinRate[map.key()];
        }
        mapWinRates.insert(team.key(), tempMapWinRate);
    }
    return mapWinRates;
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
