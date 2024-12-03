#include "graph_type.hpp"
#include <vector>
#include <fstream>
#include <sstream>

Graph* graph = nullptr;
bool** mat = nullptr;

void input(unsigned int& size, bool** mat) {
    for (int y = 0; y < size; y++) {  
        std::cout << y + 1 << " строка:\n";
        for (int x = 0; x < size; x++) {
            std::cout << ">"; std::cin >> mat[y][x];
        }
    }
}

void buid_graph(unsigned int& size, bool** mat, Graph* graph) {
    for (int y = 0; y < size; y++) {  
        for (int x = 0; x < size; x++) { 
            if (mat[y][x]) {
                graph->addEdge(y, x);
            }
        }
    }
    delete mat;
    graph->print();
}

void init(unsigned int& size) {
    graph = new Graph(size);
    mat = new bool*[size];
    for (int i = 0; i < size; i++) {mat[i] = new bool[size];}
}

int main(int argc, char const *argv[])
{
    bool check = 0;
    unsigned int size;
    std::cout << "0: запись в терминале || 1: запись из файла: "; std::cin >> check;
    if (!check) {
        std::cout << "кол-во вершин графа: "; std::cin >> size;
        init(size);
        std::cout << "матрица смежности: " << "\n";
        input(size, mat);
        std::cout << "\n";
        buid_graph(size, mat, graph);
    } else {

        std::ifstream file;
        file.open("table.txt");
        std::string l;
        std::getline(file, l);
        std::stringstream ss(l);
        ss >> size;
        init(size);
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                file >> mat[y][x];
            }
        }
        buid_graph(size, mat, graph);
        file.close();
    }
}

