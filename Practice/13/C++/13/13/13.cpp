#include <iostream>
#include <math.h>
using namespace std;
int main()
{   setlocale(LC_ALL, "Russian");
    int n;
    bool flag = true;
    cin >> n;
    if (n >= 2) {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                flag = false;
                break;
            }
        }

        if (flag == true) {
            cout << "Простое" << endl;
        }
        else {
            cout << "Сложное" << endl;
        }
    }
    
}