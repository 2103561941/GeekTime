#include <iostream>
#include <array>
#include <map>

typedef std::array<char, 8> key_t;

int main() {
    std::map<key_t, int> mp;
    key_t key{"hello"};
    mp[key] = 5;
    std::cout << mp[key] << std::endl;
}

