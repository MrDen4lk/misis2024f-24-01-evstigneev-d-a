#include <iostream>
 
void solve() {
    int first_tank = 0;
    int second_tank = 0;
    int cup = 0;
    std::cin >> first_tank >> second_tank >> cup;
    std::cout << (first_tank == second_tank ? 0 : (std::abs(second_tank - first_tank) - 1) / (2 * cup) + 1) << std::endl;
 
}
 
int main() {
    int times = 0;
    std::cin >> times;
    
    while (times--) {
        solve();
    }
 
    return 0;
}
