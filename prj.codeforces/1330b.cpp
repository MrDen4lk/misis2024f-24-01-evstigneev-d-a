#include <iostream>
#include <vector>
#include <set>
#include <map>
 
void solve() {
    int n = 0;
    int j = 0;
    bool run = false;
    std::pair<int, int> position_of_1 = {-1, -1};
    std::cin >> n;
    std::vector<int> vec(n, 0);
    std::map<int, int> statistics_left;
    std::map<int, int> statistics_right;
    std::set<int> checker_left{};
    std::set<int> checker_right{};
    std::set<int> errors{};
    int answer = 0;
    std::vector<int> all_answers{};
    for (int& item : vec) {
        std::cin >> item;
        if (item == 1) {
            if (position_of_1.first == -1) {
                position_of_1.first = j;
            } else if (position_of_1.second == -1) {
                position_of_1.second = j;
            } else {
                run = true;
            }
        }
        j++;
    }
 
    if (run || position_of_1.first == -1 || position_of_1.second == -1) {
        std::cout << 0 << std::endl;
        return;
    }
 
    for (int i = 0; i <= position_of_1.first; i++) {
        checker_left.insert(vec[i]);
        statistics_left[vec[i]]++;
        if (statistics_left[vec[i]] > 1) {
            std::cout << 0 << std::endl;
            return;
        }
    }
 
    for (int i = position_of_1.first + 1; i < n; i++) {
        checker_right.insert(vec[i]);
        statistics_right[vec[i]]++;
        if (statistics_right[vec[i]] > 1) {
            errors.insert(vec[i]);
        }
    }
 
    for (int& item : vec) {
        if (statistics_left[item] + statistics_right[item] > 2) {
            std::cout << 0 << std::endl;
            return;
        }
    }
 
    if (static_cast<int>(checker_left.size()) == *checker_left.rbegin() && static_cast<int>(checker_right.size()) == *checker_right.rbegin() && errors.empty()) {
        answer++;
        all_answers.push_back(position_of_1.first + 1);
    }
 
    for (int i = position_of_1.first + 1; i < position_of_1.second; i++) {
        if (statistics_right[vec[i]] > 1) {
            if (statistics_right[vec[i]] == 2) {
                errors.erase(vec[i]);
            }
        } else {
            checker_right.erase(vec[i]);
        }
        statistics_right[vec[i]]--;
        statistics_left[vec[i]]++;
        if (statistics_left[vec[i]] > 1) { break; }
        checker_left.insert(vec[i]);
        if (static_cast<int>(checker_left.size()) == *checker_left.rbegin() && static_cast<int>(checker_right.size()) == *checker_right.rbegin() && errors.empty()) {
            answer++;
            all_answers.push_back(checker_left.size());
        }
    }
 
    std::cout << answer << std::endl;
    for (int& item : all_answers) {
        std::cout << item << ' ' << n - item << std::endl;
    }
}
 
int main() {
    int times = 0;
    std::cin >> times;
 
    while (times--) {
        solve();
    }
}