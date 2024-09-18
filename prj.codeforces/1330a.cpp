#include <bits/stdc++.h>

void solve() {
    int number_of_elements = 0;
    int number_of_add = 0;
    std::vector<bool> static_mas(103, false);

    std::cin >> number_of_elements >> number_of_add;
    std::vector<int> places(number_of_elements);
    for (int& value : places) {
        std::cin >> value;
        static_mas[value] = true;
    }

    for (int i = 1; i <= 100; i++) {
        if (number_of_add == 0 && !static_mas[i]) {
            std::cout << i - 1 << std::endl;
            return;
        }
        if (!static_mas[i]) {
            number_of_add--;
        }
    }

    std::cout << 100 + number_of_add << std::endl;

}
 
int main() {
    int times = 0;
    std::cin >> times;
    
    while (times--) {
        solve();
    }

    return 0;
}
