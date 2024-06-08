def dfs(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    for node in graph[start]:
        if node not in path:
            newpath = dfs(graph, node, end, path)
            if newpath: return newpath
    return None

def bfs(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    for node in graph[start]:
        if node not in path:
            newpath = bfs(graph, node, end, path)
            if newpath: return newpath
    return None


def readCube(filename):
    file = open(filename, 'r')
    cube = []
    for line in file:
        cube.append([int(x) for x in line.split()])
    return cube

# function to convert 2d array to a graph
def convertToGraph(cube):
    graph = {}
    for i in range(len(cube)):
        for j in range(len(cube[i])):
            if cube[i][j] == 0:
                graph[(i, j)] = []
                if i > 0 and cube[i - 1][j] == 0:
                    graph[(i, j)].append((i - 1, j))
                if i < len(cube) - 1 and cube[i + 1][j] == 0:
                    graph[(i, j)].append((i + 1, j))
                if j > 0 and cube[i][j - 1] == 0:
                    graph[(i, j)].append((i, j - 1))
                if j < len(cube[i]) - 1 and cube[i][j + 1] == 0:
                    graph[(i, j)].append((i, j + 1))
    return graph

# function to find the path using DFS
def findPath(graph, start, end, method):
    if method == "dfs":
        return dfs(graph, start, end)
    elif method == "bfs":
        return bfs(graph, start, end)

# function to print the path
def printPath(path):
    for i in range(len(path)):
        print(path[i], end=" ")
        if i != len(path) - 1:
            print("->", end=" ")

# main function
def main():
    cube = readCube("data.txt")
    graph = convertToGraph(cube)
    print("DFS: ", end="")
    path = findPath(graph, (0, 0), (len(cube) - 1, len(cube[0]) - 1), "dfs")
    if path is None:
        print("No path found")
    else:
        printPath(path)
    
    print("\nBFS: ", end="")
    path = findPath(graph, (0, 0), (len(cube) - 1, len(cube[0]) - 1), "bfs")
    if path is None:
        print("No path found")
    else:
        printPath(path)

if __name__ == "__main__":
    main()
