#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include "Tree.h"

class TreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = nullptr);
    void setTree(BinaryTree* tree);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    BinaryTree* m_tree;
    void drawNode(QPainter& painter, BinaryTree::Node* node);
    void drawConnection(QPainter& painter, BinaryTree::Node* parent, BinaryTree::Node* child);
    void drawConnections(QPainter& painter, BinaryTree::Node* node);
    void drawNodes(QPainter& painter, BinaryTree::Node* node);
};

#endif // TREEWIDGET_H
