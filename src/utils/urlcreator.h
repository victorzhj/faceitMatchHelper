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

private:
    QString body = "https://open.faceit.com/data/v4/";
};

#endif // URLCREATOR_H
