#ifndef USERSTATSPARSER_H
#define USERSTATSPARSER_H

#include <QMap>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSet>

class userStatsParser
{
public:
    userStatsParser(const QString &file);
    QMap<QString, QString> getWinpercentage();
private:
    QJsonDocument document_;
    QJsonObject jsonObject_;
};

#endif // USERSTATSPARSER_H
