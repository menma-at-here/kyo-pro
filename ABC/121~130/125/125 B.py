N = int(input())
V = list(map(int,input().split()))
C = list(map(int,input().split()))
plus = []
for i in range(N):
    if (V[i] - C[i]) >=0:
        plus.append(int(V[i] - C[i]))
print(sum(plus))