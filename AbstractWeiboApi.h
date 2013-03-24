#ifndef ABSTRACTWEIBOAPI_H
#define ABSTRACTWEIBOAPI_H

#include <QObject>
#include <QUrl>
#include <QMap>

class AbstractWeiboApi : public QObject
{
  Q_OBJECT
public:
  explicit AbstractWeiboApi(QObject *parent = 0);

  /**
   * @brief is Http Get method?
   * @return if the Api use Http Get method, return true. if Post method, return false;
   */
  virtual bool isHttpGet() = 0;
  QUrl getUrl();

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
  virtual QString setKeyValueUrl() = 0;

  // TODO:  .
  void addKeyValueInUrl(const QString &key, const QString &value) {
    keyValueUrl.insert(key, value);
  }

  QMap<QString, QString> keyValueUrl;
  
};

#endif // ABSTRACTWEIBOAPI_H
