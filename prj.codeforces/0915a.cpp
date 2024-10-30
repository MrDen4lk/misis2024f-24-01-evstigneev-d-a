#include <iostream>

int main() {
    int n = 0;
    int k = 0;
    int answer = 1e9;
    int item = 0;
    std::cin >> n >> k;

    for (int i = 0; i < n; i++) {
        std::cin >> item;
        if (k % item == 0) {
            answer = std::min(answer, k / item);
        }
    }

    std::cout << answer << std::endl;

    return 0;
}