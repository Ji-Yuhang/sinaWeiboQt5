#include "OauthAccessToken.h"
#include "NetworkManager.h"
#include "Constraint.h"
#include "JsonParser.h"
#include <QtCore>

OauthAccessToken::OauthAccessToken(QObject *parent) :
  QObject(parent)
{
  getCode = new OauthCode;
  connect(getCode, SIGNAL(sendWeiboCode(QString)), SLOT(getAccessToekn(QString)));
  getCode->show();
}

bool OauthAccessToken::isHttpGet()
{
  return false;
}

void OauthAccessToken::parse(const QByteArray &responseStr)
{
  JsonParser parser(responseStr);
  QVariantMap responseMap = parser.getJsonMap();
  QString accessToken = responseMap["access_token"].toString();
  if (accessToken.isEmpty()) {
    qDebug() << "error AccessToken:\t" << accessToken;
    exit(1);
  }
  Constraint::ExpiresIn = responseMap["expires_in"].toString();
}

void OauthAccessToken::getAccessToekn(const QString &apiCode)
{
  addKeyValueInUrl("code", apiCode);

  getCode->close();
  getCode->deleteLater();
}

QString OauthAccessToken::setApiUrlSuffix()
{
  return "/oauth2/access_token";
}

void OauthAccessToken::setKeyValueUrl()
{
  addKeyValueInUrl("client_id", Constraint::AppKey);
  addKeyValueInUrl("client_secret", Constraint::AppSecret);
  addKeyValueInUrl("grant_type", "authorization_code");
  addKeyValueInUrl("redirect_uri", Constraint::RedirectUrl);
}
