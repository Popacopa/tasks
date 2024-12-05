#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>

typedef std::unordered_map<int, std::unordered_set<int>> edges;

struct Edge {
    int from;
    int to;
};

struct Graph {

    typedef std::vector<std::list<Edge>> Graph_data;

    Graph_data adj;
    int size; 

    Graph(int n) : adj(n), size(n) {
    }

    int count_edge() const {
        int edgecount = 0;
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

    void Incidence_Matrix() {
        //int numVertices = adj.size();
        edges edgeMap;

        int edgeId = 0;
        for (int u = 0; u < size; ++u) {
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
        std::vector<std::vector<int>> incMatrix(size, std::vector<int>(numEdges, 0));
 
        for (int u = 0; u < size; ++u) {
            for (int edgeId : edgeMap[u]) {
                incMatrix[u][edgeId] = 1;
            }
        }
        for (int y = 0; y < incMatrix.size(); y++) {
            for (int x = 0; x < incMatrix[0].size(); x++) {
                std::cout << incMatrix[y][x] << (x + 1 == incMatrix[0].size() ? "\n" : " ");
            }
        }
    }
};

#endif

