#include <bits/stdc++.h>
 
int main() {
    int a;
    std::pair<int, int> pos;
 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> a;
            if (a == 1) {
                pos = {i, j};
            }
        }
    }
 
    std::cout << std::abs(2 - pos.first) + std::abs(2 - pos.second);
 
    return 0;
}
