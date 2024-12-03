#include "graph_type.hpp"
#include <vector>
#include <fstream>

Graph* graph = nullptr;
std::vector<std::vector<bool>> mat;

void input(unsigned int& size, std::vector<std::vector<bool>>& mat) {
    for (int y = 0; y < size; y++) {  
        std::cout << y + 1 << " строка:\n";
        for (int x = 0; x < size; x++) {
            bool cache;  
            std::cout << ">"; std::cin >> cache;
            mat[y][x] = cache;
        }
    }
}

void buid_graph(unsigned int& size, std::vector<std::vector<bool>> mat, Graph* graph) {
    for (int y = 0; y < size; y++) {  
        for (int x = 0; x < size; x++) { 
            //std::cout <<  mat[y][x] << (x + 1 == size ? "\n" : "");
            if (mat[y][x]) {
                graph->addEdge(y, x);
            }
        }
    }
    graph->print();
}
void init(unsigned int& size) {
    graph = new Graph(size);
    std::vector<bool> temp;
    for (int i{}; i < size; i++) {temp.push_back(0);}
    for (int i{}; i < size; i++) {mat.push_back(temp);}
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
        while (std::getline(file, l)) {std::cout << l << "\n";}
        file.close();
    }
}

