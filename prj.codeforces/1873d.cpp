#include <bits/stdc++.h>

void solve() {
    int n = 0;
    int k = 0;
    int answer = 0;
    std:: string s = "";
    std::cin >> n >> k >> s;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            answer++;
            i += k - 1;
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
