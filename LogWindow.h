#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtCore/QSortFilterProxyModel>
#include "ui_LogWindow.h"
#include "LogModel.h"

class LogWindow : public QMainWindow, private Ui::LogWindow
{
  Q_OBJECT
public:
  explicit LogWindow();
  
signals:
  void sendLogData(const QString &url, const QDateTime &times, const QJsonObject &object,
                  const QString &error);

public slots:

private slots:
  void proxyModelFilterChanged(int index);
  void viewRowChanged(const QModelIndex &current, const QModelIndex &prev);
private:
  LogModel sourceModel;
  QSortFilterProxyModel proxyModel;
};

#endif // LOGWINDOW_H
