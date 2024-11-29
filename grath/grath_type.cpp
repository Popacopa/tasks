#ifndef GRATH_CPP
#define GRATH_CPP

#include <iostream>
#include <vector>
#include <list>

// структура ребра графа
struct Edge {
    int from; // откуда
    int to; // куда
};

// структура графа 
struct Graph {
    std::vector<std::list<Edge>> adj; // список смежности
    int size; // количество вершин

    Graph(int n) : adj(n), size(n) {} // сигнатура графа

    // добавить ребро
    void addEdge(int from, int to) {
        adj[from].push_back({from, to}); // проброс ссылок на элементы графа
        adj[to].push_back({to, from});
    }

    void print() const {
        for (int i{}; i < size; ++i) { // вывод графа
            std::cout << i << " -> ";
            for (const auto& edge : adj[i]) {
                std::cout << edge.to << " ";
            }
            std::cout << '\n';
        }
    }
};

#endif

