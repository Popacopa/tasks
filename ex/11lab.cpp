#include <iostream>
#include <fstream>

int main()
{
    std::ifstream infile;
    std::ofstream ofile_g, ofile_h;
    infile.open("./tmp/f.txt");
    ofile_g.open("./tmp/g.txt");
    ofile_h.open("./tmp/h.txt");
    std::string l;
    while (std::getline(infile, l)) {
        l.length() == 2 ? ofile_g << l << "\n" : ofile_h << l << "\n";
    }
    ofile_g.close();
    ofile_h.close();
    infile.close();
    return 0;
}
