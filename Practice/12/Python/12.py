try:
    a=int(input())
    rezult=1
    if a>=0:
        for i in range(1,a+1):
            rezult*=i
        print(rezult)
        
except ValueError:
    print("Введите целое положительное число")
