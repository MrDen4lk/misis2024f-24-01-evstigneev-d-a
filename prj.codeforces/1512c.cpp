#include <bits/stdc++.h>

void solve() {
    int amount_0 = 0;
    int amount_1 = 0;
    std::string s = "";
    std::cin >> amount_0 >> amount_1 >> s;
    std::vector<char> str(amount_0 + amount_1, ' ');
    int amount_gl = amount_0 + amount_1;
    for (int i = 0; i < amount_gl; i++) {
        str[i] = s[i];
        if (str[i] == '0') {
            amount_0--;
        } else if (str[i] == '1') {
            amount_1--;
        }
    }

    for (int i = 0; i < amount_gl / 2; i++) {
        if (str[i] != str[amount_gl - i - 1]) {
            if ((str[i] == '0' && str[amount_gl - i - 1] == '1') || (str[i] == '1' && str[amount_gl - i - 1] == '0')) {
                std::cout << -1 << std::endl;
                return;
            }
            if (str[i] == '?') {
                if ((str[amount_gl - i - 1] == '0' ? amount_0 : amount_1) != 0) {
                    (str[amount_gl - i - 1] == '0' ? amount_0 : amount_1)--;
                    str[i] = str[amount_gl - i - 1];
                } else {
                    std::cout << -1 << std::endl;
                    return;
                }
            } else {
                if ((str[i] == '0' ? amount_0 : amount_1) != 0) {
                    (str[i] == '0' ? amount_0 : amount_1)--;
                    str[amount_gl - i - 1] = str[i];
                } else {
                    std::cout << -1 << std::endl;
                    return;
                }
            }
        }
    }

    for (int i = 0; i < amount_gl / 2; i++) {
        if (str[i] == str[amount_gl - i - 1] && str[i] == '?') {
            if (amount_0 >= 2) {
                amount_0 -= 2;
                str[i] = '0';
                str[amount_gl - i - 1] = '0';
            } else if (amount_1 >= 2) {
                amount_1 -= 2;
                str[i] = '1';
                str[amount_gl - i - 1] = '1';
            } else {
                std::cout << -1 << std::endl;
                return;
            }
        }
    }
    if (amount_gl % 2 == 1 && str[amount_gl / 2] == '?') {
        if (amount_0 != 0) {
            str[amount_gl / 2] = '0';
            amount_0--;
        } else {
            str[amount_gl / 2] = '1';
            amount_1--;
        }
    }

    if (amount_0 < 0 || amount_1 < 0) {
        std::cout << -1 << std::endl;
        return;
    }

    for (const char& val : str) {
        std::cout << val;
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
