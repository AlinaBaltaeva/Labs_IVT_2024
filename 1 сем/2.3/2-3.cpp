﻿#include <iostream>
using namespace std;
int main() {
    int n, pr, sum;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        pr = 1;
        for (int j = i; j <= 2 * i; j++)
        {
            pr *= j;
        }
        sum += pr;

    }
    cout << sum << endl;
    return 0;
}