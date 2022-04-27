#include <iostream>
#include <map>

typedef char key_t[8];

int main() {
    std::map<key_t, int> mp;
    key_t key{"hello"};
    mp[key] = 5;
    std::cout << mp[key] << std::endl;
}