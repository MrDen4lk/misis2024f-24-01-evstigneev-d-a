#include <iostream>

void solve() {
    int n = 0;
    char item = '.';
    std::cin >> n;
    std::pair<int, int> pos_1 = {-1, -1}, pos_2 = {-1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> item;
            if (item == '*') {
                if (pos_1.first == -1) {
                    pos_1 = {i, j};
                } else {
                    pos_2 = {i, j};
                }
            }
        }
    }

    if (pos_1.first == pos_2.first) {
        if (std::min(pos_1.first, pos_2.first) != 0) {
            pos_1.first = 0;
        } else {
            pos_1.first = n - 1;
        }
    }
    if (pos_1.second == pos_2.second) {
        if (std::min(pos_1.second, pos_2.second) != 0) {
            pos_1.second = 0;
        } else {
            pos_1.second = n - 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == pos_1.first || i == pos_2.first) && (j == pos_1.second || j == pos_2.second)) {
                std::cout << '*';
            } else {
                std::cout << '.';
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int times = 0;
    std::cin >> times;

    while (times--) {
        solve();
    }

    return 0;
}
