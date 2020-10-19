#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "Rus");
    double x, y, rezult;
    char z;
    cin >> x >> z >> y;
    if (z == '+') {
        rezult = x + y;
    }
    else if (z == '-') {
        rezult = x - y;
    }
    else if (z == '*') {
        rezult = x * y;
    }
    else if (z == '/') {
        if (y != 0) {
            rezult = x / y;
        }
        else { 
            cout << "Деление на 0.";}
      
    }
    cout << rezult;
}
