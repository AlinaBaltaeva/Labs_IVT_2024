#include <iostream>
#include <queue>
#include <stack>
#include <random>
#include <ctime>
using namespace std;

class BinarySearchTree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;

        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root;

    
    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key);
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* findMax(Node* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    Node* remove(Node* node, int key) {
        if (node == nullptr) return nullptr;

        if (key < node->key) {
            node->left = remove(node->left, key);
        }
        else if (key > node->key) {
            node->right = remove(node->right, key);
        }
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
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

    Node* search(Node* node, int key) {
        if (node == nullptr || node->key == key) {
            return node;
        }

        return (key < node->key) ? search(node->left, key) : search(node->right, key);
    }

    // Функции для подсчета количества узлов
    int countNodes(Node* node) {
        if (node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // Функции для обходов 
    void preOrder(Node* node) {
        if (node == nullptr) return;
        std::cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        std::cout << node->key << " ";
        inOrder(node->right);
    }

    void postOrder(Node* node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->key << " ";
    }

    // Функции для балансировки 
    void store(Node* node, Node** arr, int* index) {
        if (node == nullptr) return;
        store(node->left, arr, index);
        arr[(*index)++] = node;
        store(node->right, arr, index);
    }

    Node* Balanced(Node** arr, int start, int end) {
        if (start > end) return nullptr;

        int mid = (start + end) / 2;
        Node* node = arr[mid];

        node->left = Balanced(arr, start, mid - 1);
        node->right = Balanced(arr, mid + 1, end);

        return node;
    }

   
    void print(Node* node, int space) {
        if (node == nullptr) return;

        space += 5;

        print(node->right, space);

        std::cout << std::endl;
        for (int i = 5; i < space; i++) {
            std::cout << " ";
        }
        std::cout << node->key << "\n";

        print(node->left, space);
    }


public:
    BinarySearchTree() : root(nullptr) {}

    
    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    bool search(int key) {
        return search(root, key) != nullptr;
    }

    // Обходы 
    void preOrderT() {
        cout << "Прямой обход: ";
        preOrder(root);
        cout << endl;
    }

    void inOrderT() {
        cout << "Симметричный обход: ";
        inOrder(root);
        cout << endl;
    }

    void postOrderT() {
        cout << "Обратный обход: ";
        postOrder(root);
        cout << endl;
    }

    // Балансировка 
    void balance() {
        int n = countNodes(root);
        if (n == 0) return;

        Node** nodes = new Node * [n];
        int index = 0;
        store(root, nodes, &index);

        root = Balanced(nodes, 0, n - 1);
        delete[] nodes;
    }

    
    void print() {
        print(root, 0);
    }

    
    int findMax() {
        Node* maxNode = findMax(root);
        return maxNode ? maxNode->key : -1;
    }
};
int main() {
    setlocale(LC_ALL, "ru");
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.print();

    
    bst.preOrderT();
    bst.inOrderT();
    bst.postOrderT();

    cout << "Максимальный элемент: " << bst.findMax() << endl;

    
    bst.balance();
    cout << "\nДерево после балансировки:\n";
    bst.print();

    
    bst.preOrderT();
    bst.inOrderT();
    bst.postOrderT();

    return 0;
}