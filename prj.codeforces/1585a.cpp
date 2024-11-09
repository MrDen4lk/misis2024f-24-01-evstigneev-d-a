#include <iostream>

void solve() {
    int n = 0;
    int item = 0;
    int height = 1;
    bool prev = false;
    bool run = true;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> item;

        if (item == 1) {
            if (prev) {
                height += 5;
            } else {
                height++;
                prev = true;
            }
        } else {
            if (prev || i == 0) {
                prev = false;
            } else {
                run = false;
            }
        }
    }

    std::cout << (run ? height : -1) << std::endl;
}

int main() {
    int times = 0;
    std::cin >> times;

    while (times--) {
        solve();
    }

    return 0;
}