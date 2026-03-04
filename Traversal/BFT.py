from collections import deque
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'C'],
    'C': ['A', 'B', 'D'],
    'D': ['C', 'E', 'F'],
    'E': ['D', 'F'],
    'F': ['D', 'E']
}
def BFT(graph, start):
    visited = {v: False for v in graph.keys()}
    queue = deque([start])
    traversal = []
    while queue:
        temp = queue.popleft()
        if not visited[temp]:
            visited[temp] = True
            traversal.append(temp)
            for neighbor in graph[temp]:
                if not visited[neighbor]:
                    queue.append(neighbor)
    print("The order of traversal is:")
    print(" -> ".join(traversal))

BFT(graph, 'A')
