#include "GetRequest.h"

GetRequest::GetRequest()
{
  manager = NetworkManager::getSingleNetworkManager();
}

void GetRequest::exec(AbstractWeiboApi *apiRequest)
{
  QByteArray responseStr;
  if (apiRequest->isHttpGet())
    responseStr = manager->getMethod(apiRequest->getUrl());
  else {
    QHttpMultiPart multiPart;
    QList<QHttpPart> partList = apiRequest->setPostMultiPart();
    for (int i = 0; i < partList.size(); i++)
      multiPart.append(partList.at(i));

    responseStr = manager->postMethod(apiRequest->getUrl(), multiPart);
  }

  apiRequest->parse(responseStr);
}
