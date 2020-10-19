a = 9.8
x, v, t = map(float, input().split())
s=x+v*t-(a*t**2)/2
print(s)
