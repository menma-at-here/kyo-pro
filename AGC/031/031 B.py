N = int(input())
C =[]
D = []
for _ in range (N):
    C.append(int(input()))
for i in range (N-1):
    if C[i+1] != C[i]:
        D.append(C[i])
if C[N] != C[N - 1]:
    D.append(C[N])
def same(left): #leftは一番左の駒、jはその右側の駒を指定、mはsum
    m = 0
    for i in range(left,N):
        if D[i] == D[left]:
            m = m + 1
            left = i + 1
    

