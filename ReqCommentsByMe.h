#ifndef REQCOMMENTSBYME_H
#define REQCOMMENTSBYME_H

#include "AbstractWeiboApi.h"

class ReqCommentsByMe : public AbstractWeiboApi
{
public:
  ReqCommentsByMe();
  virtual bool isHttpGet() { return true; }
  virtual QString parse(const QJsonObject &response);

private:
  virtual QString setApiUrlSuffix() {
    return "/2/comments/by_me.json";
  }

  virtual void setKeyValueUrl();
};

#endif // REQCOMMENTSBYME_H
