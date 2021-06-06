#ifndef FORM_H
#define FORM_H

#include "treemodel.h"
#include "treemodelsorter.h"

#include <QWidget>
#include <QFile>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;
    TreeModel* model;
    TreeModelSorter* sorter;
};

#endif // FORM_H
