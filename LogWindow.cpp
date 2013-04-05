#include "LogWindow.h"

LogWindow::LogWindow()
{
  setupUi(this);
  proxyModel.setSourceModel(&sourceModel);
  proxyModel.setDynamicSortFilter(true);
  proxyModel.setFilterKeyColumn(2);
  tableView->setModel(&proxyModel);
  // tableView->resizeColumnsToContents();
  tableView->horizontalHeader()->stretchLastSection();
  // tableView->setSelectionMode(QAbstractItemView::SingleSelection);
  tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

  connect(listWidget, SIGNAL(currentRowChanged(int)), SLOT(proxyModelFilterChanged(int)));
  connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
          SLOT(viewRowChanged(QModelIndex,QModelIndex)));

  connect(this, SIGNAL(sendLogData(QString,QDateTime,QString,QString)),
          &sourceModel, SLOT(addLogData(QString,QDateTime,QString,QString)));
}

void LogWindow::proxyModelFilterChanged(int index)
{
  switch (index) {
    case 0:
      proxyModel.setFilterWildcard("*");
      break;
    case 1:
      proxyModel.setFilterWildcard("Right");
      break;
    case 2:
      proxyModel.setFilterWildcard("Wrong");
      break;
    default:
      break;
  }
}

void LogWindow::viewRowChanged(const QModelIndex &current, const QModelIndex &prev)
{
  Q_UNUSED(prev);
  QModelIndex srcIndex = proxyModel.mapToSource(current);
  if (!srcIndex.isValid())
    return;

  int index = srcIndex.row();
  errorString->setText(sourceModel.errorStr(index));
  responseString->setText(sourceModel.responseStr(index));

}
