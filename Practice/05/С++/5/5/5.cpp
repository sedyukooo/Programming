#include <iostream>

int main() {
	using namespace std;

	double a = 9.8;
	double x, v, t, s;
	cout << " "; cin >> x; cout << " "; cin >> v; cout << " "; cin >> t;

    s = x + v * t - (a * t * t)/2;
	
	cout << s; 
	


}