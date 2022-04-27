/*
array 设计出来的其中一个目的是为了解决c数组在传参过程中退化的问题，传参时c指针会丢失他长度的信息
*/

#include <iostream>

void getSize(int* a) {
    // size 会自动判断该类型可不可以去size， 这里传递c数组会报错， 所以传统c在传参会加上长度信息
    // std::cout << "after pass, sizeof a is : " << std::size(a) << std::endl; 
    std::cout << "sizeof a is : " << sizeof(a) << std::endl;  // 返回只针对的大小
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    std::cout << "size a is :" << std::size(a) << std::endl; // 返回的是数组的长度
    std::cout << "sizeof a is :" << sizeof(a) << std::endl;  // 返回的是数组的字节数（因为此时编译器会考虑数组长度的问题）
    getSize(a); 
}