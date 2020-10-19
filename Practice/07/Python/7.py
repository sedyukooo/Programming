import math

print("Расчёт площади треугольника двумя способами:",
      "1 - Через длины сторон a, b, c",
      "2 - Через координаты точек A, B, C",
      "Ввыберите способ расчёта и введите цифру, соответсвующую ему: ", sep="\n")
x = float(input())
if x == 1:                                                #Через длины сторон a, b, c
    print("Введите значения:")
    a = float(input("a="))
    b = float(input("b="))
    c = float(input("c="))
    if (a + b > c) and (a + c > b) and (b + c > a):
        P = a+b+c
        S = math.sqrt((P * (P - a) * (P - b) * (P - c)))
        print("S=", S)
    else:
        print("Треугольника с данынми длинами сторон не существует.")

if x == 2:                                                #Через координаты точек A, B, C
    print("Введите значения:")
    x1, y1 = map(float, input().split())
    x2, y2 = map(float, input().split())
    x3, y3 = map(float, input().split())
    AB = math.sqrt((x2-x1)**2 + (y2-y1)**2)
    BC = math.sqrt((x3-x2)**2 + (y3-y2)**2)
    AC = math.sqrt((x3-x1)**2 + (y3-y1)**2)
    if (AB + BC > AC) and (AB + AC > BC) and (BC + AC > AB):
        P = AB + BC + AC
        S = math.sqrt((P * (P - AB) * (P - BC) * (P - AC)))
        print("S=", S)
    else:
        print("Треугольника с данынми длинами сторон не существует.")

