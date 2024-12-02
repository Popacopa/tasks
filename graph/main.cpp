#include "graph_type.hpp"
#define MARK std::cout << ">";

void input(unsigned int& size, bool** mat) {
    for (int y = 0; y < size; y++) {  
        std::cout << y + 1 << " строка:\n";
        for (int x = 0; x < size; x++) {  
            MARK;std::cin >> mat[y][x];
        }
    }
}

void buid_graph(unsigned int& size, bool** mat, Graph& graph) {
    for (int y = 0; y < size; y++) {  
        for (int x = 0; x < size; x++) {  
            if (mat[y][x]) {
                graph.addEdge(y, x);
            }
        }
    }
    graph.print();
}
int main(int argc, char const *argv[])
{
    bool check = 0;
    unsigned int size;
    std::cout << "0: запись в терминале || 1: запись из файла: "; std::cin >> check;
    if (!check) {
        std::cout << "кол-во вершин графа: ";
        std::cin >> size;
        Graph graph(size);
        bool** mat = new bool*[size];
        for (int i = 0; i < size; i++) {mat[i] = new bool[size];}
        std::cout << "матрица смежности: " << "\n";
        input(size, mat);
        std::cout << "\n";
        buid_graph(size, mat, graph);
        delete mat;
    } else {
        //just wait ¯\_(ツ)_/¯
    }
}

