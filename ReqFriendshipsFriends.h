#ifndef REQFRIENDSHIPSFRIENDS_H
#define REQFRIENDSHIPSFRIENDS_H

#include "AbstractWeiboApi.h"

class ReqFriendshipsFriends : public AbstractWeiboApi
{
public:
  ReqFriendshipsFriends();
  bool isHttpGet() { return true; }
  virtual QString parse(const QJsonObject &response);

private:
  virtual QString setApiUrlSuffix() {
    return "/2/friendships/friends.json";
  }

  virtual void setKeyValueUrl();
};

#endif // REQFRIENDSHIPSFRIENDS_H
