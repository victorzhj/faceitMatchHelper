#ifndef NETWORKER_H
#define NETWORKER_H

#include <QString>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class Networker
{
public:
    Networker();
    QString requestData(const QUrl &url);
};

#endif // NETWORKER_H
