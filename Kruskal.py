graph = {
    'A': {'B': 4, 'C': 2},
    'B': {'A': 4, 'C': 1, 'D': 5},
    'C': {'A': 2, 'B': 1, 'D': 8, 'E': 10},
    'D': {'B': 5, 'C': 8, 'E': 2, 'F': 6},
    'E': {'C': 10, 'D': 2, 'F': 3},
    'F': {'D': 6, 'E': 3}
}
class DisjointSet:
    def __init__(self, vertices):
        self.parent = {v: v for v in vertices}
        self.rank = {v: 0 for v in vertices}

    # Path compression
    def find(self, v):
        if self.parent[v] != v:
            self.parent[v] = self.find(self.parent[v])
        return self.parent[v]
    # Union by rank
    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u == root_v:
            return False
        if self.rank[root_u] < self.rank[root_v]:
            self.parent[root_u] = root_v
        elif self.rank[root_u] > self.rank[root_v]:
            self.parent[root_v] = root_u
        else:
            self.parent[root_v] = root_u
            self.rank[root_u] += 1
        return True

def kruskal(graph):
    edges = []
    for u in graph:
        for v, w in graph[u].items():
            if (v, u, w) not in edges:
                edges.append((u, v, w))
    edges.sort(key=lambda x: x[2])
    ds = DisjointSet(graph.keys())
    mst_edges = []
    total_weight = 0
    for u, v, w in edges:
        if ds.union(u, v):
            mst_edges.append((u, v, w))
            total_weight += w

    return mst_edges, total_weight

mst_edges, total_weight = kruskal(graph)

print("Edges in MST:")
for u, v, w in mst_edges:
    print(f"{u} - {v} : {w}")
print("Total weight of MST:", total_weight)
