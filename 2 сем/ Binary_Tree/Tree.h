#ifndef TREE_H
#define TREE_H

#include <QMap>
#include <QPoint>

class BinaryTree
{
public:
    struct Node {
        int key;
        Node* left;
        Node* right;
        int x; // Позиция X для отрисовки
        int y; // Позиция Y для отрисовки

        Node(int k) : key(k), left(nullptr), right(nullptr), x(0), y(0) {}
    };

    BinaryTree() : root(nullptr) {}
    ~BinaryTree() { clear(root); }

    void insert(int key) { root = insert(root, key); }
    void remove(int key) { root = remove(root, key); }
    bool search(int key) { return search(root, key) != nullptr; }
    void clear() { clear(root); root = nullptr; }
    void balance();

    Node* getRoot() const { return root; }
    void calculatePositions(int width);

private:
    Node* root;

    Node* insert(Node* node, int key);
    Node* remove(Node* node, int key);
    Node* search(Node* node, int key) const;
    Node* findMin(Node* node) const;
    Node* findMax(Node* node) const;
    void clear(Node* node);
    int countNodes(Node* node) const;
    void storeInOrder(Node* node, Node** nodes, int* index);
    Node* buildBalanced(Node** nodes, int start, int end);
    void calculateNodePositions(Node* node, int x, int y, int level, int offset);
};

#endif // BINARYTREE_H
