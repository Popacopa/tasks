#include <iostream>
#include <fstream>

int main()
{
    std::ofstream data("data.txt");
    if (!data.is_open()) {
        std::cerr << "Не удалось открыть файл для записи!" << std::endl;
        return 1;
    }
    std::string line1 = "string\n";
    data << line1 << "\n";
    
    
    return 0;
}
