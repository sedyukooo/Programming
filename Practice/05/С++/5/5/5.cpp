#include <iostream>

int main() {
	using namespace std;

	double a = 9.8;
	double x, v, t, s;
	cin >> x >> v >> t;
    s = x + v * t - (a * t * t)/2;
	
	cout << s; 
	


}