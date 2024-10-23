#include <iostream>
#include <vector>
 
void solve() {
    int number = 0;
    std::vector<int> statistic_array(1001, false);
 
    std::cin >> number;
    std::vector<int> nums(number, 0);
    int final_number = number;
 
    for (auto& item : nums) {
        std::cin >> item;
        statistic_array[item]++;
        if (statistic_array[item] > 1) {
            final_number--;
        }
    }
 
    std::cout << final_number << std::endl;
    for (const auto& item : nums) {
        if (statistic_array[item] > 1) {
            statistic_array[item]--;
        } else {
            std::cout << item << ' ';
        }
    }
 }
 
int main() {
    
    solve();
 
    return 0;
}
