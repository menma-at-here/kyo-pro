N,M = map(int,input().split())
A = list(map(int,input().split()))
B = [0]*M
C = [0]*M
for i in range (M):
    B[i],C[i] = map(int,input().split())
sortA = sorted(A)
for i in range(M):
    if sortA[B[i]-1] <= C[i]:
        for k in range (B[i]):
            sortA[k] = C[k]
        sortA = sorted(sortA)
    else:
        j = 0
        while sortA[j] <= C[i]:
            sortA[j] = C[i]
            sortA = sorted(sortA)

print(sum(sortA))
    
