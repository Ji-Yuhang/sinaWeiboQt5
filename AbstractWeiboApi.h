#ifndef ABSTRACTWEIBOAPI_H
#define ABSTRACTWEIBOAPI_H

#include <QtCore/QUrl>
#include <QtCore/QMap>
#include <QtNetwork/QHttpMultiPart>

class AbstractWeiboApi
{
public:
  explicit AbstractWeiboApi();

  /**
   * @brief is Http Get method?
   * @return if the Api use Http Get method, return true. if Post method, return false;
   */
  virtual bool isHttpGet() = 0;
  QUrl getUrl();

  /**
   * @brief  set the http post method's body.
   * You don't need to achieve this function if Api don't use http body
   */
  virtual QList<QHttpPart> setPostMultiPart() {
    QList<QHttpPart> xx;
    return xx;
  }

  void addKeyValueInUrl(const QString &key, const QString &value) {
    keyValueUrl.insert(key, value);
  }

  // return error string
  virtual QString parse(const QByteArray &responseStr) = 0;

signals:
  
public slots:

private:

  /**
   * @brief set the Api UrlSuffix.
   * the complete Url = Constraint::WeiboApiUrl + suffix.
   * eg: the suffix of Api Url 'https://api.weibo.com/2/users/show.json' is '/2/users/show.json'.
   * in this eg, must be return '/2/users/show.json'
   */
  virtual QString setApiUrlSuffix() = 0;

  /**
   * @brief set Key Value
   * eg. https://api.weibo.com/2/users/show.json?id=333
   * in this func,must use func: addKeyValueInUrl("id", "333")
   */
  virtual void setKeyValueUrl() = 0;


  QMap<QString, QString> keyValueUrl;
  
};

#endif // ABSTRACTWEIBOAPI_H
