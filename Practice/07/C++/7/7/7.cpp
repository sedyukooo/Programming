#include <iostream>
#include <cmath>
#include <iso646.h>
int main() {
	using namespace std;
	setlocale(LC_ALL, "Russian");
	double P, S, a, b, c, AB, BC, AC, x1, x2, x3, y1, y2, y3, z;
	cout << "Расчёт площади треугольника двумя способами:"
		<< endl << "1 - Через длины сторон a, b, c"
		<< endl << "2 - Через координаты точек A, B, C"
		<< endl << "Ввыберите способ расчёта и введите цифру, соответсвующую ему: ";
	cin >> z;
	if (z == 1) {
		cout << "Введите данные:" << endl;
		cout << "a="; cin >> a;
		cout << "b="; cin >> b;
		cout << "c="; cin >> c;
		if ((a + b > c) && (a + c > b) && (b + c > a)) {
			P = a + b + c;
			S = sqrt((P * (P - a) * (P - b) * (P - c)));
			cout << "S=" << S;
		}
		else cout << "Треугольника с данынми длинами сторон не существует.";
		
	}
	if (z == 2) {
		cout << "Введите данные:" << endl;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		cin >> x3 >> y3;
		AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
		AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
		if ((AB + BC > AC) && (AB + AC > BC) && (BC + AC > AB)) {
			P = AB + BC + AC;
			S = sqrt((P * (P - AB) * (P - BC) * (P - AC)));
			cout << "S=" << S;
		}
		else cout << "Треугольника с данынми длинами сторон не существует.";

		

	}
}