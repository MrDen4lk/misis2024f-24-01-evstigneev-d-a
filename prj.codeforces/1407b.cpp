#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void solve() {
    int n = 0;
    std::cin >> n;
    std::vector<int> vec(n, 0);
    std::vector<bool> used(n, false);
    for (int& item : vec) {
        std::cin >> item;
    }

    int prev = *max_element(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        if (vec[i] == prev) {
            used[i] = true;
            break;
        }
    }

    std::cout << prev << ' ';
    for (int j = 0; j < n - 1; j++) {
        int answer = -1;
        std::pair<int, int> elem{-1, -1};
        for (int i = 0; i < n; i++) {
            if (used[i]) { continue; }
            if (answer < std::gcd(prev, vec[i])) {
                answer = std::gcd(prev, vec[i]);
                elem = {vec[i], i};
            }
        }
        std::cout << elem.first << ' ';
        used[elem.second] = true;
        prev = answer;
    }
    std::cout << std::endl;
}

int main() {
    int times = 0;
    std::cin >> times;

    while (times--) {
        solve();
    }

    return 0;
}