#ifndef OAUTHCODE_H
#define OAUTHCODE_H

#include <QtWidgets/QDialog>

class QWebView;
class QUrl;

class OauthCode : public QDialog
{
  Q_OBJECT
public:
  explicit OauthCode(QDialog *parent = 0);
  virtual ~OauthCode();

signals:
  void sendWeiboCode(const QString &code);
private slots:
  void printUrl(const QUrl &url);

private:
  QWebView *view;
  void deleteWebView();

};

#endif // OAUTHCODE_H
