#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;
    int item = 0;
    std::vector<int> answer(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> item;
        answer[item - 1] = i + 1;
    }

    for (int& elem : answer) {
        std::cout << elem << ' ';
    }

    return 0;
}