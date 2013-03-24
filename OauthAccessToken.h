#ifndef OAUTHACCESSTOKEN_H
#define OAUTHACCESSTOKEN_H

#include <QObject>
#include "OauthCode.h"
#include "NetworkManager.h"

class OauthAccessToken : public QObject
{
  Q_OBJECT
public:
  explicit OauthAccessToken(QObject *parent = 0);
  
signals:
  
public slots:
  void getAccessToekn(const QString &code);

private:
  OauthCode *getCode;

};

#endif // OAUTHACCESSTOKEN_H
