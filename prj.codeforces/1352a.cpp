#include <bits/stdc++.h>
 
void solve() {
    int n, k =  0;
    std::cin >> n;
    int a = n / 1000, 
    b = n % 1000 / 100,
    c = n % 100 / 10,
    d = n % 10;
    
    if (a != 0) k++;
    if (b != 0) k++;
    if (c != 0) k++;
    if (d != 0) k++;
 
    std::cout << k << '\n';
 
    if (a != 0) std::cout << a * 1000 << ' ';
    if (b != 0) std::cout << b * 100 << ' ';
    if (c != 0) std::cout << c * 10 << ' ';
    if (d != 0) std::cout << d;
    std::cout << '\n';
 
}
 
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
