
a = input()
l = a.split()
X = [int(x) for x in l]

def Sort(X):
    for i in range(1, len(X)):
        if(X[i - 1] > X[i]):
            return False
    return True
SortList = X
while Sort(SortList):


print(SortList)