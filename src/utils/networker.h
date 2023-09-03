#ifndef NETWORKER_H
#define NETWORKER_H

#include <QString>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>
#include <QObject>
#include <QEventLoop>
#include <fstream>

class Networker : public QObject
{
public:
    Networker();
    QString requestData(const QUrl &url);
private:
    QNetworkAccessManager *manager;
    QNetworkRequest request;

    QString token ="f4bd0606-7ff9-4925-aabf-82fc21c819ef";
    QString APIkey = "Bearer " + token;
};

#endif // NETWORKER_H
