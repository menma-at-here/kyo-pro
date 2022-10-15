import copy
N = int(input())
A = list(map(int, input().split()))
C=[]
for i in range(N):
     C.append(copy.copy(A))
B = []
for i in range(N):
    del C[i][i]
    B.append(C[i])
import math
from functools import reduce
D =[] #Aから一つを除いたものの最大公約数のリスト
for i in range(N):
    D.append(reduce(math.gcd,B[i]))
maxi = max(D)
print(maxi)