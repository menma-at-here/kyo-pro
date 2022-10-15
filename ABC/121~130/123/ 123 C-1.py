 N = int(input())
cyapa = []
for i in range (1,6):
    cyapa.append(int(input()))
city1 = N
city2 = 0
city3 = 0
city4 = 0
city5 = 0
city6 = 0
mi = 0
while city6 < N:
    city6 = city6 + min(city5,cyapa[4])
    city5 = city5 + min(city4,cyapa[3]) - min(city5,cyapa[4])
    city4 = city4 + min(city3,cyapa[2]) - min(city4,cyapa[3])
    city3 = city3 + min(city2,cyapa[1]) - min(city3,cyapa[2])
    city2 = city2 + min(city1,cyapa[0]) - min(city2,cyapa[1])
    city1 = city1 - min(city1,cyapa[0])
    mi = mi + 1
print(mi)