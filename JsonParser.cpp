#include "JsonParser.h"
#include <QtCore>

JsonParser::JsonParser( const QByteArray &jsonText ,QObject *parent)
  : QObject(parent)
{
  QJsonDocument document = QJsonDocument::fromJson(jsonText, &error);
  if (error.error != QJsonParseError::NoError) {
    qDebug() << "Invalid json String:\t" << error.errorString();
    return;
  }
  if (document.isObject()) {
    jsonObject = document.object();
  } else {
    qDebug() << "weibo api always return a jsonObject,not other. some wrong here";
    qDebug() << "the jsonText in JsonParser is:\n" << jsonText;
  }
}

JsonParser::~JsonParser()
{
}
