#include <iostream>

void solve() {
    int amount = 0;
    int item = 0;
    for (int i = 0; i < 4; i++) {
        std::cin >> item;
        amount += item;
    }

    std::cout << (amount == 0 ? 0 : (amount == 4 ? 2 : 1)) << std::endl;
}

int main() {
    int times = 0;
    std::cin >> times;

    while (times--) {
        solve();
    }

    return 0;
}