N,M = map(int,input().split())
X = list(map(int,input().split()))
X2 = sorted(X)
div_X = []
for i in range (M-1):
    div_X.append(X2[i+1]-X2[i])
Y = sorted(div_X)


if N >= M:
    ans = 0
else:
    ans = sum(Y[0:M-N])

print (ans)
