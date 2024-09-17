#include <bits/stdc++.h>
 
int main() {
    int y, i;
    bool run = true;
    std::set<int> check;
    std::cin >> y;
    i = y + 1;
 
    while (run) {
        check.insert(i / 1000);
        check.insert(i % 1000 / 100);
        check.insert(i % 100 / 10);
        check.insert(i % 10);
        if (check.size() == 4) {
            run = false;
            std::cout << i;
        }
        i++;
        check.clear();
    }
 
    return 0;
}
