#include <iostream>
#include <array>

// arr 里面的5就代表数组的长度，这会作为它的属性，不因为传参而改变
void getSize(std::array<int, 5>& arr) {
    std::cout << "size arr is : " << size(arr) << std::endl;
    std::cout << "sizeof arr is : " << sizeof(arr) << std::endl;
}

int main() {
    std::array<int, 5> arr{1, 2, 3, 4, 5};
    std::cout << "size arr is : " << size(arr) << std::endl;
    std::cout << "sizeof arr is : " << sizeof(arr) << std::endl;
    getSize(arr);
}