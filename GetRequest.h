#ifndef GETREQUEST_H
#define GETREQUEST_H

#include "AbstractWeiboApi.h"
#include "NetworkManager.h"
#include <QtCore/QDateTime>
#include <QtCore/QObject>

class GetRequest : public QObject
{
  Q_OBJECT
public:
  GetRequest(QObject *parent = 0);
  void exec(AbstractWeiboApi *apiRequest);

signals:
  void sendLog(const QString &url, const QDateTime &times, const QJsonObject &response,
               const QString &error);
private:
  NetworkManager *manager;


};

#endif // GETREQUEST_H
