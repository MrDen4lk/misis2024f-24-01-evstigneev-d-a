#include <iostream>
#include <vector>

void solve() {
    std::vector<std::vector<char>> field(8, std::vector<char> (8, '.'));
    for (std::vector<char>& item : field) {
        for (char& elem : item) {
            std::cin >> elem;
        }
    }

    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            if (field[i][j] == '#' && field[i - 1][j - 1] == '#' && field[i + 1][j + 1] == '#' && field[i - 1][j + 1] == '#' && field[i + 1][j - 1] == '#') {
                std::cout << i + 1 << ' ' << j + 1 << std::endl;
                return;
            }
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