N = int(input())
a = list(map(int,input().split()))
a.insert(0,0)

div_ans = []
for i in range(1,N+1):
    sm = 0
    div = N //i #加える玉の数
    for k in range(1,div+1):
        sm += a[i*k]
        div_ans.append(sm)

ans_i = -1
flag = False
for i in range(N):
    if div_ans[i] % 2 ==a[i]:
        flag = True
        ans_i = i
        break

if flag == True:
    b = []
    for k in range(1,N//ans_i+1):
        b.append(a[k*ans_i])



