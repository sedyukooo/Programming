z = '+' or '-' or '*' or '/'
x, y = map(float, input().split(z))

if z == '+':
    rezult = x + y
elif z == '-':
    rezult = x - y
elif z =='*':
    rezult = x * y
elif (z=='/'):
	if (y!=0):
		rezult=x/y
	else:
		print("Деление на 0.")
print(rezult)
except ValueError:
    print("Это не правильный ввод!")