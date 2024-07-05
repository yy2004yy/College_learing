import math

def initialize_routing_table(graph):
    num_nodes = len(graph)
    routing_table = [{'distance': math.inf, 'path': []} for _ in range(num_nodes)]  # 根据图的大小创建了一个包含每个节点的初始距离为正无穷大、路径为空列表的路由表
    return routing_table

def distance_vector(node, graph):
    num_nodes = len(graph)  # 节点数量
    routing_table = initialize_routing_table(graph)  # 创建初始化路由表
    routing_table[node]['distance'] = 0  # 起点到自身距离为0
    calculated_nodes = {node}  # 存储已经计算过的节点

    for _ in range(num_nodes - 1):  # 只需要N-1次迭代
        updated = False
        for i in range(num_nodes):
            if i not in calculated_nodes:  # 如果i是没有计算过的节点
                continue
            for j in range(num_nodes):  # 如果i是被存储的计算过的节点
                if i != j and graph[i][j] != math.inf:  # 如果i和j是相邻节点的话
                    if routing_table[i]['distance'] + graph[i][j] < routing_table[j]['distance']:  # 实质：把此节点的路由表发送给其他节点，使其他节点更新自己的路由表
                        """ 
                        routing_table[i]['distance']是i节点的初始路由表
                        graph[i][j]是i节点到j节点的最短距离
                        routing_table[j]['distance']是j节点的初始路由表
                        """
                        routing_table[j]['distance'] = routing_table[i]['distance'] + graph[i][j]
                        routing_table[j]['path'] = routing_table[i]['path'] + [i]
                        updated = True
        if not updated:  # 如果没有路由表被更新，则说明已经找到了最短路径，可以退出循环
            break

        calculated_nodes.update([i for i in range(num_nodes) if routing_table[i]['distance'] != math.inf])  # 更新 calculated_nodes 集合

    return routing_table

graph = [
    [0.0, 1.0, math.inf, 6.0, math.inf, math.inf],
    [1.0, 0.0, 3.0, 4.0, math.inf, math.inf],
    [math.inf, 3.0, 0.0, 2.0, 6.0, math.inf],
    [6.0, 4.0, 2.0, 0.0, 9.0, 2.0],
    [math.inf, math.inf, 6.0, 9.0, 0.0, math.inf],
    [math.inf, math.inf, math.inf, 2.0, math.inf, 0.0]
]

for i in range(len(graph)):
    node = i  # 指定节点
    result = distance_vector(node, graph)
    print(node, "号节点到其他节点的最短距离：")
    for i in range(len(result)):
        if i != node:
            print("到{}号节点最短距离".format(i), ":", result[i]['distance'])

    print(node, "号节点到其他节点的最短路径：")
    for i in range(len(result)):
        if i != node:
            shortest_path = str(i)
            for n in result[i]['path'][::-1]:
                shortest_path = str(n) + ' -> ' + shortest_path
            print("到{}的最短路径".format(i), ":", shortest_path)
    print("---------------------------")