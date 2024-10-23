#include <iostream>
 
int main() {
    int n = 0;
    int k = 0;
    int a = 0;
    int b = 0;
    int mx = -1e9;
    std::cin >> n >> k;
 
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b;
        mx = std::max(mx, (b <= k ? a : a - (b - k)));
    }
    std::cout << mx;
 
    return 0;
}
