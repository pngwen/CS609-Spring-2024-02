# include <iostream>
#include <iostream>

int main() {
    int height;
    std::cout << "Enter the height of the triangle: ";
    std::cin >> height;

    // Draw the triangle
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < height - i - 1; ++j) {
            std::cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}