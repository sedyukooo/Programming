print("Введите данные для решения уравнения:")
a = input("a=")
b = input("b=")
c = input("c=")
a = float(a)
b = float(b)
c = float(c)
if a == 0:
    x = -c / b
    print("x=", x)
else:
    D = b ** 2 - 4 * a * c;
    print("D=", D)
    if D > 0:  # Дискриминант больше 0(два корня)
        x1 = (-b + D ** 0.5) / (2 * a)
        x2 = (-b - D ** 0.5) / (2 * a)
        print("x1 =", x1, "x2 =", x2)
    if D == 0:  # Дискриминант равен 0(один корень)
        x = (-b) / (2 * a)
        print("x= ", x)
    if D < 0:
        print("Корней нет")  # Дискриминант меньше 0(коней нет)