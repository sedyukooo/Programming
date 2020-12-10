from random import randint
a = input()
l = a.split()
X = [int(x) for x in l]

def Sort(X):
    for i in range(1, len(X)):
        if(X[i - 1] > X[i]):
            return False
    return True
SortList = X
while not Sort(SortList):
    rand1 = randint(0, len(SortList) - 1)
    rand2 = randint(0, len(SortList) - 1)
    swap = SortList[rand1]
    SortList[rand1] = SortList[rand2]
    SortList[rand2] = swap
print(SortList)
def Sort(X):
    for i in range(1, len(X)):
        if (X[i - 1] < X[i]):
            return False
    return True
SortList = X
while not Sort(SortList):
    rand1 = randint(0, len(SortList) - 1)
    rand2 = randint(0, len(SortList) - 1)
    swap = SortList[rand1]
    SortList[rand1] = SortList[rand2]
    SortList[rand2] = swap
print(SortList)
Y=[X[1],X[2],X[3]]
def Sort(Y):
    for i in range(1, len(Y)):
        if(Y[i - 1] > Y[i]):
            return False
    return True

SortList = Y
while not Sort(SortList):
    rand1 = randint(0, len(SortList) - 1)
    rand2 = randint(0, len(SortList) - 1)
    swap = SortList[rand1]
    SortList[rand1] = SortList[rand2]
    SortList[rand2] = swap
print(SortList)

Y=[X[1],X[2],X[3]]
def isSorted(Y):
    for i in range(1, len(Y)):
        if(Y[i - 1] < Y[i]):
            return False
    return True

SortList = Y
while not Sort(SortList):
    rand1 = randint(0, len(SortList) - 1)
    rand2 = randint(0, len(SortList) - 1)
    swap = SortList[rand1]
    SortList[rand1] = SortList[rand2]
    SortList[rand2] = swap
print(SortList)