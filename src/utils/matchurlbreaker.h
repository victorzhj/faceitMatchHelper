#ifndef MATCHURLBREAKER_H
#define MATCHURLBREAKER_H

#include <QString>
#include <QStringList>
#include <QDebug>

class matchUrlBreaker
{
public:
    matchUrlBreaker(QString &matchUrl);
    QString getMatchId();

private:
    QString matchId_;
};

#endif // MATCHURLBREAKER_H
