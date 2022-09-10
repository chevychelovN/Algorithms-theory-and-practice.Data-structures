# Параллельная обработка 

from heapq import heapreplace

p = [(0, i) for i in range(int(input().split()[0]))]
for t in map(int, input().split()):
    print(*reversed(heapreplace(p, (p[0][0] + t, p[0][1]))))
