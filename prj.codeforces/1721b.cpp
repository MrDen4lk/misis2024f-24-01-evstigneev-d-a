#include <bits/stdc++.h>

bool check_distance(std::pair<int, int> point, std::pair<int, int> lazer, int distance) {
    return ((std::abs(point.first - lazer.first) + std::abs(point.second - lazer.second)) <= distance);
}

void solve() {
    int height = 0;
    int width = 0;
    int distance = 0;
    std::pair<int, int> point_of_lazer = {0, 0};
    std::cin >> height >> width >> point_of_lazer.first >> point_of_lazer.second >> distance;

    std::cout << (check_distance({point_of_lazer.first, width}, point_of_lazer, distance) 
    && check_distance({height, point_of_lazer.second}, point_of_lazer, distance)
    || check_distance({point_of_lazer.first, 1}, point_of_lazer, distance)
    && check_distance({1, point_of_lazer.second}, point_of_lazer, distance) 
    || check_distance({point_of_lazer.first, 1}, point_of_lazer, distance)
    && check_distance({point_of_lazer.first, width}, point_of_lazer, distance) 
    || check_distance({height, point_of_lazer.second}, point_of_lazer, distance)
    && check_distance({1, point_of_lazer.second}, point_of_lazer, distance) 
    ? -1 : height + width - 2) << std::endl;
}
 
int main() {
    int times = 0;
    std::cin >> times;
    
    while (times--) {
        solve();
    }

    return 0;
}
