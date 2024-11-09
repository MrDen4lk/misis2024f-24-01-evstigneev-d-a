#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n = 0;
    std::cin >> n;
    std::vector<int64_t> vec(n, 0);
    for (int64_t& item : vec) {
        std::cin >> item;
    }

    std::sort(vec.begin(), vec.end());

    std::cout << std::max(vec[0] * vec[1] * vec[2] * vec[3] * vec[n - 1], 
    std::max(vec[0] * vec[1] * vec[n - 3] * vec[n - 2] * vec[n - 1], vec[n - 5] * vec[n - 4] * vec[n - 3] * vec[n - 2] * vec[n - 1])) << std::endl;

    return;
}

int main() {
    int times = 0;
    std::cin >> times;

    while (times--) {
        solve();
    }

    return 0;
}