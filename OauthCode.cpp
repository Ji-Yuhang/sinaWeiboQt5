#include "OauthCode.h"

#include <QtGui>
#include <QSslSocket>
#include <QtWebKitWidgets>
#include <QtWidgets>
#include "Constraint.h"


OauthCode::OauthCode(QDialog *parent)
  : QDialog(parent)
{

  if (!QSslSocket::supportsSsl()) {
    qDebug() << "Sina Weibo requires SSL support.";
    exit(1);
  }

  view = new QWebView;
  connect(view, SIGNAL(urlChanged(QUrl)), SLOT(printUrl(QUrl)));
  view->setContextMenuPolicy(Qt::NoContextMenu);
  view->load(QUrl(Constraint::OauthGetCodeUrl));

  QHBoxLayout xx;
  xx.addWidget(view, 1);
  xx.addSpacing(1);
  setLayout(&xx);
}

OauthCode::~OauthCode()
{
}

void OauthCode::printUrl(const QUrl &url)
{
  QString tmp = url.toString();
  if (tmp.contains(Constraint::RedirectUrl) &&
      tmp.contains("code=")) {
    view->hide();
    emit sendWeiboCode(tmp.mid(tmp.lastIndexOf('=') + 1));
  }
}

