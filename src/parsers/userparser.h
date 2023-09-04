#ifndef USERPARSER_H
#define USERPARSER_H

#include <QString>
#include <QVector>
#include <QJsonDocument>
#include <QJsonObject>

class UserParser
{
public:
    UserParser(const QString &file);
    QString getImageUrl();
    int getSkillLevel();
    int getFaceitElo();
private:
    QJsonObject getCsgoStats();

    QJsonDocument document_;
    QJsonObject jsonObject_;
};

#endif // USERPARSER_H
