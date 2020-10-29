#include <iostream>
using namespace std;

int main()
{   setlocale(LC_ALL, "Russian");
    

    int s, l1, l2, r1, r2;
    cout << "Введите пять целых числа через пробел  s, l1, l2, r1, r2:" << endl;
    cin >> s >> l1 >> l2 >> r1 >> r2;
    if (l1 + r2 >= s) {
        r2 = max(s - l1, l2);
    }
    else {
        l1 = min(s - r2, r1);
    }
    if (l1 + r2 == s) {
        std::cout << l1 << " " << r2 << std::endl;
    }
    else {
        std::cout << -1 << std::endl;
    }


}