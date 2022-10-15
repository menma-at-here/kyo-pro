N,K = map(int,input().split())
A = list(map(int,input().split()))
B = sorted(A,reverse = True)
C = []
D = [] #二進数を大きい順に並べたリスト
for i in range(N):
    C.append(format(B[i],'b'))
print(type(format(B[0,b])))
    #D.append(str(bin(B[i])))

    