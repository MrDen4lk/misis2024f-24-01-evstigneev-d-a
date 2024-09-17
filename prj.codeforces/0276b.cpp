#include <bits/stdc++.h>
 
int main() {
    std::string str = "";
    int k = 0;
    std::cin >> str;
    std::vector<int> cnt(1000, 0);
 
    for (auto& i : str) {
        cnt[i]++;
    }
    for (auto& i : str) {
        k += (1 ? cnt[i] % 2 == 1 : 0);
    }
 
    if (k <= 1 || k % 2 == 1) {
        std::cout << "First";
    } else {
        std::cout << "Second";
    }
 
    return 0;
}
