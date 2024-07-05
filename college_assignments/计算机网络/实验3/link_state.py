import math

# Dijkstra算法
def dijkstra(start, graph):
    num_nodes = len(graph)  # 节点数量
    distance = [math.inf] * num_nodes  # 初始化距离数组，初始值为无穷大
    distance[start] = 0  # 起点到自身的距离为0
    path = [-1] * num_nodes  # 存储最短路径的前一个节点
    visited = [False] * num_nodes  # 标记节点是否被访问过

    for _ in range(num_nodes):  # 迭代所有节点
        min_dist = math.inf
        min_node = -1
        for i in range(num_nodes):
            if not visited[i] and distance[i] < min_dist:  # 选择未访问节点中距离最小的节点作为下一个访问节点
                min_dist = distance[i]
                min_node = i
        visited[min_node] = True  # 标记该节点为已访问

        for i in range(num_nodes):  # 更新其他节点的距离
            if not visited[i] and graph[min_node][i] != math.inf:  # 对于未访问节点，更新其距离
                new_dist = distance[min_node] + graph[min_node][i]  # 计算新的距离
                if new_dist < distance[i]:  # 如果新的距离小于已有的距离，则更新
                    distance[i] = new_dist
                    path[i] = min_node  # 记录最短路径中当前节点的前一个节点

    return distance, path  # 返回起点到各个节点的最短距离和最短路径的前一个节点


# 图的邻接矩阵表示
graph = [
    [0.0, 1.0, math.inf, 6.0, math.inf, math.inf],
    [1.0, 0.0, 3.0, 4.0, math.inf, math.inf],
    [math.inf, 3.0, 0.0, 2.0, 6.0, math.inf],
    [6.0, 4.0, 2.0, 0.0, 9.0, 2.0],
    [math.inf, math.inf, 6.0, 9.0, 0.0, math.inf],
    [math.inf, math.inf, math.inf, 2.0, math.inf, 0.0]
]

# 对每个节点进行Dijkstra算法计算
for i in range(len(graph)):
    distances, paths = dijkstra(i, graph)  # 调用Dijkstra算法计算最短距离和最短路径
    print(i, "号节点到其他节点的最短距离：")
    for j in range(len(distances)):  # 输出最短距离
        if j != i:
            print("Node", j, ":", distances[j])
    print(i, "号节点到其他节点的最短路径：")
    for j in range(len(paths)):  # 输出最短路径
        if j != i:
            if distances[j] == math.inf:  # 如果最短距离为无穷大，说明没有路径
                print(f"No path from {i} to {j}")
            else:
                path = []
                current = j
                while current != -1:  # 从终点开始逆序回溯最短路径
                    path.insert(0, str(current))
                    current = paths[current]
                print(f"Node {j}:", ' -> '.join(path))
    print("--------------------------------")  # 分隔不同起点的结果
