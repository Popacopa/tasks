#include <iostream>
#include <cmath>
#define AREA(v1, v2, v3) (obj[v1].inside(v2, v3))

struct figure {
    bool isCircle;
    float x{}, y{};
    double w{}, h{}, r{};

    bool inside(float x0, float y0) {
        if (isCircle) {
            const auto dx = x0 - x;
            const auto dy = y0 - y;
            return std::sqrt(dx * dx + dy * dy) < r;
        } else {
            return std::abs(x0 - x) < (w / 2) && std::abs(y0 - y) < (h / 2);
        }
    }
};

bool func(figure[4], float, float);

int main() {
    int check{};
    bool enter1 = 0;
    bool enter2 = 0;
    float pointX, pointY;
    figure figures[4];

    while(true) {
        std::cout << "(1: figure | 2: point) :";std::cin >> check;
        if (check == 1) {
            enter1 = 1;
            for (int i = 0; i < 4; ++i) {
                std::cout << "Enter figure " << char(i + 'A') << " parameters:\n";
                std::cout << "Is circle (0/1): ";
                std::cin >> figures[i].isCircle;
                std::cout << "Enter coordinates: ";
                std::cin >> figures[i].x >> figures[i].y;
                if (figures[i].isCircle) {
                    std::cout << "Enter radius: ";
                    std::cin >> figures[i].r;
                } else {
                    std::cout << "Enter size (width, height): ";
                    std::cin >> figures[i].w >> figures[i].h;
                }
            } 
        }
        if (check == 2) {
            enter2 = 1;
            std::cout << "Enter point coordinates: ";
            std::cin >> pointX >> pointY;
            std::cout << "\n\n";
        }
        if (enter1 && enter2) {std::cout << (func(figures, pointX, pointY) ? "Point is inside the set" : "Point is outside the set") << std::endl;}
    }
}

bool func(figure obj[4], float x0, float y0) {
    return AREA(0, x0, y0) && !(AREA(1, x0, y0) || AREA(3, x0, y0)) || AREA(2, x0, y0);
}