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
  setKeyValueUrl();
  QMapIterator<QString, QString> i(keyValueUrl);
  while (i.hasNext()) {
    i.next();
    urlStr += QString("%1=%2&").arg(i.key()).arg(i.value()) ;
  }

  QUrl url(urlStr);
  if (!url.isValid()) {
    qDebug() << QString("Invalid URL: %1\n Pls check your WeiboApi code").arg(urlStr);
    exit(1);
  }
  qDebug() << url;
  return url;
}
