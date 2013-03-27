#include "OauthAccessToken.h"
#include "GetRequest.h"
#include <QtWidgets/QApplication>


int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  GetRequest request;
  OauthAccessToken xxx;
  request.exec(&xxx);
  return app.exec();
}
