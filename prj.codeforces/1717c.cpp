#include <iostream>
#include <vector>

void solve() {
    int amount = 0;
    std::cin >> amount;
    std::vector<int> vec_old(amount, 0);
    std::vector<int> vec_new(amount, 0);
    for (int& item : vec_old) {
        std::cin >> item;
    }
    for (int& item : vec_new) {
        std::cin >> item;
    }

    for (int i = 0; i < amount; i++) {
        if (vec_old[i] > vec_new[i] || ((vec_new[i] > vec_new[(i + 1) % amount] + 1) && vec_new[i] != vec_old[i])) {
            std::cout << "no" << std::endl;
            return;
        }
    }
    std::cout << "yes" << std::endl;
}
 
int main() {
    int times = 0;
    std::cin >> times;
    
    while (times--) {
        solve();
    }

    return 0;
}
