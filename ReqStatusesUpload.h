#ifndef REQSTATUSESUPLOAD_H
#define REQSTATUSESUPLOAD_H

#include "AbstractWeiboApi.h"

class ReqStatusesUpload : public AbstractWeiboApi
{
public:
  ReqStatusesUpload();
  virtual bool isHttpGet() { return false; }
  virtual QList<QHttpPart> setPostMultiPart();
  virtual QString parse(const QByteArray &responseStr);

private:
  virtual QString setApiUrlSuffix() {
    return "/2/statuses/upload.json";
  }

  virtual void setKeyValueUrl();
};

#endif // REQSTATUSESUPLOAD_H
