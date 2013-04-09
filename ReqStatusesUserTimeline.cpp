#include "ReqStatusesUserTimeline.h"

void ReqStatusesUserTimeline::setKeyValueUrl()
{
  addKeyValueInUrl("access_token", Constraint::AccessToken);
  addKeyValueInUrl("count", "10");
}


ReqStatusesUserTimeline::ReqStatusesUserTimeline()
{
}

QString ReqStatusesUserTimeline::parse(const QJsonObject &response)
{
  Q_UNUSED(response);
  return "";
}
