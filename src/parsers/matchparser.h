#ifndef MATCHPARSER_H
#define MATCHPARSER_H

#include <QMap>
#include <QVector>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class MatchParser
{
public:
    MatchParser();
    QMap<QString, QVector<QString>> getData(QString &file);
    bool validateFile(QString &file);

private:
    QVector<QString> getPlayersId(QJsonObject &faction);

};

#endif // MATCHPARSER_H
