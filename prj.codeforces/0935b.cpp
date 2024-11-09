#include <iostream>

int main() {
    int n = 0;
    int cost = 0;
    bool state = false;
    bool prev = true;
    std::pair<int, int> point{0, 0};
    std::string way = "";
    std::cin >> n >> way;

    for (int i = 0; i < n; i++) {
        if (way[i] == 'R') {
            point.first++;
        } else {
            point.second++;
        }

        if (state && ((prev && (point.first < point.second)) || (!prev && (point.first > point.second)))) { cost++; }
        if (point.first == point.second) {
            state = true;
        } else {
            prev = (point.first >= point.second ? true : false);
        }
    }

    std::cout << cost << std::endl;

    return 0;
}