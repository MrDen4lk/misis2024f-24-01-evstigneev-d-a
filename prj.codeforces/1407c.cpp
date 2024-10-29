#include <iostream>
#include <vector>

int main() {
    int n = 0;
    int a = 0;
    int b = 0;
    int j = 0;
    std::cin >> n;
    std::vector<int> vec(n, -1);

    for (int i = 1; i < n; i++) {
        std::cout << "? " << j + 1 << ' ' << i + 1 << std::endl;
        std::cin >> a;
        std::cout << "? " << i + 1 << ' ' << j + 1 << std::endl;
        std::cin >> b;

        if (a > b) {
            vec[j] = a;
            j = i;
        } else {
            vec[i] = b;
        }
    }
    vec[j] = n;

    std::cout << "! ";
    for (int& item : vec) {
        std::cout << item << ' ';
    }

    return 0;
}