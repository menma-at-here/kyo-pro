N = int(input())
W = list(map(int,input().split()))
sumW = []
for i in range (N):
    sumW.append(sum(W[0:i+1]) - sum(W[i+1:N]))
    
W2 =[]
for k in range (N):
    W2.append(abs(sumW[k]))

print(min(W2))

