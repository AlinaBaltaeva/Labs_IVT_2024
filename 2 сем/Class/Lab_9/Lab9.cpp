#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
    try
    {
        Vector v1(3);
        cout<< "v1: "<< v1;
        v1 = v1 + 2;   // добавляем 2 элемента
        cout << "v1 after +2: " << v1;  // 0 0 0 0 0
        v1[1] = 5;

        Vector v2 = v1 - 3;  // удаляем 3 элемента
        cout << "v2 (v1-3): " << v2; 

        --v2;          
        cout << "v2 after --: " << v2;  

        cout << "Size of v2: " << (int)v2 << endl;  
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}