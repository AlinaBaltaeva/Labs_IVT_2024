#include <iostream>
using namespace std;
int main() {
    int N, c;
    cin >> N;
    int i = 1;
    c = 1;
    while (i <= N) {
        c *= i;
        i++;
    }
    cout << c << endl;
    return 0;
}

