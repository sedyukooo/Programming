#include <iostream>
#include "f1.h"
#include "f2.h"
#include "f3.h"
using namespace std;
int main() {
	
	for (int i = 1; i <= 10; i++) {
		cout << i << factorial(i) << "\n";
	}
	int y = 5;
	for (double x = 0; x <= 3.14 / 4; x = (x + 3.14 / 180)) {
		cout << x << sin(x, y) << "\n";
	}
	for (int y = 1; y <= 10; y++) {
		cout <<  f(y, 10) << "\n";
	}
}