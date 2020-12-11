#include <iostream>
#include <vector>

using namespace std;
void factorial(int i, int a = 1)
{
    vector<int> v;
    if (i == 1) return;
    if (i % a == 0)
    {

        cout << a << endl;
        factorial(i / a, a);

    }
    else
        if (a == 2)
            factorial(i, a + 1);
        else
            factorial(i, a + 2);
}
int main()
{
    int i;
    cin >> i;
    factorial(i, 2);
    cin.get();
    cin.get();

    return 0;
}