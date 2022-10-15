from operator import itemgetter

N,M = map(int,input().split())
A = list(map(int,input().split()))

D = []
for i in range (M):
    
    D.append(list(map(int,input().split())))
DD = sorted(D,key = itemgetter(1),reverse = True)
#print (DD)
AA = sorted(A)
nC = [] #大きい順にCをB個ずつ並べたリスト
for i in range (M):
    for _ in range (DD[i][0]):
        if len(nC) <= N:
            nC.append(DD[i][1])
#print(nC)

j = 0 #AAの何番めか
k = 0 #nCの何番めか
for k in range (len(nC)):
    if nC[k] > AA[j]:
        AA[k] = nC[j]
        k += 1
        j += 1
    else:
        if j == 0:
            k += 1
        else:
            j = 0
        
print(sum(AA))