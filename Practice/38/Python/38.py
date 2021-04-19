import math


class Rational:
    def __init__(self, numerator, denominator):
        if numerator is None and denominator is None:
            self.Result = 0
            return
        if numerator is not None and denominator is None:
            self.a = numerator
            self.b = 1
            self.Result = numerator
            return
        if numerator is not None and denominator is not None:
            self.a = numerator
            self.b = denominator
            if numerator == 0 and denominator == 0:
                self.Result = float('nan')
                return
            if numerator > 0 and denominator == 0:
                self.Result = float('inf')
                return
            if numerator < 0 and denominator == 0:
                self.Result = float('-inf')
                return
            if denominator != 0:
                self.Result = numerator / denominator
                return

    @staticmethod
    def gcd(first_num, second_num):
        count = 1
        for num in range(max(first_num, second_num), 0, -1):
            if first_num % num == 0 and second_num % num == 0:
                count = num
                break
        return count

    def isNaN(self):
        if math.isnan(self.Result):
            return True
        else:
            return False

    def isInf(self):
        if math.isinf(self.Result):
            return True
        else:
            return False

    def isInfPos(self):
        if math.isinf(self.Result) and self.a > 0:
            return True
        else:
            return False

    def isInfNeg(self):
        if math.isinf(self.Result) and self.a < 0:
            return True
        else:
            return False

    def numerator(self):
        return self.a

    def denominator(self):
        return self.b

    def __add__(self, second):
        if not self.isNaN() and not second.isNaN() and not self.isInf() and not \
                second.isInf() and self.b != second.b:
            result = Rational((self.a * second.b) + (second.a * self.b), (self.b * second.b))
            return result
        if not self.isNaN() and not second.isNaN() and not self.isInf() and not \
                second.isInf() and self.b == second.b:
            result = Rational((self.a + second.a), second.b)
            return result
        if self.isNaN() or second.isNaN():
            result = Rational(0, 0)
            return result
        if self.isInfNeg() and second.isInfPos():
            result = Rational(0, 0)
            return result
        if self.isInfPos() and second.isInfNeg():
            result = Rational(0, 0)
            return result
        if self.isInfNeg() and second.isInfNeg():
            return self
        if self.isInfPos() and second.isInfPos():
            return self
        if self.isNaN() or self.isInf() and not second.isNaN() and not second.isInf():
            return self
        if not self.isNaN() and not self.isInf() and second.isNaN() or second.isInf():
            return second

    def __eq__(self, second):
        if self.isNaN() or second.isNaN():
            return False
        if self.Result == second.Result:
            return True
        return False

    def __sub__(self, second):
        if not self.isNaN() and not second.isNaN() and not self.isInf() and not \
                second.isInf() and self.b != second.b:
            result = Rational((self.a * second.b) - (second.a * self.b), (self.b * second.b))
            return result

        if not self.isNaN() and not second.isNaN() and not self.isInf() and not \
                second.isInf() and self.b == second.b:
            result = Rational((self.a - second.a), second.b)
            return result

        if self.isInfNeg() and second.isInfNeg():
            result = Rational(0, 0)
            return result

        if self.isInfPos() and second.isInfPos():
            result = Rational(0, 0)
            return result

        elif self.isNaN() or second.isNaN():
            result = Rational(0, 0)
            return result

        elif self.isInfNeg() and second.isInfPos():
            return self
        elif self.isInfPos() and second.isInfNeg():
            return self
        elif self.isNaN() or self.isInf() and not second.isNaN() and not second.isInf():
            return self
        elif not self.isNaN() and not self.isInf() and second.isNaN() or second.isInf():
            result = Rational(-second.a, 0)
            return result

    def __mul__(self, second):
        result = Rational((self.a * second.a), (self.b * second.b))
        return result

    def __truediv__(self, second):
        if self.isNaN() or self.isInf() and not second.isNaN() and not second.isInf():
            if second.a < 0:
                result = Rational(-self.a, self.b)
                return result
            else:
                return self
        else:
            result = Rational(self.a * second.b, self.b * second.a)
            return result

    def __float__(self):
        return float(self.Result)

    def __bool__(self):
        if self.Result == 0:
            return False
        else:
            return True


def equal(a, b, e=1E-10):
    if -e < a - b < e:
        return True
    else:
        return False


if (Rational.gcd(91, 65) == 13 and
        Rational.gcd(10, 3) == 1 and
        Rational.gcd(-10, 3) == 1 and
        Rational.gcd(10, -3) == 1 and
        Rational.gcd(-10, -3) == 1 and
        Rational.gcd(30, 10) == 10 and
        Rational.gcd(10, 30) == 10 and
        Rational.gcd(0, 10) == 10 and
        Rational.gcd(10, 0) == 10
):
    print('gcd test passed')
else:
    print('gcd test failed')

if (not Rational(22, 0).isNaN() and
        not Rational(22, 9).isNaN() and
        not Rational(0, 9).isNaN() and
        not Rational(-22, 9).isNaN() and
        not Rational(-22, 0).isNaN() and
        Rational(0, 0).isNaN()
):
    print('isNaN test passed')
else:
    print('isNaN test failed')

if (Rational(22, 0) == Rational(22, 0) and
        Rational(22, 0) == Rational(9, 0) and
        not (Rational(22, 0) == Rational(22, 9)) and
        not (Rational(22, 0) == Rational(-22, 9)) and
        not (Rational(22, 0) == Rational(-22, 0)) and
        not (Rational(22, 0) == Rational(0, 9)) and
        not (Rational(22, 0) == Rational(0, 0)) and

        Rational(22, 9) == Rational(22, 9) and
        Rational(22, 9) == Rational(-22, -9) and
        Rational(22, 9) == Rational(110, 45) and
        Rational(22, 9) == Rational(-110, -45) and
        not (Rational(22, 9) == Rational(-22, 9)) and
        not (Rational(22, 9) == Rational(22, -9)) and
        not (Rational(22, 9) == Rational(9, 22)) and
        not (Rational(22, 9) == Rational(22, 0)) and
        not (Rational(22, 9) == Rational(-22, 0)) and
        not (Rational(22, 9) == Rational(0, 9)) and
        not (Rational(22, 9) == Rational(0, 0)) and

        Rational(0, 1) == Rational(0, 1) and
        Rational(0, 1) == Rational(0, 9) and
        Rational(0, 1) == Rational(0, -9) and
        not (Rational(0, 1) == Rational(22, 9)) and
        not (Rational(0, 1) == Rational(-22, 9)) and
        not (Rational(0, 1) == Rational(22, 0)) and
        not (Rational(0, 1) == Rational(-22, 0)) and
        not (Rational(0, 1) == Rational(0, 0)) and

        Rational(-22, 9) == Rational(-22, 9) and
        Rational(-22, 9) == Rational(22, -9) and
        Rational(-22, 9) == Rational(-110, 45) and
        Rational(-22, 9) == Rational(110, -45) and
        not (Rational(-22, 9) == Rational(-22, -9)) and
        not (Rational(-22, 9) == Rational(22, 9)) and
        not (Rational(-22, 9) == Rational(9, -22)) and
        not (Rational(-22, 9) == Rational(22, 0)) and
        not (Rational(-22, 9) == Rational(-22, 0)) and
        not (Rational(-22, 9) == Rational(0, 9)) and
        not (Rational(-22, 9) == Rational(0, 0)) and

        Rational(-22, 0) == Rational(-22, 0) and
        Rational(-22, 0) == Rational(-9, 0) and
        not (Rational(-22, 0) == Rational(22, 9)) and
        not (Rational(-22, 0) == Rational(-22, 9)) and
        not (Rational(-22, 0) == Rational(22, 0)) and
        not (Rational(-22, 0) == Rational(0, 9)) and
        not (Rational(-22, 0) == Rational(0, 0)) and

        not (Rational(0, 0) == Rational(0, 0))
):
    print('Equality test passed')
else:
    print('Equality test failed')

if (Rational(22, 0) + Rational(22, 0) == Rational(22, 0) and
        Rational(22, 9) + Rational(22, 0) == Rational(22, 0) and
        Rational(0, 9) + Rational(22, 0) == Rational(22, 0) and
        Rational(-22, 9) + Rational(22, 0) == Rational(22, 0) and
        (Rational(-22, 0) + Rational(22, 0)).isNaN() and

        Rational(22, 0) + Rational(22, 9) == Rational(22, 0) and
        Rational(22, 9) + Rational(22, 9) == Rational(44, 9) and
        Rational(0, 9) + Rational(22, 9) == Rational(22, 9) and
        Rational(-22, 9) + Rational(22, 9) == Rational(0, 9) and
        Rational(-22, 0) + Rational(22, 9) == Rational(-22, 0) and

        Rational(22, 0) + Rational(0, 1) == Rational(22, 0) and
        Rational(22, 9) + Rational(0, 1) == Rational(22, 9) and
        Rational(0, 9) + Rational(0, 1) == Rational(0, 9) and
        Rational(-22, 9) + Rational(0, 1) == Rational(-22, 9) and
        Rational(-22, 0) + Rational(0, 1) == Rational(-22, 0) and

        Rational(22, 0) + Rational(-22, 9) == Rational(22, 0) and
        Rational(22, 9) + Rational(-22, 9) == Rational(0, 9) and
        Rational(0, 9) + Rational(-22, 9) == Rational(-22, 9) and
        Rational(-22, 9) + Rational(-22, 9) == Rational(-44, 9) and
        Rational(-22, 0) + Rational(-22, 9) == Rational(-22, 0) and

        (Rational(22, 0) + Rational(-22, 0)).isNaN() and
        Rational(22, 9) + Rational(-22, 0) == Rational(-22, 0) and
        Rational(0, 9) + Rational(-22, 0) == Rational(-22, 0) and
        Rational(-22, 9) + Rational(-22, 0) == Rational(-22, 0) and
        Rational(-22, 0) + Rational(-22, 0) == Rational(-22, 0) and

        (Rational(22, 0) + Rational(0, 0)).isNaN() and
        (Rational(22, 9) + Rational(0, 0)).isNaN() and
        (Rational(0, 9) + Rational(0, 0)).isNaN() and
        (Rational(-22, 9) + Rational(0, 0)).isNaN() and
        (Rational(-22, 0) + Rational(0, 0)).isNaN()
):
    print('Summation test passed')
else:
    print('Summation test failed')

if ((Rational(22, 0) - Rational(22, 0)).isNaN() and
        Rational(22, 9) - Rational(22, 0) == Rational(-22, 0) and
        Rational(0, 9) - Rational(22, 0) == Rational(-22, 0) and
        Rational(-22, 9) - Rational(22, 0) == Rational(-22, 0) and
        Rational(-22, 0) - Rational(22, 0) == Rational(-22, 0) and

        Rational(22, 0) - Rational(22, 9) == Rational(22, 0) and
        Rational(22, 9) - Rational(22, 9) == Rational(0, 9) and
        Rational(0, 9) - Rational(22, 9) == Rational(-22, 9) and
        Rational(-22, 9) - Rational(22, 9) == Rational(-44, 9) and
        Rational(-22, 0) - Rational(22, 9) == Rational(-22, 0) and

        Rational(22, 0) - Rational(0, 1) == Rational(22, 0) and
        Rational(22, 9) - Rational(0, 1) == Rational(22, 9) and
        Rational(0, 9) - Rational(0, 1) == Rational(0, 9) and
        Rational(-22, 9) - Rational(0, 1) == Rational(-22, 9) and
        Rational(-22, 0) - Rational(0, 1) == Rational(-22, 0) and

        Rational(22, 0) - Rational(-22, 9) == Rational(22, 0) and
        Rational(22, 9) - Rational(-22, 9) == Rational(44, 9) and
        Rational(0, 9) - Rational(-22, 9) == Rational(22, 9) and
        Rational(-22, 9) - Rational(-22, 9) == Rational(0, 9) and
        Rational(-22, 0) - Rational(-22, 9) == Rational(-22, 0) and

        Rational(22, 0) - Rational(-22, 0) == Rational(22, 0) and
        Rational(22, 9) - Rational(-22, 0) == Rational(22, 0) and
        Rational(0, 9) - Rational(-22, 0) == Rational(22, 0) and
        Rational(-22, 9) - Rational(-22, 0) == Rational(22, 0) and
        (Rational(-22, 0) - Rational(-22, 0)).isNaN() and

        (Rational(22, 0) - Rational(0, 0)).isNaN() and
        (Rational(22, 9) - Rational(0, 0)).isNaN() and
        (Rational(0, 9) - Rational(0, 0)).isNaN() and
        (Rational(-22, 9) - Rational(0, 0)).isNaN() and
        (Rational(-22, 0) - Rational(0, 0)).isNaN()
):
    print('Subtraction test passed')
else:
    print('Subtraction test failed')

if (Rational(22, 0) * Rational(22, 0) == Rational(22, 0) and
        Rational(22, 9) * Rational(22, 0) == Rational(22, 0) and
        (Rational(0, 9) * Rational(22, 0)).isNaN() and
        Rational(-22, 9) * Rational(22, 0) == Rational(-22, 0) and
        Rational(-22, 0) * Rational(22, 0) == Rational(-22, 0) and

        Rational(22, 0) * Rational(22, 9) == Rational(22, 0) and
        Rational(22, 9) * Rational(22, 9) == Rational(22 * 22, 9 * 9) and
        Rational(0, 9) * Rational(22, 9) == Rational(0, 9) and
        Rational(-22, 9) * Rational(22, 9) == Rational(-22 * 22, 9 * 9) and
        Rational(-22, 0) * Rational(22, 9) == Rational(-22, 0) and

        (Rational(22, 0) * Rational(0, 1)).isNaN() and
        Rational(22, 9) * Rational(0, 1) == Rational(0, 9) and
        Rational(0, 9) * Rational(0, 1) == Rational(0, 9) and
        Rational(-22, 9) * Rational(0, 1) == Rational(0, 9) and
        (Rational(-22, 0) * Rational(0, 1)).isNaN() and

        Rational(22, 0) * Rational(-22, 9) == Rational(-22, 0) and
        Rational(22, 9) * Rational(-22, 9) == Rational(-22 * 22, 9 * 9) and
        Rational(0, 9) * Rational(-22, 9) == Rational(0, 9) and
        Rational(-22, 9) * Rational(-22, 9) == Rational(22 * 22, 9 * 9) and
        Rational(-22, 0) * Rational(-22, 9) == Rational(22, 0) and

        Rational(22, 0) * Rational(-22, 0) == Rational(-22, 0) and
        Rational(22, 9) * Rational(-22, 0) == Rational(-22, 0) and
        (Rational(0, 9) * Rational(-22, 0)).isNaN() and
        Rational(-22, 9) * Rational(-22, 0) == Rational(22, 0) and
        Rational(-22, 0) * Rational(-22, 0) == Rational(22, 0) and

        (Rational(22, 0) * Rational(0, 0)).isNaN() and
        (Rational(22, 9) * Rational(0, 0)).isNaN() and
        (Rational(0, 9) * Rational(0, 0)).isNaN() and
        (Rational(-22, 9) * Rational(0, 0)).isNaN() and
        (Rational(-22, 0) * Rational(0, 0)).isNaN()
):
    print('Multiplication test passed')
else:
    print('Multiplication test failed')

if ((Rational(22, 0) / Rational(22, 0)).isNaN() and
        Rational(22, 9) / Rational(22, 0) == Rational(0, 9) and
        Rational(0, 9) / Rational(22, 0) == Rational(0, 9) and
        Rational(-22, 9) / Rational(22, 0) == Rational(0, 9) and
        (Rational(-22, 0) / Rational(22, 0)).isNaN() and

        Rational(22, 0) / Rational(22, 9) == Rational(22, 0) and
        Rational(22, 9) / Rational(22, 9) == Rational(9, 9) and
        Rational(0, 9) / Rational(22, 9) == Rational(0, 9) and
        Rational(-22, 9) / Rational(22, 9) == Rational(-9, 9) and
        Rational(-22, 0) / Rational(22, 9) == Rational(-22, 0) and

        Rational(22, 0) / Rational(0, 1) == Rational(22, 0) and
        Rational(22, 9) / Rational(0, 1) == Rational(22, 0) and
        (Rational(0, 9) / Rational(0, 1)).isNaN() and
        Rational(-22, 9) / Rational(0, 1) == Rational(-22, 0) and
        Rational(-22, 0) / Rational(0, 1) == Rational(-22, 0) and

        Rational(22, 0) / Rational(-22, 9) == Rational(-22, 0) and
        Rational(22, 9) / Rational(-22, 9) == Rational(-9, 9) and
        Rational(0, 9) / Rational(-22, 9) == Rational(0, 9) and
        Rational(-22, 9) / Rational(-22, 9) == Rational(9, 9) and
        Rational(-22, 0) / Rational(-22, 9) == Rational(22, 0) and

        (Rational(22, 0) / Rational(-22, 0)).isNaN() and
        Rational(22, 9) / Rational(-22, 0) == Rational(0, 9) and
        Rational(0, 9) / Rational(-22, 0) == Rational(0, 9) and
        Rational(-22, 9) / Rational(-22, 0) == Rational(0, 9) and
        (Rational(-22, 0) / Rational(-22, 0)).isNaN() and

        (Rational(22, 0) / Rational(0, 0)).isNaN() and
        (Rational(22, 9) / Rational(0, 0)).isNaN() and
        (Rational(0, 9) / Rational(0, 0)).isNaN() and
        (Rational(-22, 9) / Rational(0, 0)).isNaN() and
        (Rational(-22, 0) / Rational(0, 0)).isNaN()
):
    print('Division test passed')
else:
    print('Division test failed')

if (equal(float(Rational(-22, -9)), 22 / 9.0) and
        equal(float(Rational(-9, -9)), 1) and
        equal(float(Rational(-6, -9)), 6 / 9.0) and
        equal(float(Rational(0, -9)), 0) and
        equal(float(Rational(6, -9)), -6 / 9.0) and
        equal(float(Rational(9, -9)), -1) and
        equal(float(Rational(22, -9)), -22 / 9.0) and
        math.isinf(float(Rational(-9, 0))) and
        math.isnan(float(Rational(0, 0))) and
        math.isinf(float(Rational(9, 0))) and
        equal(float(Rational(-22, 9)), -22 / 9.0) and
        equal(float(Rational(-9, 9)), -1) and
        equal(float(Rational(-6, 9)), -6 / 9.0) and
        equal(float(Rational(0, 9)), 0) and
        equal(float(Rational(6, 9)), 6 / 9.0) and
        equal(float(Rational(9, 9)), 1) and
        equal(float(Rational(22, 9)), 22 / 9.0)
):
    print('Conversion to double test passed')
else:
    print('Conversion to double test failed')

if (bool(Rational(-22, -9)) and
        bool(Rational(-9, -9)) and
        bool(Rational(-6, -9)) and
        not bool(Rational(0, -9)) and
        bool(Rational(6, -9)) and
        bool(Rational(9, -9)) and
        bool(Rational(22, -9)) and
        bool(Rational(-9, 0)) and
        bool(Rational(0, 0)) and
        bool(Rational(9, 0)) and
        bool(Rational(-22, 9)) and
        bool(Rational(-9, 9)) and
        bool(Rational(-6, 9)) and
        not bool(Rational(0, 9)) and
        bool(Rational(6, 9)) and
        bool(Rational(9, 9)) and
        bool(Rational(22, 9))
):
    print('Conversion to bool test passed')
else:
    print('Conversion to bool test failed')