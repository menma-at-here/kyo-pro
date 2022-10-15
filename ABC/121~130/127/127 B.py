r,D,x =map(int,input().split())
X = []
X.append(x)
for i in range(10):
    X.append(r*X[i] - D)
for i in range(1,11):
    print (X[i])
