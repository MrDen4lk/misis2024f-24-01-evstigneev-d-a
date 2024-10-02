#include <bits/stdc++.h>

void solve() {
    int answer = 0;
    std::string s = "";
    std::vector<std::string> vec(10);

    for (int i = 0; i < 10; i++) {
        std::cin >> vec[i];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (vec[i][j] == 'X') {
                answer += std::min((j > 4 ? 9 - j : j) + 1, (i > 4 ? 9 - i : i) + 1);
            }
        }
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
