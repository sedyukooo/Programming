import math

a=float(input())
b=int(input())

c=1
c=a
i=1

while (i<abs(b)):
    c*=a
    i+=1

if b>0:
    print(c)
elif b<0:
    print(1/c)
elif b==0:
    print("Результат = 1")
