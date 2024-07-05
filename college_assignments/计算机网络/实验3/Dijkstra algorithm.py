import math

# Dijkstra算法
def dijkstra(start, graph):
    num_nodes = len(graph)  # 节点数量
    distance = [math.inf] * num_nodes  # 初始化该节点的距离数组，初始值为无穷大:[inf, inf, inf, inf, inf, inf]
    distance[start] = 0  # 起点到自身的距离为0:[0, inf, inf, inf, inf, inf] 以0为例
    N_prime = set()  # 存储已经找到最短路径的节点集合
    path = {start: [start]}  # 存储起点到每个节点的路径

    while len(N_prime) < num_nodes:  # 循环直到所有节点都被访问过
        min_dist = math.inf  # 设置为正无穷大可以确保第一个被选中的节点一定是未访问节点中距离起点最近的节点
        min_node = -1
        for i in range(num_nodes):
            if i not in N_prime and distance[i] < min_dist:  # 选择未访问节点中距离我这个起始点最近的节点作为下一个访问节点
                min_dist = distance[i]
                min_node = i

        N_prime.add(min_node)  # 将该节点加入已找到最短路径的节点集合

        for i in range(num_nodes):  # 更新其他节点的距离
            if i not in N_prime and graph[min_node][i] != math.inf:  # 对于正在访问节点，更新其距离
                new_dist = distance[min_node] + graph[min_node][i]  # 计算新的距离：新的距离=起点到该点的距离+该点到其他节点的距离
                if new_dist < distance[i]:  # 如果新的距离小于已有的距离，则更新
                    distance[i] = new_dist
                    path[i] = path[min_node] + [i]  # 更新路径

    return distance, path  # 返回起点到各个节点的最短距离和路径

# 图的邻接矩阵表示
graph = [
    [0.0, 1.0, math.inf, 6.0, math.inf, math.inf],
    [1.0, 0.0, 3.0, 4.0, math.inf, math.inf],
    [math.inf, 3.0, 0.0, 2.0, 6.0, math.inf],
    [6.0, 4.0, 2.0, 0.0, 9.0, 2.0],
    [math.inf, math.inf, 6.0, 9.0, 0.0, math.inf],
    [math.inf, math.inf, math.inf, 2.0, math.inf, 0.0]
]

# 计算所有节点到其他节点的最短距离和路径
for start_node in range(len(graph)):
    distances, paths = dijkstra(start_node, graph)  # 调用Dijkstra算法计算最短距离和路径
    print("起点{}号节点到其他节点的最短距离：".format(start_node))
    for i in range(len(distances)):  # 输出最短距离和路径
        if i != start_node:
            print("到{}号节点最短距离".format(i), ":", distances[i], "\n 最短路径:", paths[i])

    print("---------------------------")
