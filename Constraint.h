#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include <QString>

class Constraint
{
  public:
  const static QString WeiboApiUrl;
  const static QString AppKey;
  const static QString AppSecret;
  const static QString RedirectUrl;
  const static QString OauthGetCodeUrl;
  static QString AccessToken;
  static QString ExpiresIn;

};

#endif // CONSTRAINT_H
