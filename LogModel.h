#ifndef LOGMODEL_H
#define LOGMODEL_H

#include <QtCore/QDateTime>
#include <QtCore/QObject>
#include <QtCore/QAbstractTableModel>
#include <QtCore/QDateTime>
#include <QtCore/QJsonObject>

class LogData
{
public:
  QDateTime timeLine;
  QString url;
  QJsonObject responseObject;
  QString errorStr;
};

class LogModel : public QAbstractTableModel
{
  Q_OBJECT

public:
  LogModel(QObject *parent = 0);
  int rowCount(const QModelIndex &parent) const;
  int columnCount(const QModelIndex &parent) const;
  QVariant data(const QModelIndex &index, int role) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
  Qt::ItemFlags flags(const QModelIndex &index) const;
  bool insertRow(const LogData &data, int row);

  QString errorStr(const int index) {
    return modelList[index].errorStr;
  }

  QJsonObject responseObj(const int index) {
    return modelList[index].responseObject;
  }

private slots:
  void addLogData(const QString &url, const QDateTime &times, const QJsonObject &object,
               const QString &error);

private:
  QList<LogData> modelList;
};

#endif // LOGMODEL_H
