#include <iostream>

void solve() {
    int n = 0;
    int m = 0;
    int now = 1;
    int house = 0;
    long long cost = 0ll;
    std::cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        std::cin >> house;
        if (house >= now) {
            cost += house - now;
        } else {
            cost += n - now + house;
        }
        now = house;
    }

    std::cout << cost;
}

int main() {
    int times = 1;
    //std::cin >> times;

    while (times--) {
        solve();
    }

    return 0;
}
