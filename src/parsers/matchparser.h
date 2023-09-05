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
    /**
     * @brief MatchParser. Class used to parse match data.
     */
    MatchParser();

    /**
     * @brief getMatchPlayersPerTeam. Class method that returns each player per team.
     * @param file. The match.
     * @return QMap where the key is the team and value is a QVector of player ids
     */
    QMap<QString, QVector<QString>> getMatchPlayersPerTeam(QString &file);
    bool validateFile(QString &file);

private:
    /**
     * @brief getPlayersId. Gets single team's player ids
     * @param faction. The team.
     * @return QVector where the values are the id.
     */
    QVector<QString> getPlayersId(QJsonObject &faction);

};

#endif // MATCHPARSER_H
