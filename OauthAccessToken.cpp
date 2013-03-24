#include "OauthAccessToken.h"
#include "NetworkManager.h"
#include "Constraint.h"

#include <QtNetwork>
#include <QtCore>

OauthAccessToken::OauthAccessToken(QObject *parent) :
  QObject(parent)
{
  getCode = new OauthCode;
  connect(getCode, SIGNAL(sendWeiboCode(QString)), SLOT(getAccessToekn(QString)));
  getCode->show();
}


void OauthAccessToken::getAccessToekn(const QString &code)
{
  getCode->close();
  getCode->deleteLater();
  NetworkManager *manager = NetworkManager::getSingleNetworkManager();

  QByteArray tmp = manager->postMethod(QUrl(Constraint::GetTokenUrl + code));

  QJsonParseError errorMsg;
  QJsonDocument jsonDoc = QJsonDocument::fromJson(tmp, &errorMsg);
  if (errorMsg.error != QJsonParseError::NoError) {
    qDebug() << errorMsg.errorString();
  }
}
