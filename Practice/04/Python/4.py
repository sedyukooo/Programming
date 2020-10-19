a, b = map(int, input().split())
c = a
a = b
b = c
print(a,b) #с помощью дополнительной переменной.

x, y = map(int, input().split())
x = x + y
y = x - y
x = x - y
print(x, y) #без помощи дополнительной переменной.