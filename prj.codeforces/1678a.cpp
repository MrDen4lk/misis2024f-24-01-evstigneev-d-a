#include <iostream>
#include <vector>

void solve() {
    int n = 0;
    int amount_of_zeros = 0;
    bool twice = false;
    std::cin >> n;
    std::vector<int> vec(n);
    std::vector<bool> amount(101, false);
    for (int& item : vec) {
        std::cin >> item;
        amount_of_zeros += (item == 0 ? 1 : 0);
        if (!amount[item]) {
            amount[item] = true;
        } else {
            twice = true;
        }
    }

    if (amount_of_zeros != 0) {
        std::cout << n - amount_of_zeros << std::endl;
    } else if (twice) {
        std::cout << n << std::endl;
    } else {
        std::cout << n + 1 << std::endl;
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