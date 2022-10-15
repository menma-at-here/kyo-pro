N = int(input())
cyapa = []
for i in range (1,6):
    cyapa.append(int(input()))
kasu = min(cyapa)
if kasu >= N:
    ans = 5
else:
    ans = 5 + N//kasu
print(ans)