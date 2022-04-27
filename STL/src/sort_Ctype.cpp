#include <iostream>
#include <algorithm>

int main() {
    int a[] = {5, 4, 3, 2, 1};
    std::sort(a, a + 5);
    for(int i = 0; i < 5; i++) {
        std::cout << a[i] << " ";
    }
}