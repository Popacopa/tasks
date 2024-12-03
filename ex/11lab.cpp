#include <iostream>
#include <fstream>
int main(int argc, char const *argv[])
{
    std::ifstream infile;
    std::ofstream ofile_h;
    std::ofstream ofile_g;
    infile.open("./tmp/f.txt");
    ofile_g.open("./tmp/g.txt");
    ofile_h.open("./tmp/h.txt");
    std::string l;
    while (std::getline(infile, l)) {
        if (l.length() == 2) {
            ofile_g << l << "\n";
        }
        if (l.length() == 1) {
            ofile_h << l << "\n";
        }
    }
    ofile_g.close();
    ofile_h.close();
    infile.close();
    return 0;
}
