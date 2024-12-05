#include <iostream>
#include "graph_type.hpp"
#include <unordered_map>
#include <unordered_set>

typedef std::unordered_map<int, std::unordered_set<int>> edges;

class Print {
public:
    void operator() (const int& size, Graph* graph, std::string index = "adjacency list") {
        if (index == "adjacency list") {
            adjacency_list(size, graph);
        } else if (index == "lists of incidents") {
            lists_of_incidents(size, graph);
        } else if (index == "Incidence Matrix") {
            Incidence_Matrix(size, graph);
        }
    }
private:
    void adjacency_list(const int& size, Graph* graph) const {
        for (int i = 0; i < size; ++i) {
            std::cout << i << " -> ";
            for (const auto& edge : graph->adj[i]) {
                std::cout << edge.to << " ";
            }
            std::cout << '\n';
        }
    }

    void lists_of_incidents(const int& size, Graph* graph) const {
        for (int i = 0; i < size; ++i) {
            std::cout << i << " -> ";
            for (const auto& edge : graph->adj[i]) {
                std::cout << "(" << edge.from << ", " << edge.to << ") ";
            }
            std::cout << '\n';
        }
    }

    void Incidence_Matrix(const int& size, Graph* graph) {
        edges edgeMap;

        int edgeId = 0;
        for (int u = 0; u < size; ++u) {
            for (const auto& edge : graph->adj[u]) {
                int v = edge.to;
                if (u < v) {  
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

Print print;