S = str(input())
m =0
maxi = 0
for i in range(0,len(S)):
    if S[i] == 'A' or S[i] == 'G'or S[i] == 'C'or S[i] == 'T' :
        m = m + 1 
        maxi = max(maxi,m)
    else:
        m = 0
        maxi = maxi
print(maxi)

