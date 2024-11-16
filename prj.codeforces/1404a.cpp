#include <iostream>
#include <vector>

void solve() {
    int n = 0;
    int k = 0;
    std::string s = "";
    std::cin >> n >> k >> s;
    std::vector<char> check(k, '?');
 
    for (int i = 0; i < n; i++) {
        if (check[i % k] == '?' && s[i] != '?') {
            check[i % k] = s[i];
        } else if (check[i % k] != '?' && s[i] != '?' && s[i] != check[i % k]) {
            std::cout << "NO" << std::endl;
            return;
        }
    }
 
    int cnt_0 = 0;
    int cnt_1 = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == '0' || check[i % k] == '0') {
            cnt_0++;
        } else if (s[i] == '1' || check[i % k] == '1') {
            cnt_1++;
        }
    }
 
    if (cnt_0 > k / 2 || cnt_1 > k / 2) {
        std::cout << "NO" << std::endl;
        return;
    }
 
    std::cout << "YES" << std::endl;
}
 
int main() {
    int times = 0;
    std::cin >> times;
 
    while (times--) {
        solve();
    }
 
    return 0;
}
