from operator import itemgetter

N,M = map(int,input().split())
A = list(map(int,input().split()))
#B = [0]*M
#C = [0]*M
D = []
for i in range (M):
    #B[i],C[i] = list(map(int,input().split()))
    D.append(list(map(int,input().split())))
DD = sorted(D,key = itemgetter(1))
AA = sorted(A)
nC = [] #大きい順にCをB個ずつ並べたリスト
while len(nC) <=N:
    for i in range (M):
        for _ in range (DD[i][1]):
            nC.append(DD[i][2])

j = 0
while nC[j] >= AA[j]:
    AA[j] = nC[j]

print(sum(AA))
