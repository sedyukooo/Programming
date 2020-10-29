from random import *
x = 0
while (x == 0) | (x == 1):
    n = randint(0, 100)
    for y in range(5):
        y = int(input("Введите целое число:"))
        if y == n:
            print("Поздравляю! Вы угадали")
        elif y > n:
            print("Загаданное число меньше")
        elif y < n:
            print("Загаданное число больше")
    if y != n:
        print("Вы проиграли. Было загадано:", n)
    x = int(input("Хотите начать сначала? (1 - ДА )"))










