#include "matchurlbreaker.h"

matchUrlBreaker::matchUrlBreaker(QString &matchUrl)
{
    QStringList l = matchUrl.split('/');
    qDebug() << l;
    matchId_ = l.at(-1);
}

QString matchUrlBreaker::getMatchId()
{
    return matchId_;
}
