#include "OauthAccessToken.h"
#include "NetworkManager.h"
#include "Constraint.h"
#include "JsonParser.h"
#include <QtCore>

OauthAccessToken::OauthAccessToken(QObject *parent) :
  QObject(parent)
{
  getCode = new OauthCode;
  connect(getCode , SIGNAL(sendWeiboCode(QString)), SLOT(getAccessToekn(QString)));
  getCode->exec();
}

bool OauthAccessToken::isHttpGet()
{
  return false;
}

QString OauthAccessToken::parse(const QByteArray &responseStr)
{
  JsonParser parser(responseStr);
  qDebug() << responseStr;
  QVariantMap responseMap = parser.getJsonMap();
  QString accessToken = responseMap["access_token"].toString();
  if (accessToken.isEmpty()) {
    return "error AccessToken:\t";
  }
  Constraint::AccessToken = accessToken;
  Constraint::ExpiresIn = responseMap["expires_in"].toString();
  qDebug() << "expires_in is:\t" << Constraint::ExpiresIn ;
  return "";
}

void OauthAccessToken::getAccessToekn(const QString &apiCode)
{
  addKeyValueInUrl("code", apiCode);
  qDebug() << "apicode is:\t" << apiCode;

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
