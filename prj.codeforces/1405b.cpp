#include <iostream>

void solve() {
    int n = 0;
    int item = 0;
    int64_t answer = 0;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::cin >> item;
        answer = std::max(0ll, (answer + item));
    }

    std::cout << answer << std::endl;
}

int main() {
    int times = 0;
    std::cin >> times;

    while (times--) {
        solve();
    }

    return 0;
}