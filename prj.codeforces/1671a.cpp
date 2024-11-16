#include <iostream>

void solve() {
    std::string s;
    std::cin >> s;

    if (s.size() == 1 || s[0] != s[1] || s[s.size() - 1] != s[s.size() - 2]) {
        std::cout << "NO" << std::endl;
        return;
    }
    for (size_t i = 1; i < s.size() - 1; i++) {
        if (s[i - 1] == s[i + 1] && s[i] != s[i + 1]) {
            std::cout << "NO" << std::endl;
            return;
        }
    }
    std::cout << "YES" << std::endl;
}

int main() {
    int32_t times = 0;
    std::cin >> times;

    while (times--) {
        solve();
    }

    return 0;
}