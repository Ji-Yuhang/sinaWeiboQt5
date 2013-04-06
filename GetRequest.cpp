#include "GetRequest.h"
#include "OauthCode.h"
#include "OauthAccessToken.h"
#include "JsonParser.h"

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
    QHttpMultiPart multiPart(QHttpMultiPart::FormDataType);
    QList<QHttpPart> partList = apiRequest->setPostMultiPart();
    for (int i = 0; i < partList.size(); i++)
      multiPart.append(partList.at(i));

    responseStr = manager->postMethod(apiRequest->getUrl(), multiPart);
  }
  QString error;
  JsonParser parser(responseStr);

  QJsonObject responseMap = parser.getJsonObject();
  if (responseMap.isEmpty())
    error = responseStr;
  else
    error = apiRequest->parse(responseMap);
  emit sendLog(apiRequest->getUrl().toString(), QDateTime::currentDateTime(),
               responseMap, error);
}
