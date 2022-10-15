N,M = map(int,input().split())
L = [0]*M
R = [0]*M
for i in range(M):
    L[i],R[i] = map(int,input().split())
mL = max(L)
mR = min(R)
ans = 0
for i in range(1,N+1):
    if ((mL <=i) and (i<=mR)):
        ans += 1
print(ans)
