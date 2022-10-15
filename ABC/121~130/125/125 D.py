N = int(input())
A = list(map(int,input().split()))
B =[]
for i in range (N):
    B.append(abs(A[i]))
m = 0
for i in range (N):
    if A[i] < 0:
        m = m + 1
if m % 2 == 0:
    maxi = sum(B)
else:
    if 0 in A:
        maxi = sum(B)
    else:
        maxi = sum(B) - 2 * min(B)
print(maxi)