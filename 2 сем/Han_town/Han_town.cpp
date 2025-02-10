#include <iostream>
using namespace std;
void Han_town(int n, char st, char fin, char tmp)
{
    setlocale(LC_ALL, "rus");
    if (n == 1) {
        
        cout << "Первый диск движется из " << st
            << " в стержень " << fin << endl;
        return;
    }
    Han_town(n - 1, st, tmp, fin);

    cout << "Движение диска " << n << " из стержня " << st
        << " в стержень " << fin << endl;
    Han_town(n - 1, tmp, fin, st);
}

int main()
{
    
    int n = 3;
    Han_town(n, 'A', 'C', 'B');

    return 0;
}
