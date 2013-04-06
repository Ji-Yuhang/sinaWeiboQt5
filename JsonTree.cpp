#include "JsonTree.h"
#include <QtCore>

JsonTree::JsonTree(QTreeWidget *widget, const QJsonObject &object)
{
  treeWidget = widget;
  responseObject = object;
  parseObject(responseObject);
}

void JsonTree::parseObject(const QJsonObject &object, QTreeWidgetItem *parent)
{
  QStringList objectKeys = object.keys();
  QTreeWidgetItem *child;
  for (int i = 0; i < objectKeys.size(); i++) {

    if (parent == NULL)
      child = new QTreeWidgetItem(treeWidget);
    else
      child = new QTreeWidgetItem(parent);

    child->setText(0, objectKeys[i]);
    QJsonValue value = object[objectKeys.at(i)];
    parseJsonValue(value, 1, child);
  }
}

void JsonTree::parseJsonValue(const QJsonValue &jsonValue, int column, QTreeWidgetItem *node)
{
  QString valueStr;

  QJsonArray  array;
  switch (jsonValue.type()) {
  case QJsonValue::Bool:
    valueStr = jsonValue.toBool() ? "True" : "False";
    node->setText(column, valueStr);
    break;
  case QJsonValue::String:
    valueStr = jsonValue.toString();
    node->setText(column, valueStr);
    break;
  case QJsonValue::Double:
    valueStr = QString::number(jsonValue.toDouble());
    node->setText(column, valueStr);
    break;
  case QJsonValue::Null:
    valueStr = "NULL";
    node->setText(column, valueStr);
    break;
  case QJsonValue::Undefined:
    qDebug() << "Undefined Json Value, check your request";
    break;
  case QJsonValue::Array:
    // Array used Key(array.at(i)) ：null
    array = jsonValue.toArray();
    for (int i = 0; i < array.size(); i++) {
      parseJsonValue(array[i], 0, new QTreeWidgetItem(node));
    }
    break;
  case QJsonValue::Object:
    parseObject(jsonValue.toObject(), node);
    break;
  default:
    qDebug() << "what's the fucking in parseJsonValue default";
    break;
  }
}
