#include <iostream>
#include <vector>

void solve() {
    int n = 0;
    int answer = 0;
    std::cin >> n;
    std::vector<std::pair<int, int>> time(n,{0, 0});
    std::vector<int> late(n, 0);
    for (auto& [time_in, time_out] : time) {
        std::cin >> time_in >> time_out;
    }
    for (int& item : late) {
        std::cin >> item;
    }

    answer = time[0].first + late[0];
    for (int i = 0; i < n - 1; i++) {
        answer = std::max(time[i].second, answer + (time[i].second - time[i].first + 1) / 2);
        answer += time[i + 1].first - time[i].second + late[i + 1];
    }

    std::cout << answer << std::endl;
}

int main() {
    int times = 0;
    std::cin >> times;

    while (times--) {
        solve();
    }

    return 0;
}