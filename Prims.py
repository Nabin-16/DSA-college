import math
from queue import PriorityQueue

graph = {
    '1': {'4': 1, '5': 4, '2': 2},
    '2': {'1': 2, '3': 3, '4': 3, '6': 7},
    '3': {'2': 3, '4': 5, '6': 8},
    '4': {'1': 1, '2': 3, '3': 5, '5': 9},
    '5': {'1': 4, '4': 9},
    '6': {'2': 7, '3': 8}
}

def temp_graph(graph, start):
    key = dict()
    parent = dict()
    for vertex in graph.keys():
        key[vertex] = math.inf
        parent[vertex] = None
    key[start] = 0
    return key, parent


def prim(graph, start):
    key, parent = temp_graph(graph, start)
    q = PriorityQueue()
    visited = {v: False for v in graph.keys()}
    for vertex in graph.keys():
        q.put((key[vertex], vertex))

    mst_edges = []
    total_weight = 0
    while not q.empty():
        _, temp = q.get()
        if visited[temp]:
            continue
        visited[temp] = True
        if parent[temp] is not None:
            mst_edges.append((parent[temp], temp, key[temp]))
            total_weight += key[temp]

        for neighbor, weight in graph[temp].items():
            if not visited[neighbor] and weight < key[neighbor]:
                parent[neighbor] = temp
                key[neighbor] = weight
                q.put((key[neighbor], neighbor))

    return mst_edges, total_weight

mst_edges, total_weight = prim(graph, '1')
print("MST edges:")
for u, v, w in mst_edges:
    print(f"{u} -> {v}, weight={w}")

print("Total weight of MST:", total_weight)