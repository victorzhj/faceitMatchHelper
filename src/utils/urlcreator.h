#ifndef URLCREATOR_H
#define URLCREATOR_H

#include <QString>
#include <QUrl>

class UrlCreator
{
public:
    /**
     * @brief UrlCreator. Class that creates the needed urls.
     */
    UrlCreator();

    /**
     * @brief createMatchUrl. Method that creates the needed url to get match's data.
     * @param matchId. The id of the match.
     * @return QUrl to get match's data.
     */
    QUrl createMatchUrl(const QString &matchId);

    /**
     * @brief createUserUrl. Method that creates the needed url to get user's data.
     * @param userName. The nickname of the user.
     * @return QUrl to get user's data.
     */
    QUrl createUserUrl(const QString &userName);

    /**
     * @brief createUserWinRateUrl. Method that creates the needed url to get user's winrates.
     * @param userId. The id of the user.
     * @return QUrl to get user's winrates.
     */
    QUrl createUserWinRateUrl(const QString &userId);

private:
    QString body_ = "https://open.faceit.com/data/v4/";
};

#endif // URLCREATOR_H
