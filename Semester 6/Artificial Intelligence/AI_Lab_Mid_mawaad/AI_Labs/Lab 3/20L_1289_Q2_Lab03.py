def readCube(filename):
    file = open(filename, 'r')
    cube = []
    for line in file:
        cube.append([int(x) for x in line.split()])
    return cube

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

def A_star(graph, start, end):
    open = []
    closed = []
    open.append([start, 0, 0])
    while len(open) > 0:
        open.sort(key=lambda x: x[1] + x[2])
        current = open.pop(0)
        closed.append(current[0])
        if current[0] == end:
            path = []
            while current[0] != start:
                path.append(current[0])
                current = current[3]
            path.append(start)
            path.reverse()
            return path
        for node in graph[current[0]]:
            if node not in closed:
                g = current[1] + 1
                h = abs(node[0] - end[0]) + abs(node[1] - end[1])
                for i in range(len(open)):
                    if open[i][0] == node and open[i][1] <= g:
                        break
                else:
                    open.append([node, g, h, current])
                    
    return None

def printPath(path):
    for i in range(len(path)):
        print(path[i], end=" ")

def main():
    cube = readCube("data.txt")
    graph = convertToGraph(cube)
    path = A_star(graph, (0, 0), (len(cube) - 1, len(cube[0]) - 1))
    printPath(path)

if __name__ == "__main__":
    main()