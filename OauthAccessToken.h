#ifndef OAUTHACCESSTOKEN_H
#define OAUTHACCESSTOKEN_H

#include <QtCore/QObject>
#include "OauthCode.h"
#include "AbstractWeiboApi.h"
#include <QtNetwork/QHttpMultiPart>

class OauthAccessToken : public QObject, public AbstractWeiboApi
{
  Q_OBJECT
public:
  explicit OauthAccessToken(QObject *parent = 0);
  virtual bool isHttpGet();
  QString parse(const QByteArray &responseStr);

signals:
  
public slots:
  void getAccessToekn(const QString &apiCode);

private:
  virtual QString setApiUrlSuffix();
  virtual void setKeyValueUrl();
  OauthCode *getCode;

};

#endif // OAUTHACCESSTOKEN_H
