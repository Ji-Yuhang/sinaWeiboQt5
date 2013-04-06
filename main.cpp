#include "OauthAccessToken.h"
#include "GetRequest.h"
#include "LogWindow.h"
#include <QtWidgets/QApplication>

#include "ReqStatusesUpload.h"


int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  GetRequest request;
  LogWindow logwindow;
  QObject::connect(&request, SIGNAL(sendLog(QString,QDateTime,QJsonObject,QString)),
                   &logwindow, SIGNAL(sendLogData(QString,QDateTime,QJsonObject,QString)));
  logwindow.show();
  OauthAccessToken xxx;
  request.exec(&xxx);

  // test upload images....
  ReqStatusesUpload uploadpic;
  request.exec(&uploadpic);

  return app.exec();
}
