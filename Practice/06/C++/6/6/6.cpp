#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double a, b, c, D, x1, x2, x;
	cout << "Введите данные для решения уравнения:" << endl;
	cout << "a = "; cin >> a;  cout << "b = "; cin >> b; cout << "c = "; cin >> c;
	if (a == 0)
	{
		x = (-c / b);
		cout << "x=" << x << endl;

	}
	else
	{
		D = (b * b - 4 * a * c);  cout << "D=" << (D) << endl;// Дискриминант
		if (D > 0) // Дискриминант больше 0(два корня)
		{
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = (-b - sqrt(D)) / (2 * a);
			cout << "x1=" << x1 << endl << "x2=" << x2 << endl;
		}

		if (D == 0) // Дискриминант равен 0(один корень)
		{
			x = (-b) / (2 * a);
			cout << "x=" << x << endl;
		}
		if (D < 0) // Дискриминант меньше 0(коней нет)
			cout << "Корней нет";
	}

}