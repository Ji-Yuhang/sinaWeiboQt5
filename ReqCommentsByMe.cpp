#include "ReqCommentsByMe.h"

void ReqCommentsByMe::setKeyValueUrl()
{
  addKeyValueInUrl("access_token", Constraint::AccessToken);
  addKeyValueInUrl("count", "10");
}


ReqCommentsByMe::ReqCommentsByMe()
{
}

QString ReqCommentsByMe::parse(const QJsonObject &response)
{
  Q_UNUSED(response);
  return "";
}
