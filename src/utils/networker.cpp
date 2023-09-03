#include "networker.h"
#include <iostream>

Networker::Networker()
{

}

QString Networker::requestData(const QUrl &url)
{
    QString faceitReply;
    manager = new QNetworkAccessManager();
    QEventLoop loop;
    connect(manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization",  APIkey.toLocal8Bit());
    QNetworkReply *reply = manager->get(request);
    loop.exec();
    //qDebug() << reply->readAll();
    faceitReply = reply->readAll();
    qDebug() << faceitReply;
    return faceitReply;
}
