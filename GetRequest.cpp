#include "GetRequest.h"
#include "OauthCode.h"
#include "OauthAccessToken.h"

GetRequest::GetRequest(QObject *parent)
  : QObject(parent)
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
  QString error;
  error = apiRequest->parse(responseStr);
  emit sendLog(apiRequest->getUrl().toString(), QDateTime::currentDateTime(),
               QString::fromUtf8(responseStr), error);
}
