#include <iostream>
#include <vector>
 
int main() {
    int n = 0;
    int times = 0;
    int left = 0;
    int right = 0;

    std::cin >> n >> times;
    std::vector<int> mas(n);
    std::vector<int> cnt_mas(n, 0);
    std::vector<std::pair<int, int>> state;

    for (int& val : mas) {
        std::cin >> val;
    }

    for (int i = 0; i < times; i++) {
        std::cin >> left >> right;
        left--; right--;
        state.emplace_back(left, false);
        state.emplace_back(right, true);
    }

    std::sort(state.begin(), state.end());

    int j = 0;
    int now = 0;
    for (int i = 0; i < n; i++) {
        while (j < 2 * times && state[j].first == i && !state[j].second) {
            now++;
            j++;
        }
        cnt_mas[i] = now;
        while (j < 2 * times && state[j].first == i && state[j].second) {
            now--;
            j++;
        }
    }

    std::sort(mas.rbegin(), mas.rend());
    std::sort(cnt_mas.rbegin(), cnt_mas.rend());
    long long answer = 0ll;

    for (int i = 0; i < n; i++) {
        answer += mas[i]  * 1ll * cnt_mas[i];
    }

    std::cout << answer;

    return 0;
}
