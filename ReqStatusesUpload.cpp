#include "ReqStatusesUpload.h"
#include <QtCore>

ReqStatusesUpload::ReqStatusesUpload()
{
}

QList<QHttpPart> ReqStatusesUpload::setPostMultiPart()
{
  QList<QHttpPart> picPost;

  QHttpPart statusPart;
  statusPart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("text/plain"));
  statusPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"status\""));
  statusPart.setBody("哈哈哈，测试QT5-SINA-WEIBO-API");

  QHttpPart imagePart;
  imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));
  imagePart.setHeader(QNetworkRequest::ContentDispositionHeader,
                      QVariant("form-data; name=\"pic\"; filename=\"test.jpg\""));
  QFile *file = new QFile("/home/sd44/test.jpg");
  file->open(QIODevice::ReadOnly);
  imagePart.setBodyDevice(file);

  picPost.append(statusPart);
  picPost.append(imagePart);

  return picPost;
}

QString ReqStatusesUpload::parse(const QByteArray &responseStr)
{
  return "";
}


void ReqStatusesUpload::setKeyValueUrl()
{
  addKeyValueInUrl("access_token", Constraint::AccessToken);
}
