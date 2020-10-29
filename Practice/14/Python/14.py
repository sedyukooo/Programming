try:
    n=int(input())
    rezult=0
    multiplicand=1

    while multiplicand <= n:
        multiplicand *=2
        rezult+=1

    print(rezult)

except ValueError:
    print("Ошибка ввода.")
