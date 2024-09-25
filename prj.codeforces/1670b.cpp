#include <bits/stdc++.h>

void solve() {
    int n = 0;
    int k = 0;
    int mx_val = -1e9;
    char item = ' ';
    std::string s = "";
    std::cin >> n >> s >> k;
    std::vector<int> num(n, 0);
    std::vector<bool> check(26, false);
    for (int i = 0; i < k; i++) {
        std::cin >> item;
        check[item - 97] = true;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (check[s[i + 1] - 97]) {
            num[i] = 1;
        } else {
            num[i] = (num[i + 1] == 0 ? 0 : num[i + 1] + 1);
        }
        mx_val = std::max(mx_val, num[i]);
    }

    std::cout << mx_val << std::endl;
}

int main() {
    int times = 0;
    std::cin >> times;

    while (times--) {
        solve();
    }

    return 0;
}
