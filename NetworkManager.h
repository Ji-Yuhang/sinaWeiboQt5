#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QMutexLocker>
#include <QtCore/QMutex>

class QUrl;
class QNetworkRequest;
class QNetworkReply;
class QNetworkAccessManager;
class QHttpMultiPart;

class  OauthCode;

class NetworkManager : public QObject
{
  Q_OBJECT
public:
  static NetworkManager *getSingleNetworkManager();


  QByteArray getMethod(const QUrl &url);

  QByteArray postMethod(const QUrl &url, QHttpMultiPart &parts);
  QByteArray postMethod(const QUrl &url);

  static QNetworkAccessManager *qAccessManager;

  
signals:
  
public slots:

private:
  explicit NetworkManager(QObject *parent = 0);
  NetworkManager(const NetworkManager &tmp);
  NetworkManager &operator=(const NetworkManager &tmp);

  // TODO: 暂时此类中均通过QEventLoop来实现网络同步，放弃了QNetworkManager的异步优势，日后是否能改进？
  QByteArray getReplyStr(QNetworkReply *reply);

  static QMutex lock;
  static NetworkManager *manager;
};

#endif // NETWORKMANAGER_H
