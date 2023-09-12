#ifndef MATCHURLBREAKER_H
#define MATCHURLBREAKER_H

#include <QString>
#include <QStringList>
#include <QDebug>

class MatchUrlBreaker
{
public:
    /**
     * @brief MatchUrlBreaker. Takes the url of match and takes that match's id.
     * @param matchUrl. The url of the match.
     */
    MatchUrlBreaker(QString &matchUrl);

    /**
     * @brief getMatchId. Returns the id of the match
     * @return QString. Match id
     */
    QString getMatchId();

private:
    QString matchId_;
};

#endif // MATCHURLBREAKER_H
