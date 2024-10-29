#include <iostream>
#include <vector>

void solve() {
    int n = 0;
    int answer = 0;
    bool run = true;
    std::cin >> n;
    std::vector<int> vec(n, 0);
    std::vector<int> statistics(101, 0);

    for (int& item : vec) {
        std::cin >> item;
        statistics[item]++;
    }

    for (int i = 0; i <= 100; i++) {
        if (statistics[i] == 0) {
            if (run) {
                std::cout << 2 * i << std::endl;
                return;
            } else {
                std::cout << answer + i << std::endl;
                return;
            }
        } else if (statistics[i] == 1 && run) {
            run = false;
            answer = i;
        }
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