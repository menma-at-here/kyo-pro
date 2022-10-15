N,M = map(int,input().split())
a = []
if M >= 1:
    for i in range(M):
        a.append(int(input()))

def fibo(n):
    a, b = 1, 1
    if (n == 0) or (n == 1) or (n == 2):
        return 1
    else:
        for _ in range(n-2):
            a, b = b, a + b
        return b

aa = [] #aの差を取ったもののリスト
if M >= 2:
    for k in range(M-1):
        aa.append(a[k+1] - a[k] - 1)
#print(aa)
#aa.append(N - a(M))

    if 0 in aa:
        ans = 0

    else:
        ans = 1
        ans_list = []
        for i in range(M-1):
            ans_list.append(fibo(aa[i]))

        ans_list.append(fibo(a[0]))
        ans_list.append(fibo(N - a[M-1]))
    #print(ans_list)
    
        for i in range (len(ans_list)):
            ans = (ans * ans_list[i]) % (10**9 + 7)

elif M == 1:
    ans_list = []
    ans_list.append(fibo(a[0]))
    ans_list.append(fibo(N - a[0]))
    ans = (ans_list[0] * ans_list[1]) % (10**9 + 7)

elif M == 0:
    ans = fibo(N+1) % (10**9 + 7)

print(ans)
