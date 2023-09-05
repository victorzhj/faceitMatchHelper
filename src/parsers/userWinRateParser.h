#ifndef USERWINRATEPARSER_H
#define USERWINRATEPARSER_H

#include <QMap>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSet>

class UserWinRateParser
{
public:
    /**
     * @brief UserWinRateParser. Parses user's winrates per map
     * @param file. The file of the user that is gotten with user id.
     */
    UserWinRateParser(const QString &file);

    /**
     * @brief getWinpercentage. Returns user's winrates in each competive map.
     * @return QMap where the key is the map and value is the win rate of that map.
     */
    QMap<QString, double> getWinpercentage();
private:
    QJsonDocument document_;
    QJsonObject jsonObject_;
};

#endif // USERWINRATEPARSER_H
