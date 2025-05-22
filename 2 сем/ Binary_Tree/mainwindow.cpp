#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаем виджет для отрисовки дерева
    m_treeWidget = new TreeWidget(this);
    ui->verticalLayout->insertWidget(0, m_treeWidget);
    m_tree.insert(50);
    m_tree.insert(30);
    m_tree.insert(70);
    m_tree.insert(20);
    m_tree.insert(40);
    m_tree.insert(60);
    m_tree.insert(80);
    m_treeWidget->update();
    m_treeWidget->setTree(&m_tree);

    // Подключаем кнопки
    connect(ui->insertButton, &QPushButton::clicked, this, &MainWindow::onInsertClicked);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveClicked);
    connect(ui->balanceButton, &QPushButton::clicked, this, &MainWindow::onBalanceClicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::onClearClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onInsertClicked()
{
    bool ok;
    int value = ui->valueSpinBox->value();

    m_tree.insert(value);
    m_treeWidget->update();
    m_treeWidget->setTree(&m_tree);
}

void MainWindow::onRemoveClicked()
{
    int value = ui->valueSpinBox->value();

    if (!m_tree.search(value)) {
        QMessageBox::warning(this, "Ошибка", "Узел с таким значением не найден!");
        return;
    }

    m_tree.remove(value);
    m_treeWidget->setTree(&m_tree);
}

void MainWindow::onBalanceClicked()
{
    m_tree.balance();
    m_treeWidget->setTree(&m_tree);
}

void MainWindow::onClearClicked()
{
    m_tree.clear();
    m_treeWidget->setTree(&m_tree);
}
