N,Q = map(int,input().split())
S = str(input())
for _ in range(Q):
    l,r = map(int,input().split())
for i in range (Q):
    S_i =[]
    ac = 0
    for k in range(l-1,r):
        S_i.append(S[k])
    for j in range(len(S_i)-1):
        if (S_i[j] == 'A' and S_i[j+1] =='C'):
            ac = ac + 1
            print(ac)
    print(ac)

