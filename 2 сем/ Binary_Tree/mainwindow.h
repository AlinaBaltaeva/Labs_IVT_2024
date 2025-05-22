#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Tree.h"
#include "treewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onInsertClicked();
    void onRemoveClicked();
    void onBalanceClicked();
    void onClearClicked();

private:
    Ui::MainWindow *ui;
    BinaryTree m_tree;
    TreeWidget* m_treeWidget;
};

#endif // MAINWINDOW_H
