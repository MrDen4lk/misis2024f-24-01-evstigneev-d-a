#include <iostream>
#include <vector>

void solve() {
    int n = 0;
    int m = 0;
    int steps_row = 1e9;
    int steps_col = 1e9;
    std::cin >> n >> m;
    std::vector<std::vector<char>> field(n, std::vector<char> (m, 'E'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> field[i][j];
            if (field[i][j] == 'R') {
                steps_row = std::min(steps_row, i);
                steps_col = std::min(steps_col, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == 'R' && i <= steps_row && j <= steps_col) {
                std::cout << "YES" << std::endl;
                return;
            }
        }
    }
    std::cout << "NO" << std::endl;
}

int main() {
    int times = 0;
    std::cin >> times;

    while (times--) {
        solve();
    }

    return 0;
}