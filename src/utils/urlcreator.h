#ifndef URLCREATOR_H
#define URLCREATOR_H

#include <QString>
#include <QUrl>

class UrlCreator
{
public:
    UrlCreator();
    QUrl createMatchUrl(const QString &matchId);
    QUrl createUserUrl(const QString &userName);
    QUrl createUserStatsUrl(const QString &userId);

private:
    QString body = "https://open.faceit.com/data/v4/";
};

#endif // URLCREATOR_H
