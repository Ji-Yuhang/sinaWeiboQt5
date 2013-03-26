#ifndef GETREQUEST_H
#define GETREQUEST_H

#include "AbstractWeiboApi.h"
#include "NetworkManager.h"

class GetRequest
{
public:
  GetRequest();
  void exec(AbstractWeiboApi *apiRequest);
private:
  NetworkManager *manager;

};

#endif // GETREQUEST_H
