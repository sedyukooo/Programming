#include <iostream>
#include<math.h>
using namespace std;
int main()
{

    double a, b;
    int x, i = 1;

    cin >> a >> x;

    b = a;
    while (i < abs(x)) {
        a = a * b;
        i++;
    }
    if (x > 0) {
        cout << a << endl;
        return 0;
    }
    else if (x < 0) {
        cout << 1 / a << endl;
        return 0;
    }
    else if (x == 0) {
        cout << 1 << endl;
        return 0;
    }
}