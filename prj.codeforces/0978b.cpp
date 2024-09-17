#include <bits/stdc++.h>
 
void solve() {
    int n = 0;
    int i = 0;
    int j = 0;
    int answer = 0;
    std::string s = "";
    std::cin >> n >> s;
 
    while (i < n) {
        if (s[i] != 'x') {
            i++;
            continue;
        }
        j = i;
        while (i < n && s[i] == 'x') {
            i++;
        }
        answer += std::max(0, i - j - 2);
        i++;
    }
 
    std::cout << answer;
}
 
int main() {
    
    solve();
 
    return 0;
}
