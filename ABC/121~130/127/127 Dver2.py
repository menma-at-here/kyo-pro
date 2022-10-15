N,M = map(int,input().split())
A = list(map(int,input().split()))
B = [0]*M
C = [0]*M
for i in range (M):
    B[i],C[i] = map(int,input().split())
sortA = sorted(A)
for i in range(M):
    if sortA[B[i]-1] <= C[i]:
        m = 0
        j = B[i]
        while sortA[j] <= C[i]:
            m += 1
        for k in range (m):
            sortA[k] = sortA[k+B[i]]
        for k in range (m,B[i]+m):
            sortA[k] = C[i]
            
    else:
        j = 0
        while sortA[j] <= C[i]:
            sortA[j] = C[i]
            
print(sum(sortA))
    
