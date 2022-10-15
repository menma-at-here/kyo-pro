N = int(input())
H = list(map(int,input().split()))
m = 0
high = H[0]
for i in range (N):
    if H[i] >= high:
        high = H[i]
        m = m + 1
print(m)