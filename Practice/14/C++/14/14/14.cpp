#include <iostream>
using namespace std;
int main()
{
    int n, rezult = 0, multiplicand = 1;

    cin >> n;


    if (n >= 0) {
        while (multiplicand <= n) {
            multiplicand *= 2;
            rezult += 1;
        }
        cout << rezult << endl;
    }
}