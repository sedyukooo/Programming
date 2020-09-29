#include <iostream>
using namespace std;
int main() {
	int a = 3;
	int b = 5;

	int c;

	c = a;
	a = b;
	b = c;
	cout << a << endl << b;

}