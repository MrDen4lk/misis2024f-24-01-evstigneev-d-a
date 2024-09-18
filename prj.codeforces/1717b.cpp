#include <bits/stdc++.h>

void solve() {
    int height = 0;
    int k_size = 0;
    std::pair<int, int> must_point;
    std::cin >> height >> k_size >> must_point.first >> must_point.second;

    int must_color = (must_point.second % k_size + must_point.first - 1) % k_size;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height; j++) {
            if (((i + 1) % k_size + j) % k_size == must_color) {
                std::cout << 'X';
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
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
