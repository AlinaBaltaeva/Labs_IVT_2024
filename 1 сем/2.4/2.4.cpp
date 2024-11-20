#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n < 3 && (n % 2 == 0))
    {
        cout << "select a different value" << endl;
    }
    else
    {
        int p = n / 2;
        int t = 1;
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            for (int j = 0; j < p; j++)
            {
                cout << " ";
            }
            p--;
            for (int j = 0; j < t; j++)
            {
                cout << "*";
            }
            t += 2;
            cout << endl;
        }
    }
    return 0;
}