#include <iostream>
#include <ctime>
#include <stdio.h>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите целое число:";
	int x, y, n = rand() % (100 + 1);
	x = 0;
	while (x < 5)
	{
		cin >> y;
		if (y == n) {
			cout << "Поздравляю! Вы угадали";
		}
		if (y > n) {
			cout << "Загаданное число меньше:";
		}
		if (y < n) {
			cout << "Загаданное число больше:";
		}
		x++;
	}
	if (y != n) {
		cout << "Вы проиграли. Было загадано:" << n << endl;
	}
	

}