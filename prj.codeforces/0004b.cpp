#include <iostream>
#include <vector>
 
int main() {
    int days = 0, sum_time = 0, min_time = 0, max_time = 0;
    std::cin >> days >> sum_time;
    std::vector<std::pair<int, int>> vec(days, {0, 0});
 
    for (auto& [a, b] : vec) {
        std::cin >> a >> b;
        min_time += a;
        max_time += b;
    }
 
    if (sum_time < min_time || sum_time > max_time) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    std::cout << "YES" << std::endl;
    int diff = sum_time - min_time;
 
    for (int i = 0; i < days; i++) {
        if (diff + vec[i].first >= vec[i].second) {
            diff -= vec[i].second - vec[i].first;
            std::cout << vec[i].second << ' ';
        } else if (diff != 0) {
            std::cout << vec[i].first + diff << ' ';
            diff = 0;
        } else {
            std::cout << vec[i].first << ' ';
        }
    }
 
    return 0;
}
