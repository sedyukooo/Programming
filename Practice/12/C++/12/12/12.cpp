#include <iostream>
using namespace std;
int main()
{
    int a, rezult = 1;
    cin >> a;

    if (a >= 0) {
        for (int i = 1; i <= a; i++)
        {
            rezult *= i;
        }
        cout << rezult;
    }
}

