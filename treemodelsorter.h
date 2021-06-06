#ifndef TREEMODELSORTER_H
#define TREEMODELSORTER_H

#include <QObject>
#include <QSortFilterProxyModel>

class TreeModelSorter : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit TreeModelSorter(QObject *parent = nullptr);
    ~TreeModelSorter();

public:
    virtual bool filterAcceptsRow(int sourceRow, QModelIndex const& sourceParent) const override;
};

#endif // TREEMODELSORTER_H