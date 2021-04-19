#include <iostream>
#include <cmath>

bool equal(double a, double b, double e = 1E-10);

class Rational
{
	int numerator;
	int denominator;
	int sign;

public:
	Rational(int a, int b)
	{
		numerator = abs(a);
		denominator = abs(b);
		if (a >= 0 and b >= 0)
			sign = 1;
		else if (a == 0 and b != 0)
			sign = 1;
		else if (a < 0 and b < 0)
			sign = 1;
		else
			sign = -1;
	}

	Rational()
	{
		numerator = abs(0);
		denominator = abs(0);
		sign = 1;
	}
	int get_num() const { return numerator; }
	int get_denom() const { return denominator; }
	static int gcd(int a, int b)
	{
		int num1 = a;
		int num2 = b;
		int gcdout;
		for (int i = 1; i <= num1 && i <= num2; i++)
		{
			if (num1 % i == 0 && num2 % i == 0)
			{
				gcdout = i;
			}
		}
		return gcdout;
	}
	bool operator==(const Rational &other) const
	{
		if (isNaN() || other.isNaN())
			return false;
		else if (get_num() == 0 && other.get_num() == 0)
			return true;
		else if (sign != other.sign)
			return false;
		else if (get_denom() == 0 && other.get_denom() == 0)
			return true;
		return get_num() * other.get_denom() == get_denom() * other.get_num();
	}
	Rational operator+(const Rational &other) const
	{
		Rational temp;
		if (isNaN() || other.isNaN())
			return Rational(0, 0);
		else if (get_denom() == 0 && other.get_denom() == 0)
		{
			if (sign == other.sign)
				return Rational(sign, 0);
			return Rational(0, 0);
		}
		else if (get_denom() == 0)
			return *this;
		else if (other.get_denom() == 0)
			return other;
		else if (sign != other.sign)
		{
			temp.numerator = abs(get_num() * other.get_denom() - other.get_num() * get_denom());
			if (temp.numerator == 0)
				return Rational(0, 1);
			if (sign == 1)
			{
				if (get_num() * other.get_denom() > other.get_num() * get_denom())
					temp.sign = 1;
				else
					temp.sign = -1;
			}
			else
			{
				if (get_num() * other.get_denom() > other.get_num() * get_denom())
					temp.sign = -1;
				else
					temp.sign = 1;
			}
		}
		else
		{
			temp.numerator = get_num() * other.get_denom() + other.get_num() * get_denom();
			if (sign == 1 and other.sign == 1)
				temp.sign = 1;
			else if (sign == -1 and other.sign == -1)
				temp.sign = -1;
		}
		temp.denominator = get_denom() * other.get_denom();
		return temp;
	}
	Rational operator-(const Rational &other) const
	{
		Rational lol;
		lol = other;
		lol.sign = -other.sign;
		return *this + lol;
	}
	Rational operator*(const Rational &other) const
	{
		Rational lol;
		lol.sign = sign * other.sign;
		lol.numerator = get_num() * other.get_num();
		lol.denominator = get_denom() * other.get_denom();
		return lol;
	}
	Rational operator/(const Rational &other) const
	{
		Rational lol;
		lol.sign = sign * other.sign;
		return Rational(lol.sign * numerator * other.denominator, other.numerator * denominator);
	}
	operator double() const
	{
		return sign * numerator / (double)denominator;
	}
	operator bool() const
	{
		return numerator != 0 or denominator == 0;
	}
	bool isNaN() const
	{
		return numerator == 0 and denominator == 0;
	}
};

int main()
{
	if (Rational::gcd(91, 65) == 13 &&
		Rational::gcd(10, 3) == 1 &&
		Rational::gcd(-10, 3) == 1 &&
		Rational::gcd(10, -3) == 1 &&
		Rational::gcd(-10, -3) == 1 &&
		Rational::gcd(30, 10) == 10 &&
		Rational::gcd(10, 30) == 10 &&
		Rational::gcd(0, 10) == 10 &&
		Rational::gcd(10, 0) == 10)
		std::cout << "gcd test passed\n";
	else
		std::cout << "gcd test failed\n";

	if (!Rational(22, 0).isNaN() &&
		!Rational(22, 9).isNaN() &&
		!Rational(0, 9).isNaN() &&
		!Rational(-22, 9).isNaN() &&
		!Rational(-22, 0).isNaN() &&
		Rational(0, 0).isNaN())
		std::cout << "isNaN test passed\n";
	else
		std::cout << "isNaN test failed\n";

	if (Rational(22, 0) == Rational(22, 0) &&
		Rational(22, 0) == Rational(9, 0) &&
		!(Rational(22, 0) == Rational(22, 9)) &&
		!(Rational(22, 0) == Rational(-22, 9)) &&
		!(Rational(22, 0) == Rational(-22, 0)) &&
		!(Rational(22, 0) == Rational(0, 9)) &&
		!(Rational(22, 0) == Rational(0, 0)) &&

		Rational(22, 9) == Rational(22, 9) &&
		Rational(22, 9) == Rational(-22, -9) &&
		Rational(22, 9) == Rational(110, 45) &&
		Rational(22, 9) == Rational(-110, -45) &&
		!(Rational(22, 9) == Rational(-22, 9)) &&
		!(Rational(22, 9) == Rational(22, -9)) &&
		!(Rational(22, 9) == Rational(9, 22)) &&
		!(Rational(22, 9) == Rational(22, 0)) &&
		!(Rational(22, 9) == Rational(-22, 0)) &&
		!(Rational(22, 9) == Rational(0, 9)) &&
		!(Rational(22, 9) == Rational(0, 0)) &&

		Rational(0, 1) == Rational(0, 1) &&
		Rational(0, 1) == Rational(0, 9) &&
		Rational(0, 1) == Rational(0, -9) &&
		!(Rational(0, 1) == Rational(22, 9)) &&
		!(Rational(0, 1) == Rational(-22, 9)) &&
		!(Rational(0, 1) == Rational(22, 0)) &&
		!(Rational(0, 1) == Rational(-22, 0)) &&
		!(Rational(0, 1) == Rational(0, 0)) &&

		Rational(-22, 9) == Rational(-22, 9) &&
		Rational(-22, 9) == Rational(22, -9) &&
		Rational(-22, 9) == Rational(-110, 45) &&
		Rational(-22, 9) == Rational(110, -45) &&
		!(Rational(-22, 9) == Rational(-22, -9)) &&
		!(Rational(-22, 9) == Rational(22, 9)) &&
		!(Rational(-22, 9) == Rational(9, -22)) &&
		!(Rational(-22, 9) == Rational(22, 0)) &&
		!(Rational(-22, 9) == Rational(-22, 0)) &&
		!(Rational(-22, 9) == Rational(0, 9)) &&
		!(Rational(-22, 9) == Rational(0, 0)) &&

		Rational(-22, 0) == Rational(-22, 0) &&
		Rational(-22, 0) == Rational(-9, 0) &&
		!(Rational(-22, 0) == Rational(22, 9)) &&
		!(Rational(-22, 0) == Rational(-22, 9)) &&
		!(Rational(-22, 0) == Rational(22, 0)) &&
		!(Rational(-22, 0) == Rational(0, 9)) &&
		!(Rational(-22, 0) == Rational(0, 0)) &&

		!(Rational(0, 0) == Rational(0, 0)))
		std::cout << "Equality test passed\n";
	else
		std::cout << "Equality test failed\n";

	if (Rational(22, 0) + Rational(22, 0) == Rational(22, 0) &&
		Rational(22, 9) + Rational(22, 0) == Rational(22, 0) &&
		Rational(0, 9) + Rational(22, 0) == Rational(22, 0) &&
		Rational(-22, 9) + Rational(22, 0) == Rational(22, 0) &&
		(Rational(-22, 0) + Rational(22, 0)).isNaN() &&

		Rational(22, 0) + Rational(22, 9) == Rational(22, 0) &&
		Rational(22, 9) + Rational(22, 9) == Rational(44, 9) &&
		Rational(0, 9) + Rational(22, 9) == Rational(22, 9) &&
		Rational(-22, 9) + Rational(22, 9) == Rational(0, 9) &&
		Rational(-22, 0) + Rational(22, 9) == Rational(-22, 0) &&

		Rational(22, 0) + Rational(0, 1) == Rational(22, 0) &&
		Rational(22, 9) + Rational(0, 1) == Rational(22, 9) &&
		Rational(0, 9) + Rational(0, 1) == Rational(0, 9) &&
		Rational(-22, 9) + Rational(0, 1) == Rational(-22, 9) &&
		Rational(-22, 0) + Rational(0, 1) == Rational(-22, 0) &&

		Rational(22, 0) + Rational(-22, 9) == Rational(22, 0) &&
		Rational(22, 9) + Rational(-22, 9) == Rational(0, 9) &&
		Rational(0, 9) + Rational(-22, 9) == Rational(-22, 9) &&
		Rational(-22, 9) + Rational(-22, 9) == Rational(-44, 9) &&
		Rational(-22, 0) + Rational(-22, 9) == Rational(-22, 0) &&

		(Rational(22, 0) + Rational(-22, 0)).isNaN() &&
		Rational(22, 9) + Rational(-22, 0) == Rational(-22, 0) &&
		Rational(0, 9) + Rational(-22, 0) == Rational(-22, 0) &&
		Rational(-22, 9) + Rational(-22, 0) == Rational(-22, 0) &&
		Rational(-22, 0) + Rational(-22, 0) == Rational(-22, 0) &&

		(Rational(22, 0) + Rational(0, 0)).isNaN() &&
		(Rational(22, 9) + Rational(0, 0)).isNaN() &&
		(Rational(0, 9) + Rational(0, 0)).isNaN() &&
		(Rational(-22, 9) + Rational(0, 0)).isNaN() &&
		(Rational(-22, 0) + Rational(0, 0)).isNaN())
		std::cout << "Summation test passed\n";
	else
		std::cout << "Summation test failed\n";

	if ((Rational(22, 0) - Rational(22, 0)).isNaN() &&
		Rational(22, 9) - Rational(22, 0) == Rational(-22, 0) &&
		Rational(0, 9) - Rational(22, 0) == Rational(-22, 0) &&
		Rational(-22, 9) - Rational(22, 0) == Rational(-22, 0) &&
		Rational(-22, 0) - Rational(22, 0) == Rational(-22, 0) &&

		Rational(22, 0) - Rational(22, 9) == Rational(22, 0) &&
		Rational(22, 9) - Rational(22, 9) == Rational(0, 9) &&
		Rational(0, 9) - Rational(22, 9) == Rational(-22, 9) &&
		Rational(-22, 9) - Rational(22, 9) == Rational(-44, 9) &&
		Rational(-22, 0) - Rational(22, 9) == Rational(-22, 0) &&

		Rational(22, 0) - Rational(0, 1) == Rational(22, 0) &&
		Rational(22, 9) - Rational(0, 1) == Rational(22, 9) &&
		Rational(0, 9) - Rational(0, 1) == Rational(0, 9) &&
		Rational(-22, 9) - Rational(0, 1) == Rational(-22, 9) &&
		Rational(-22, 0) - Rational(0, 1) == Rational(-22, 0) &&

		Rational(22, 0) - Rational(-22, 9) == Rational(22, 0) &&
		Rational(22, 9) - Rational(-22, 9) == Rational(44, 9) &&
		Rational(0, 9) - Rational(-22, 9) == Rational(22, 9) &&
		Rational(-22, 9) - Rational(-22, 9) == Rational(0, 9) &&
		Rational(-22, 0) - Rational(-22, 9) == Rational(-22, 0) &&

		Rational(22, 0) - Rational(-22, 0) == Rational(22, 0) &&
		Rational(22, 9) - Rational(-22, 0) == Rational(22, 0) &&
		Rational(0, 9) - Rational(-22, 0) == Rational(22, 0) &&
		Rational(-22, 9) - Rational(-22, 0) == Rational(22, 0) &&
		(Rational(-22, 0) - Rational(-22, 0)).isNaN() &&

		(Rational(22, 0) - Rational(0, 0)).isNaN() &&
		(Rational(22, 9) - Rational(0, 0)).isNaN() &&
		(Rational(0, 9) - Rational(0, 0)).isNaN() &&
		(Rational(-22, 9) - Rational(0, 0)).isNaN() &&
		(Rational(-22, 0) - Rational(0, 0)).isNaN())
		std::cout << "Subtraction test passed\n";
	else
		std::cout << "Subtraction test failed\n";

	if (Rational(22, 0) * Rational(22, 0) == Rational(22, 0) &&
		Rational(22, 9) * Rational(22, 0) == Rational(22, 0) &&
		(Rational(0, 9) * Rational(22, 0)).isNaN() &&
		Rational(-22, 9) * Rational(22, 0) == Rational(-22, 0) &&
		Rational(-22, 0) * Rational(22, 0) == Rational(-22, 0) &&

		Rational(22, 0) * Rational(22, 9) == Rational(22, 0) &&
		Rational(22, 9) * Rational(22, 9) == Rational(22 * 22, 9 * 9) &&
		Rational(0, 9) * Rational(22, 9) == Rational(0, 9) &&
		Rational(-22, 9) * Rational(22, 9) == Rational(-22 * 22, 9 * 9) &&
		Rational(-22, 0) * Rational(22, 9) == Rational(-22, 0) &&

		(Rational(22, 0) * Rational(0, 1)).isNaN() &&
		Rational(22, 9) * Rational(0, 1) == Rational(0, 9) &&
		Rational(0, 9) * Rational(0, 1) == Rational(0, 9) &&
		Rational(-22, 9) * Rational(0, 1) == Rational(0, 9) &&
		(Rational(-22, 0) * Rational(0, 1)).isNaN() &&

		Rational(22, 0) * Rational(-22, 9) == Rational(-22, 0) &&
		Rational(22, 9) * Rational(-22, 9) == Rational(-22 * 22, 9 * 9) &&
		Rational(0, 9) * Rational(-22, 9) == Rational(0, 9) &&
		Rational(-22, 9) * Rational(-22, 9) == Rational(22 * 22, 9 * 9) &&
		Rational(-22, 0) * Rational(-22, 9) == Rational(22, 0) &&

		Rational(22, 0) * Rational(-22, 0) == Rational(-22, 0) &&
		Rational(22, 9) * Rational(-22, 0) == Rational(-22, 0) &&
		(Rational(0, 9) * Rational(-22, 0)).isNaN() &&
		Rational(-22, 9) * Rational(-22, 0) == Rational(22, 0) &&
		Rational(-22, 0) * Rational(-22, 0) == Rational(22, 0) &&

		(Rational(22, 0) * Rational(0, 0)).isNaN() &&
		(Rational(22, 9) * Rational(0, 0)).isNaN() &&
		(Rational(0, 9) * Rational(0, 0)).isNaN() &&
		(Rational(-22, 9) * Rational(0, 0)).isNaN() &&
		(Rational(-22, 0) * Rational(0, 0)).isNaN())
		std::cout << "Multiplication test passed\n";
	else
		std::cout << "Multiplication test failed\n";

	if ((Rational(22, 0) / Rational(22, 0)).isNaN() &&
		Rational(22, 9) / Rational(22, 0) == Rational(0, 9) &&
		Rational(0, 9) / Rational(22, 0) == Rational(0, 9) &&
		Rational(-22, 9) / Rational(22, 0) == Rational(0, 9) &&
		(Rational(-22, 0) / Rational(22, 0)).isNaN() &&

		Rational(22, 0) / Rational(22, 9) == Rational(22, 0) &&
		Rational(22, 9) / Rational(22, 9) == Rational(9, 9) &&
		Rational(0, 9) / Rational(22, 9) == Rational(0, 9) &&
		Rational(-22, 9) / Rational(22, 9) == Rational(-9, 9) &&
		Rational(-22, 0) / Rational(22, 9) == Rational(-22, 0) &&

		Rational(22, 0) / Rational(0, 1) == Rational(22, 0) &&
		Rational(22, 9) / Rational(0, 1) == Rational(22, 0) &&
		(Rational(0, 9) / Rational(0, 1)).isNaN() &&
		Rational(-22, 9) / Rational(0, 1) == Rational(-22, 0) &&
		Rational(-22, 0) / Rational(0, 1) == Rational(-22, 0) &&

		Rational(22, 0) / Rational(-22, 9) == Rational(-22, 0) &&
		Rational(22, 9) / Rational(-22, 9) == Rational(-9, 9) &&
		Rational(0, 9) / Rational(-22, 9) == Rational(0, 9) &&
		Rational(-22, 9) / Rational(-22, 9) == Rational(9, 9) &&
		Rational(-22, 0) / Rational(-22, 9) == Rational(22, 0) &&

		(Rational(22, 0) / Rational(-22, 0)).isNaN() &&
		Rational(22, 9) / Rational(-22, 0) == Rational(0, 9) &&
		Rational(0, 9) / Rational(-22, 0) == Rational(0, 9) &&
		Rational(-22, 9) / Rational(-22, 0) == Rational(0, 9) &&
		(Rational(-22, 0) / Rational(-22, 0)).isNaN() &&

		(Rational(22, 0) / Rational(0, 0)).isNaN() &&
		(Rational(22, 9) / Rational(0, 0)).isNaN() &&
		(Rational(0, 9) / Rational(0, 0)).isNaN() &&
		(Rational(-22, 9) / Rational(0, 0)).isNaN() &&
		(Rational(-22, 0) / Rational(0, 0)).isNaN())
		std::cout << "Division test passed\n";
	else
		std::cout << "Division test failed\n";

	if (equal(Rational(-22, -9), 22 / 9.0) &&
		equal(Rational(-9, -9), 1) &&
		equal(Rational(-6, -9), 6 / 9.0) &&
		equal(Rational(0, -9), 0) &&
		equal(Rational(6, -9), -6 / 9.0) &&
		equal(Rational(9, -9), -1) &&
		equal(Rational(22, -9), -22 / 9.0) &&
		std::isinf((double)Rational(-9, 0)) &&
		std::isnan((double)Rational(0, 0)) &&
		std::isinf((double)Rational(9, 0)) &&
		equal(Rational(-22, 9), -22 / 9.0) &&
		equal(Rational(-9, 9), -1) &&
		equal(Rational(-6, 9), -6 / 9.0) &&
		equal(Rational(0, 9), 0) &&
		equal(Rational(6, 9), 6 / 9.0) &&
		equal(Rational(9, 9), 1) &&
		equal(Rational(22, 9), 22 / 9.0))
		std::cout << "Conversion to double test passed\n";
	else
		std::cout << "Conversion to double test failed\n";

	if (Rational(-22, -9) &&
		Rational(-9, -9) &&
		Rational(-6, -9) &&
		!Rational(0, -9) &&
		Rational(6, -9) &&
		Rational(9, -9) &&
		Rational(22, -9) &&
		Rational(-9, 0) &&
		Rational(0, 0) &&
		Rational(9, 0) &&
		Rational(-22, 9) &&
		Rational(-9, 9) &&
		Rational(-6, 9) &&
		!Rational(0, 9) &&
		Rational(6, 9) &&
		Rational(9, 9) &&
		Rational(22, 9))
		std::cout << "Conversion to bool test passed\n";
	else
		std::cout << "Conversion to bool test failed\n";
}

bool equal(double a, double b, double e)
{
	if (-e < a - b && a - b < e)
		return true;
	else
		return false;
}