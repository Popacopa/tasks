#ifndef GRATH_CPP
#define GRATH_CPP

#include <iostream>
#include <vector>
#include <list>
#include <set>


struct Graph {
    struct Edge {
        int from;
        int to;
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
        for (const auto& edge : adj) {
             edgecount += edge.size();
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

    void incident_matrix() const {
        //std::cout << count_edge();
    }
};

#endif

