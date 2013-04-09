#include "ReqFriendshipsFriends.h"

ReqFriendshipsFriends::ReqFriendshipsFriends()
{
}

QString ReqFriendshipsFriends::parse(const QJsonObject &response)
{
  Q_UNUSED(response);
  return "";
}

void ReqFriendshipsFriends::setKeyValueUrl()
{
  addKeyValueInUrl("access_token", Constraint::AccessToken);
  addKeyValueInUrl("count", "10");
  addKeyValueInUrl("screen_name", QString::fromUtf8("sd44农场"));
}
