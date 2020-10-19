#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b;
	c = a;
	a = b;
	b = c;
	cout << a  << b;

	int x, y;
	cin >> x >> y;
	x = x + y;
	y = x - y;
	x = x - y;
	cout << x << endl<< y;
}