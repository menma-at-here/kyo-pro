S = str(input())
N = len(S)

left_b = 0
if N%2 == 0:
    for i in range(N//2):
        if S[2*i] == str(1): #もし奇数番目が白だったらひっくり返す
            left_b = left_b + 1
        if S[2*i+1] == str(0):
            left_b = left_b + 1
    mini = min(left_b,N - left_b)
        
else:
    for i in range(N//2):
        if S[2*i] == str(1): #もし奇数番目が白だったらひっくり返す
            left_b = left_b + 1
        if S[2*i+1] == str(0):
            left_b = left_b + 1
    if S[N-1] == str(1):
            left_b = left_b + 1
    mini = min(left_b,N - left_b)

print(mini)


        