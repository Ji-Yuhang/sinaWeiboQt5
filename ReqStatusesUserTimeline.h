#ifndef REQSTATUSESUSERTIMELINE_H
#define REQSTATUSESUSERTIMELINE_H

#include "AbstractWeiboApi.h"

class ReqStatusesUserTimeline : public AbstractWeiboApi
{
public:
  ReqStatusesUserTimeline();
  bool isHttpGet() { return true; }
  virtual QString parse(const QJsonObject &response);

private:
  virtual QString setApiUrlSuffix() {
    return "/2/statuses/user_timeline.json";
  }

  virtual void setKeyValueUrl();
};

#endif // REQSTATUSESUSERTIMELINE_H
