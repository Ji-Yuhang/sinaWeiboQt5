#include "AbstractWeiboApi.h"
#include "Constraint.h"
#include <QtCore>

AbstractWeiboApi::AbstractWeiboApi()
{
}

QUrl AbstractWeiboApi::getUrl()
{
  QString urlStr = Constraint::WeiboApiUrl + setApiUrlSuffix();

  urlStr += "?";
  QMapIterator<QString, QString> i(keyValueUrl);
  while (i.hasNext()) {
    i.next();
    urlStr += QString("%1=%2&").arg(i.key()).arg(i.value()) ;
  }
  if (Constraint::AccessToken == "") {
    qDebug() << "NULL AccessToken, pls check your code";
    exit(1);
  }
  urlStr += QString("access_token=") + Constraint::AccessToken;

  QUrl url(urlStr);
  if (!url.isValid()) {
    qDebug() << QString("Invalid URL: %1\n Pls check your WeiboApi code").arg(urlStr);
    exit(1);
  }
  return url;
}
