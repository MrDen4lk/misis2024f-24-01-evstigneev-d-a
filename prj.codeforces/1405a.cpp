#include <iostream>
#include <vector>
 
void solve() {
    int n = 0;
    std::cin >> n;
    std::vector<int> vec(n, 0);
    for (int& item : vec) {
        std::cin >> item;
    }
    
    for (int i = n - 1; i >= 0; i--) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
}
 
int main() {
    int times = 0;
    std::cin >> times;
 
    while (times--) {
        solve();
    }
}