N , K = map(int,input().split())
S = str(input())
T =[] #０と１の個数を並べていったリスト
m = 1
for i in range(N-1):
    if S[i] == S[i + 1]:
        m = m + 1
    else:
        T.append(m)
        m = 1
T.append(m)
n = len(T)

left_1 = []
left_0 = []
if S[0] == str(1):
    if K >= (len(T) // 2):
        ans = N
    else:
        if len(T) % 2 == 0:
            i = 0
            while 2*i + 2*K + 1 <= n:
                left_1.append(sum(T[2*i:2*i+2*K+2]))
            left_1.append(sum(T[n - 2*K :n]))
            ans = max(left_1)
        else:
            i = 0
            while 2*i + 2*K + 1 <= n:
                left_1.append(sum(T[2*i:2*i+2*K+2]))
            ans = max(left_1)

else: # if S[0] == 0:
    if n % 2 == 0: 
        if K >= (len(T) / 2):
            ans = N
        else:
            left_0.append(sum(T[0:2*K]))
            i = 0
            while 2*i + 2*K + 2 <= n:
                left_1.append(sum(T[2*i + 1:2*i + 2*K + 3]))
            ans = max(left_0)
    
    else:
        if K >= (len(T)//2 + 1):
            ans = N
        else:
            left_0.append(sum(T[0:2*K]))
            left_0.append(sum(T[n-2*K:n]))
            while 2*i + 2*K + 2 <= n:
                left_1.append(sum(T[2*i + 1:2*i + 2*K + 3]))
            ans = max(left_0)

print (left_1)
print (ans)
           
