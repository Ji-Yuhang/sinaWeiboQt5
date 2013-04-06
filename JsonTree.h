#ifndef JSONTREE_H
#define JSONTREE_H

#include <QVariantMap>
#include <QTreeWidget>
#include <QJsonObject>

class JsonTree
{
public:
    JsonTree(QTreeWidget *widget, const QJsonObject &object);
private:
  void parseObject(const QJsonObject &object, QTreeWidgetItem *parent = NULL);
  void parseJsonValue(const QJsonValue &jsonValue, int column, QTreeWidgetItem *node);
  QJsonObject responseObject;
  QTreeWidget *treeWidget;

};

#endif // JSONTREE_H
