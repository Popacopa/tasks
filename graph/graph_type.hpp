#ifndef GRATH_CPP
#define GRATH_CPP

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>
#include <unordered_set>


struct Graph {
    struct Edge {
        //Edge(){num++;}
        int from;
        int to;
         //static int num;
    };

    typedef std::vector<std::list<Edge>> data;
    data adj;
    int size;

    Graph(int n) : adj(n), size(n) {
    }

    int count_edge() const {
        std::set<Edge> cache;
        int edgecount = 0;
        //std::set<Edge>::iterator it = cache.begin();
        for (const auto& core : adj) {
             edgecount += core.size();
        }
        return edgecount;
    }

    void addEdge(int from, int to) {
        adj[from].push_back({from, to});
        //adj[to].push_back({to, from});
    }

    void adjacency_list() const {
        for (int i = 0; i < size; ++i) {
            std::cout << i << " -> ";
            for (const auto& edge : adj[i]) {
                std::cout << edge.to << " ";
            }
            std::cout << '\n';
        }
    }

    void lists_of_incidents() const {
        for (int i = 0; i < size; ++i) {
            std::cout << i << " -> ";
            for (const auto& edge : adj[i]) {
                //std::cout << edge.from << " ";
                std::cout << "(" << edge.from << ", " << edge.to << ") ";
            }
            std::cout << '\n';
        }
    }

    void buildIncidenceMatrix() {
    int numVertices = adj.size();
    std::unordered_map<int, std::unordered_set<int>> edgeMap;

    // Создаем уникальные идентификаторы для ребер
    int edgeId = 0;
    for (int u = 0; u < numVertices; ++u) {
        for (const auto& edge : adj[u]) {
            int v = edge.to;
            if (u < v) {  // Для неориентированного графа учитываем ребро только один раз
                edgeMap[u].insert(edgeId);
                edgeMap[v].insert(edgeId);
                ++edgeId;
            }
        }
    }

    int numEdges = edgeId;
    std::vector<std::vector<int>> incidenceMatrix(numVertices, std::vector<int>(numEdges, 0));

    // Заполняем матрицу инцидентности
    for (int u = 0; u < numVertices; ++u) {
        for (int edgeId : edgeMap[u]) {
            incidenceMatrix[u][edgeId] = 1;
        }
    }
    for (int y = 0; y < incidenceMatrix.size(); y++) {
        for (int x = 0; x < incidenceMatrix[0].size(); x++) {
            std::cout << incidenceMatrix[y][x] << (x + 1 == incidenceMatrix[0].size() ? "\n" : " ");
        }
    }
}
};

#endif

