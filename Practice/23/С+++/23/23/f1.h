#include <iostream>
#pragma once

void factorial() {
    using namespace std;
    int n, rezult = 1;
    cin >> n;

    if (n >= 0) {
        for (int i = 1; i <= n; i++)
        {
            rezult *= i;
        }
        cout << rezult;
    }
}
