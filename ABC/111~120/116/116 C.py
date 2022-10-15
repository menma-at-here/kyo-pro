N = int(input())
h = list(map(int,input().split()))
if max(h) == min(h):
    ans = h[0]

else:
    same = []
    for i in range(N-1):
        if h[i] == h[i+1]:
            same.append(i)
    
    if len(same) >= 1:
        for k in range (len(same))[::-1]:
            del h[same[k]]
    
    N = len(h)

    lmin = [] #極小値のリスト
    lmax = [] #極大値のリスト

    if N >=3:
        for i in range(1,N-1):
            if (h[i] > h[i-1]) and (h[i] > h[i+1]):
                lmax.append(h[i])
        
        for k in range(1,N-1):
            if (h[k] < h[k-1]) and (h[k] < h[k+1]):
                lmin.append(h[k])

        if h[0] > h[1]:
            lmax.append(h[0])
            
        if h[N-1] > h[N -2]:
            lmax.append(h[N-1])
                
        if (len(lmax) == 1) :
            ans = max(h)

        else:
            ans = sum(lmax) - sum(lmin)
    
    if N == 2:
        ans = max(h)

    if N == 1:
        ans = h[0]

#print(lmax)
#print(lmin)
print(ans)
