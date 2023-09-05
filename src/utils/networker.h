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


class Networker : public QObject
{
public:
    /**
     * @brief Networker. Used to get JSON data from faceit REST API.
     */
    Networker();

    /**
     * @brief requestData. Method used to request data from faceit REST API.
     * @param url. The url of the requested data.
     * @return The json data as QString.
     */
    QString requestData(const QUrl &url);
private:
    QNetworkAccessManager *manager;
    QNetworkRequest request;

    QString token_ ="f4bd0606-7ff9-4925-aabf-82fc21c819ef";
    QString APIkey_ = "Bearer " + token_;
};

#endif // NETWORKER_H
