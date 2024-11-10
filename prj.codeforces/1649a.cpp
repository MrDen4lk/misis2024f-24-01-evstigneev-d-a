#include <iostream>
#include <vector>

void solve() {
    int n = 0;
    int item = 0;
    int last_zero = -1;
    int first_zero = -1;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> item;
        if (item == 0) {
            first_zero = (first_zero == -1 ? i : first_zero);
            last_zero = i;
        }
    }

    std::cout << (first_zero == -1 ? 0 : last_zero - first_zero + 2) << std::endl;
}

int main() {
    int times = 0;
    std::cin >> times;

    while (times--) {
        solve();
    }

    return 0;
}