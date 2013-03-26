#include "NetworkManager.h"
#include "Constraint.h"
#include <QtCore>
#include <QtNetwork>

NetworkManager *NetworkManager::manager = NULL;
QNetworkAccessManager *NetworkManager::qAccessManager = NULL;
QMutex NetworkManager::lock;

NetworkManager::NetworkManager(QObject *parent) :
  QObject(parent)
{
}

NetworkManager *NetworkManager::getSingleNetworkManager()
{
  if (manager == NULL) {
    QMutexLocker locker(&lock);
    if (manager == NULL) {
      manager = new NetworkManager;
      qAccessManager = new QNetworkAccessManager;
    }
  }
  return manager;
}

QByteArray NetworkManager::getMethod(const QUrl &url)
{
  QNetworkRequest request(url);
  QNetworkReply *reply = qAccessManager->get(request);
  return getReplyStr(reply);
}

QByteArray NetworkManager::postMethod(const QUrl &url, QHttpMultiPart &parts )
{
  QNetworkRequest request(url);
  // TODO: header may be changed by some API, maybe!
  request.setHeader(QNetworkRequest::ContentTypeHeader,
                    "application/x-www-form-urlencoded");
  QNetworkReply *reply = qAccessManager->post(request, &parts);
  return getReplyStr(reply);
}

QByteArray NetworkManager::getReplyStr(QNetworkReply *reply)
{
  QEventLoop loop;
  connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
  loop.exec();
  QByteArray tmp = reply->readAll();
  reply->deleteLater();
  return tmp;
}
