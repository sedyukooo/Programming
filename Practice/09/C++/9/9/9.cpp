#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
   
    double h1, h2, m1, m2, time1, time2;
    cin >> h1 >> ":" >> m1;
    cin >> h2 >> ":" >> m2;
    time1 = h1 + (m1 / 60);
    time2 = h2 + (m2 / 60);
    if ((0 <= time2 - time1) && (time2 - time1 <= 0.25)){
        cout << "Встреча состоялась";
    }
    else {
        cout << "Встреча не состоялась";
    }
}