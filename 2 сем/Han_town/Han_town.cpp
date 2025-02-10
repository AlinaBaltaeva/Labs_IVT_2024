#include <iostream>
using namespace std;
void towerOfHanoi(int n, char st, char fin, char tmp)
{
    setlocale(LC_ALL, "rus");
    if (n == 1) {
        
        cout << "Первый диск движется из " << st
            << " в стержень " << fin << endl;
        return;
    }
    towerOfHanoi(n - 1, st, tmp, fin);

    cout << "Движение диска " << n << " из стержня " << st
        << " в стержень " << fin << endl;
    towerOfHanoi(n - 1, tmp, fin, st);
}

int main()
{
    
    int n = 3;
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}