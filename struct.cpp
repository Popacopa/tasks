#include <iostream>
#include <cmath>
#define AREA(v1, v2, v3) (obj[v1].inside(v2, v3))

struct figure {
    // Тип фигуры (0 - круг, 1 - прямоугольник)
    bool isCircle;
    // Координаты центра
    float x{}, y{};
    // Размеры
    double w{}, h{}, r{};


    // Проверка, лежит ли точка внутри фигуры
    bool inside(float x0, float y0) {
        if (isCircle) {
            // Проверка, лежит ли точка внутри круга
            const auto dx = x0 - x;
            const auto dy = y0 - y;
            return std::sqrt(dx * dx + dy * dy) < r;
        } else {
            // Проверка, лежит ли точка внутри прямоугольника
            return std::abs(x0 - x) < (w / 2) && std::abs(y0 - y) < (h / 2);
        }
    }
};

// Функция, которая проверяет, лежит ли точка внутри множества
bool func(figure obj[4], float x0, float y0) {
    return AREA(0, x0, y0) && !(AREA(1, x0, y0) || AREA(3, x0, y0)) || AREA(2, x0, y0);
}

int main() {
    float pointX, pointY;
    figure figures[4];

    // бесконечный цикл, где пользователь может вводить параметры фигур
    while (true) {
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
    

        std::cout << "Enter point coordinates: ";
        std::cin >> pointX >> pointY;
        std::cout << "\n\n";
        std::cout << (func(figures, pointX, pointY) ? "Point is inside the set" : "Point is outside the set") << std::endl;
    }
}

