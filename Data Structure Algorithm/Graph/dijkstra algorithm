
#Using the heap, reduce timecomplexity.

import heapq

def dijkstra(vertex, node, start, end):
    meet = set()
    notyet = set()
    distance = []
    distance2 = dict()
    for i in vertex:
        notyet.add(i)
        if i != start:
            heapq.heappush(distance, (float('inf'), i))
            distance2[i] = float('inf')
        else:
            heapq.heappush(distance, (0, i))
            distance2[i] = 0
    while len(distance) > 0:
        p = heapq.heappop(distance)
        nowvertex = p[1]
        value = p[0]
        if nowvertex in meet:
            continue
        for i in node[nowvertex].keys():
            k = node[nowvertex][i]
            heapq.heappush(distance, (value + k, i))
            distance2[i] = min(distance2[i], value + k)
        meet.add(nowvertex)
    return distance2[end]

vertex = ['A', 'B', 'C', 'D', 'E', 'F']
node = dict()
for i in vertex:
    node[i] = dict()

node['A']['B'], node['A']['C'], node['A']['D'] = 10, 30, 15
node['B']['E'] = 20
node['C']['F'] = 5
node['D']['C'], node['D']['F'] = 5, 20
node['E']['F'] = 20
node['F']['D'] = 20

print(dijkstra(vertex, node, 'A', 'F')) # 25
