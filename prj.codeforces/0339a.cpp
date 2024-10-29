#include <iostream>
 
int main() {
    std::string s = "";
    std::cin >> s;
    int amount_1 = 0;
    int amount_2 = 0;
    int amount_3 = 0;
 
    for (char& item : s) {
        if (item == '1') {
            amount_1++;
        } else if (item == '2') {
            amount_2++;
        } else if (item == '3') {
            amount_3++;
        }
    }
 
    if (amount_1 != 0) {
        std::cout << '1';
    }
    for (int i = 1; i < amount_1; i++) {
        std::cout << "+1";
    }
    if (amount_2 != 0) {
        if (amount_1 != 0) {
            std::cout << "+2";
        } else {
            std::cout << "2";
        }   
    }
    for (int i = 1; i < amount_2; i++) {
        std::cout << "+2";
    }
    if (amount_3 != 0) {
        if (amount_1 != 0 || amount_2 != 0) {
            std::cout << "+3";
        } else {
            std::cout << "3";
        }
    }
    for (int i = 1; i < amount_3; i++) {
        std::cout << "+3";
    }
    
    std::cout << std::endl;
 
    return 0;
}