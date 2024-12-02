#ifndef GRATH_CPP
#define GRATH_CPP

#include <iostream>
#include <vector>
#include <list>

struct Edge {
    int from;
    int to;
};

struct Graph {
    std::vector<std::list<Edge>> adj;
    int size;

    Graph(int n) : adj(n), size(n) {}

    void addEdge(int from, int to) {
        adj[from].push_back({from, to});
        adj[to].push_back({to, from});
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << i << " -> ";
            for (const auto& edge : adj[i]) {
                std::cout << edge.to << " ";
            }
            std::cout << '\n';
        }
    }
};

#endif

