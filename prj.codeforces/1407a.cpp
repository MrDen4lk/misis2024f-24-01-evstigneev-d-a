#include <iostream>
#include <vector>

void solve() {
    int n = 0;
    int item = 0;
    int amount_0 = 0;
    int amount_1 = 0;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> item;
        if (item == 1) {
            amount_1++;
        } else {
            amount_0++;
        }
    }

    if (amount_0 < amount_1) {
        amount_1 -= amount_1 % 2;
        std::cout << amount_1 << std::endl;
        for (int i = 0; i < amount_1; i++) {
            std::cout << 1 << ' ';
        }
        std::cout << std::endl;
    } else {
        std::cout << amount_0 << std::endl;
        for (int i = 0; i < amount_0; i++) {
            std::cout << 0 << ' ';
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