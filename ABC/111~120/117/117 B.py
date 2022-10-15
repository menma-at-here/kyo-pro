N = int(input())
L = list(map(int,input().split()))
Lmax = max(L)
if Lmax < sum(L) - Lmax:
    print('Yes')
else:
    print('No')