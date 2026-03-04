graph = {
    'A': ['B', 'C'],
    'B': ['A', 'C'],
    'C': ['A', 'B', 'D'],
    'D': ['C', 'E', 'F'],
    'E': ['D', 'F'],
    'F': ['D', 'E']
}
def DFT(graph, start):
    visited = {v: False for v in graph.keys()}
    stack = [start]
    traversal = []
    while stack:
        temp = stack.pop()
        if not visited[temp]:
            visited[temp] = True
            traversal.append(temp)
            for neighbor in graph[temp]:
                if not visited[neighbor]:
                    stack.append(neighbor)
    print("The order of traversal is:")
    print(" -> ".join(traversal))
DFT(graph, 'A')
