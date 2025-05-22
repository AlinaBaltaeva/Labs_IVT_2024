#include "treewidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QFont>

TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent), m_tree(nullptr)
{
    setMinimumSize(800, 600);
}

void TreeWidget::setTree(BinaryTree *tree)
{
    m_tree = tree;
    if (m_tree) {
        m_tree->calculatePositions(width());
    }
    update();
}

void TreeWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Белый фон
    painter.fillRect(rect(), Qt::white);
    drawConnections(painter, m_tree->getRoot());


    drawNodes(painter, m_tree->getRoot());
}

void TreeWidget::drawConnections(QPainter& painter, BinaryTree::Node* node)
{
    if (!node) return;

    if (node->left) {
        drawConnection(painter, node, node->left);
        drawConnections(painter, node->left);
    }

    if (node->right) {
        drawConnection(painter, node, node->right);
        drawConnections(painter, node->right);
    }
}

void TreeWidget::drawConnection(QPainter& painter, BinaryTree::Node* parent, BinaryTree::Node* child)
{
    painter.setPen(QPen(Qt::black, 2));
    painter.drawLine(parent->x + 15, parent->y + 15, child->x + 15, child->y + 15);
}

void TreeWidget::drawNodes(QPainter& painter, BinaryTree::Node* node)
{
    if (!node) return;

    // Рисуем узел
    painter.setPen(QPen(Qt::black, 2));
    painter.setBrush(QBrush(Qt::lightGray));
    painter.drawEllipse(node->x, node->y, 30, 30);

    // Рисуем текст (ключ узла)
    painter.setPen(Qt::black);
    QFont font = painter.font();
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(QRect(node->x, node->y, 30, 30), Qt::AlignCenter, QString::number(node->key));

    // Рекурсивно рисуем левое и правое поддеревья
    drawNodes(painter, node->left);
    drawNodes(painter, node->right);
}
