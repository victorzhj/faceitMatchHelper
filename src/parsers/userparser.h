#ifndef USERPARSER_H
#define USERPARSER_H

#include <QString>
#include <QVector>
#include <QJsonDocument>
#include <QJsonObject>

class UserParser
{
public:
    /**
     * @brief UserParser. Parses single users data.
     * @param file. File of player that is gotten with user nickname.
     */
    UserParser(const QString &file);

    /**
     * @brief getImageUrl. Return a link to profile picture of the user.
     * @return Link to user's profile picture.
     */
    QString getImageUrl();

    /**
     * @brief getSkillLevel. Return user's current faceit level in csgo.
     * @return Int. The current faceit level of user.
     */
    int getSkillLevel();

    /**
     * @brief getFaceitElo. Return user's current faceit elo in csgo
     * @return Int. The current faceit elo of user.
     */
    int getFaceitElo();
private:
    /**
     * @brief getCsgoStats. Helper method to get user data
     * @return QJsonObject. User's current csgo stats in faceit.
     */
    QJsonObject getCsgoStats();

    /**
     * @brief document_
     */
    QJsonDocument document_;
    QJsonObject jsonObject_;
};

#endif // USERPARSER_H
