#include "OauthAccessToken.h"
#include "GetRequest.h"
#include "LogWindow.h"
#include <QtWidgets/QApplication>


int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  GetRequest request;
  LogWindow logwindow;
  QObject::connect(&request, SIGNAL(sendLog(QString,QDateTime,QString,QString)),
                   &logwindow, SIGNAL(sendLogData(QString,QDateTime,QString,QString)));
  logwindow.show();
  OauthAccessToken xxx;
  request.exec(&xxx);
  return app.exec();
}
