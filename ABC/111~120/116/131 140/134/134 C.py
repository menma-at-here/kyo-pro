N = int(input())
A =[0] * N
for i in range(N):
    A[i] = int(input())

A_l = [A[0]] #左から数えた最大値
A_r = [A[N-1]] #右から数えた最大値

for i in range(1,N-1):
    A_l.append(max(A_l[i-1],A[i]))

for i in range(1,N-1):
    A_r.append(max(A_r[i-1],A[-(i+1)]))

ans =[]
ans.append(A_r[N-2])
for k in range(N-2):
    ans.append(max(A_l[k],A_r[-(k+2)]))

ans.append(A_l[N-2])

for i in range(N):
    print(ans[i])