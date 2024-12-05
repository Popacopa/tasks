#ifndef GRAPH_CPP
#define GRAPH_CPP

//#include <iostream>
#include <vector>
#include <list>

struct Edge {
    int from;
    int to;
};

struct Graph {

    std::vector<std::list<Edge>> adj;
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
    }
};

#endif

