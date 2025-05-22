#include "Tree.h"
#include <algorithm>

BinaryTree::Node* BinaryTree::insert(Node* node, int key)
{
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}

BinaryTree::Node* BinaryTree::remove(Node* node, int key)
{
    if (node == nullptr) return nullptr;

    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->key = temp->key;
        node->right = remove(node->right, temp->key);
    }

    return node;
}

BinaryTree::Node* BinaryTree::search(Node* node, int key) const
{
    if (node == nullptr || node->key == key) {
        return node;
    }
    return (key < node->key) ? search(node->left, key) : search(node->right, key);
}

BinaryTree::Node* BinaryTree::findMin(Node* node) const
{
    while (node && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BinaryTree::Node* BinaryTree::findMax(Node* node) const
{
    while (node && node->right != nullptr) {
        node = node->right;
    }
    return node;
}

void BinaryTree::clear(Node* node)
{
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

int BinaryTree::countNodes(Node* node) const
{
    return node ? 1 + countNodes(node->left) + countNodes(node->right) : 0;
}

void BinaryTree::storeInOrder(Node* node, Node** nodes, int* index)
{
    if (node == nullptr) return;
    storeInOrder(node->left, nodes, index);
    nodes[(*index)++] = node;
    storeInOrder(node->right, nodes, index);
}

BinaryTree::Node* BinaryTree::buildBalanced(Node** nodes, int start, int end)
{
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    Node* node = nodes[mid];

    node->left = buildBalanced(nodes, start, mid - 1);
    node->right = buildBalanced(nodes, mid + 1, end);

    return node;
}

void BinaryTree::balance()
{
    int n = countNodes(root);
    if (n == 0) return;

    Node** nodes = new Node*[n];
    int index = 0;
    storeInOrder(root, nodes, &index);

    root = buildBalanced(nodes, 0, n - 1);
    delete[] nodes;
}

void BinaryTree::calculatePositions(int width)
{
    if (!root) return;

    // Рассчитываем глубину дерева
    int depth = 0;
    Node* current = root;
    while (current) {
        depth++;
        current = current->left;
    }

    // Начальные параметры для расчета позиций
    int startX = width / 2;
    int startY = 50;
    int levelHeight = 80;

    calculateNodePositions(root, startX, startY, 1, width / 4);
}

void BinaryTree::calculateNodePositions(Node* node, int x, int y, int level, int offset)
{
    if (!node) return;

    node->x = x;
    node->y = y;

    // Рекурсивно рассчитываем позиции для левого и правого поддеревьев
    calculateNodePositions(node->left, x - offset, y + 80, level + 1, offset / 2);
    calculateNodePositions(node->right, x + offset, y + 80, level + 1, offset / 2);
}
