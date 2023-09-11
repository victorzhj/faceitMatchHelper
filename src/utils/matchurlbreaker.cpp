#include "matchurlbreaker.h"

MatchUrlBreaker::MatchUrlBreaker(QString &matchUrl)
{
    QStringList l = matchUrl.split('/');
    if (l.isEmpty())
    {
        matchId_ = "NO VALUE";
        return;
    }
    matchId_ = l.back();
    // qDebug() << matchId_;
}

QString MatchUrlBreaker::getMatchId()
{
    return matchId_;
}
