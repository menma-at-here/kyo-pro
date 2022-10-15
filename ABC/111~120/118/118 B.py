N,M = map(int,input().split())
K = []
for i in range (N):
    K.append(list(map(int,input().split())))
ans = 0
yobi = 0

for i in range(1,M+1):
    for j in range (N):
        for k in range(1,K[j][0]+1):
            if K[j][k]  == i:
                yobi += 1
        
    if yobi == N:
        ans += 1
        yobi = 0
    
    else:
        yobi = 0

print(ans)    
        