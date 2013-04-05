#include "LogModel.h"
#include <QtCore>

LogModel::LogModel(QObject *parent)
  : QAbstractTableModel(parent)
{
}

int LogModel::rowCount(const QModelIndex &parent) const
{
  Q_UNUSED(parent);
  return modelList.size();
}

int LogModel::columnCount(const QModelIndex &parent) const
{
  Q_UNUSED(parent);
  return 3;
}

QVariant LogModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  if (role == Qt::TextAlignmentRole)
    return int(Qt::AlignLeft | Qt::AlignVCenter);

  if (role == Qt::DisplayRole) {
    LogData tmp = modelList.at(index.row());
    switch (index.column()) {
      case 0:
        return tmp.timeLine.toString("yyyy-MM-dd hh:mm:ss");
      case 1:
        return tmp.url;
      case 2:
        if (tmp.errorStr.isEmpty())
          return "Right";
        else
          return "Wrong";
      default:
        qDebug() << "in logModel,sth. wrong";
    }
  }
  return QVariant();
}


QVariant LogModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
    if (section == 0)
      return "TimeLine";
    else if (section == 1)
      return "Request Url";
    else if (section == 2)
      return "isRight";
  }

  if (orientation == Qt::Vertical && role == Qt::DisplayRole)
    return QString::number(section + 1);

  return QVariant();
}

Qt::ItemFlags LogModel::flags(const QModelIndex &index) const
{
  Qt::ItemFlags flags = QAbstractTableModel::flags(index);
  return flags;
}

bool LogModel::insertRow(const LogData &data, int row)
{
  beginInsertRows(QModelIndex(), row, row);
  modelList.append(data);
  endInsertRows();
  return true;
}

void LogModel::addLogData(const QString &url, const QDateTime &times, const QString &responseStr, const QString &error)
{
  LogData tmp;
  tmp.url = url;
  tmp.timeLine = times;
  tmp.responseStr = responseStr;
  tmp.errorStr = error;

  insertRow(tmp, rowCount(QModelIndex()));
}
