h1, m1 = map(int, input().split(':'))
h2, m2 = map(int, input().split(':'))
0 <= h1, h2 <= 23
0 <= m1, m2 <= 59
time1 = h1 + (m1/60)
time2 = h2 + (m2/60)
if (0 <= (time2 - time1) <= 0.25):
    print("Встреча состоялась.")
else:
    print("Встреча не состоялась.")