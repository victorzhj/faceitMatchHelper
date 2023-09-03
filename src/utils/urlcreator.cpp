#include "urlcreator.h"

UrlCreator::UrlCreator()
{

}

QUrl UrlCreator::createMatchUrl(const QString &matchId)
{
    QString url = body + "matches/" + matchId;
    return QUrl(url);
}

QUrl UrlCreator::createUserUrl(const QString &userName)
{
    QString url = body + "players?nickname?=" + userName;
    return QUrl(url);
}

QUrl UrlCreator::createUserStatsUrl(const QString &userId)
{
    QString url = body + "players/" + userId + "/stats/csgo";
    return QUrl(url);
}
