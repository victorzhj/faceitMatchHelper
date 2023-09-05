#include "matchurlbreaker.h"

MatchUrlBreaker::MatchUrlBreaker(QString &matchUrl)
{
    QStringList l = matchUrl.split('/');
    qDebug() << l;
    matchId_ = l.at(-1);
}

QString MatchUrlBreaker::getMatchId()
{
    return matchId_;
}
