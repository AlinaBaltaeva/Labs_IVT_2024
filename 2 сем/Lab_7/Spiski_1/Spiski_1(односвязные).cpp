// Записи в линейном списке содержат ключевое поле типа
//int.Сформировать однонаправленный список.Удалить из
//него элемент с заданным ключом, добавить элемент перед
//элементом с заданным ключом;


#include <iostream>
using namespace std;
struct Node
{
    char data;
    Node* next_ptr;

    void adddata(char Data)
    {
        data = Data;
        next_ptr = nullptr;
    }
};
struct List
{
    Node* head = NULL;
    Node* tail = NULL;

    //добавление элемента в конец списка
    void push(char data)
    {
        Node* node = new Node;
        node->adddata(data);
        if (head == nullptr) head = node;
        if (tail != nullptr) tail->next_ptr = node;
        tail = node;
    }

    //добавление в начало списка
    void push1(char data)
    {
        Node* node = new Node;
        node->adddata(data);
        node->next_ptr = head;
        head = node;
        if (tail == nullptr) tail = node;
    }

    Node* getAt(int k)
    {
        if (k < 0) return 0;

        Node* node = head;
        int n = 0;
        while (node && n != k && node->next_ptr)
        {
            node = node->next_ptr;
            n++;
        }
        if (n == k) return node;
        else return nullptr;
    }

    //добавление после элемента с заданным индексом
    void insert(int k, char data)
    {
        Node* left = getAt(k);
        if (left == nullptr) return;
        Node* right = left->next_ptr;
        Node* node = new Node;

        left->next_ptr = node;
        node->next_ptr = right;
        if (right == NULL) tail = node;
    }
    
    //удаление первого элемента
    void del_elem()
    {
        if (head == nullptr) return;
        if (head == tail) 
        {
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node* node = head;
        head = node->next_ptr;
        delete node;
    }

    //удаление последнего элемента
    void last_elem()
    {
        if (tail == nullptr) return;
        if (head == tail)
        {
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node* node = head;
        for (; node->next_ptr != tail; node = node->next_ptr);
        node->next_ptr = nullptr;
        delete tail;
        tail = node;
    }

    //удаление элемента с заданным индексом
    void erase(int k)
    {
        if (k < 0)return;
        if (k == 0)
        {
            del_elem();
            return;
        }
        Node* left = getAt(k - 1);
        Node* node = left->next_ptr;
        if (node == nullptr) return;
        Node* right = node->next_ptr;
        left->next_ptr = right;
        if (node == tail) tail = left;
        delete node;
    }
};
int main()
{
    setlocale(LC_ALL, "rus");
    List list;
    char ch;
    for (int i = 0; i < 5; i++)
    {
        cout << "Введите " << i + 1 << " элемент;";
        cin >> ch;
        list.push(ch);
    }
    cout << endl;
    list.insert(2, 'u'); //добавление элемента с индексом 2
    for (Node* node = list.head; node != list.tail->next_ptr; node = node->next_ptr)
        cout << node->data << ' ';
    cout << endl << endl;
    list.erase(4); //удaление элемента с индексом 4
    for (Node* node = list.head; node != list.tail->next_ptr; node = node->next_ptr)
    {
        cout << node->data << ' ';
    }

}

