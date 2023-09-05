#include "urlcreator.h"

UrlCreator::UrlCreator()
{

}

QUrl UrlCreator::createMatchUrl(const QString &matchId)
{
    QString url = body_ + "matches/" + matchId;
    return QUrl(url);
}

QUrl UrlCreator::createUserUrl(const QString &userName)
{
    QString url = body_ + "players?nickname?=" + userName;
    return QUrl(url);
}

QUrl UrlCreator::createUserWinRateUrl(const QString &userId)
{
    QString url = body_ + "players/" + userId + "/stats/csgo";
    return QUrl(url);
}
