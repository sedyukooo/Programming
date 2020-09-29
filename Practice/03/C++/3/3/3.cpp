#include <iostream>
using namespace std;

int main() {
	int a = 3.1, b = 99;
	cout << a + b << b - a << b / a << a * b;

	double c = 3.1;
	double d = 99;
	cout << endl << c + d << d - c << d / c << c * d;

	int e = 3.1;
	double q = 99;
	cout << endl << e + q << q - e << q / e << e * q;

	double z = 3.1;
	int x = 99;
	cout << endl << z + x << x - z << x / z << z * x;
}