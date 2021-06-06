#include "form.h"
#include "treemodel.h"
#include "ui_form.h"

#include <QFile>
#include <QTreeView>

Form::Form(QWidget *parent)
    : QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this);

    QFile file(":/default.txt");
    file.open(QIODevice::ReadOnly);
    model = new TreeModel(file.readAll());
    file.close();

    sorter = new TreeModelSorter(this);
    // QRegularExpression regularExpression(ui->lineEdit->text().toLower(), QRegularExpression::PatternOptions());
    // sorter->setFilterRegularExpression(regularExpression);
    sorter->setSourceModel(model);

    ui->treeView->setModel(sorter);
    ui->treeView->setWindowTitle(QObject::tr("Simple Tree Model"));
    ui->treeView->show();

    connect(ui->lineEdit, &QLineEdit::textChanged, sorter, static_cast<void (TreeModelSorter::*)(const QString &)>(&TreeModelSorter::setFilterRegularExpression));
}

Form::~Form()
{
    delete model;
    delete sorter;
    delete ui;
}
