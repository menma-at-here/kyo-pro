N,Q = map(int,input().split())
S = str(input())
ans = [0]*(N+1)
ans[0] = 0
for i in range (N):
    if (S[i:i+2]) == 'AC':
        ans[i+1] = ans[i] + 1
    else:
        ans[i+1] = ans[i]

for k in range(Q):
    l,r = map(int,input().split())
    print(ans[r-1]-ans[l-1])
