#include "treemodelsorter.h"

TreeModelSorter::TreeModelSorter(QObject *parent)
    : QSortFilterProxyModel(parent)
{
}

TreeModelSorter::~TreeModelSorter()
{
}

bool TreeModelSorter::filterAcceptsRow(int sourceRow, QModelIndex const &sourceParent) const
{
    // check the current item
    bool result = QSortFilterProxyModel::filterAcceptsRow(sourceRow, sourceParent);
    QModelIndex currntIndex = sourceModel()->index(sourceRow, 0, sourceParent);
    if (sourceModel()->hasChildren(currntIndex))
    {
        // if it has sub items
        for (int i = 0; i < sourceModel()->rowCount(currntIndex) && !result; ++i)
        {
            // keep the parent if a children is shown
            result = result || filterAcceptsRow(i, currntIndex);
        }
    }
    return result;
}