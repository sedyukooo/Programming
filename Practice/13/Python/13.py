import math
n = int(input())
i = 2
limit = int(math.sqrt(n))
flag = 1
if n < 2:
    print("Число должно быть больше 2")
else:
    while i <= limit:
        if n % i == 0:
            print("Составное")
            flag = 2

        i = i + 1
    if flag == 1:
        print("Простое")