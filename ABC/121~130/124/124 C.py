S = int(input())
N = len(S)

if N%2 == 0:
    left_b = 0
    left_w = 0
    while i in range(N//2 - 1):
        if S[2*i] = 1: #もし奇数番目が白だったらひっくり返す
            left_b = left_b + 1
        if S[2*i+1] = 0:
            left_b = left_b + 1
        if S[2*i] = 0: #もし奇数番目が黑だったらひっくり返す
            left_w = left_w + 1
        if S[2*i+1] = 1:
            left_w = left_w + 1
        mini = min(left_b,left_w)
        
else:
    left_b2 = 0
    left_w2 = 0
    for i in range(N//2):
        if S[2*i] = 1: #もし奇数番目が白だったらひっくり返す
            left_b2 = left_b2 + 1
        if S[2*i+1] = 0:
            left_b2 = left_b2 + 1
        if S[2*i] = 0: #もし奇数番目が黑だったらひっくり返す
            left_w2 = left_w2 + 1
        if S[2*i+1] = 1:
            left_w2 = left_w2 + 1
    
        mini = min(left_b,left_w)
        