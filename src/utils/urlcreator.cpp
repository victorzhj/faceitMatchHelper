#include "urlcreator.h"

UrlCreator::UrlCreator()
{

}

QUrl UrlCreator::createMatchUrl(QString matchId)
{
    QString url = body + "matches/" + matchId;
    return QUrl(url);
}

QUrl UrlCreator::createUserUrl(QString userName)
{
    QString url = body + "players?nickname?=" + userName;
    return QUrl(url);
}
