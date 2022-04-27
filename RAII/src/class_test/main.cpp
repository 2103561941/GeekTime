#include <iostream>
#include "class.h"

// 这三个文件是错的，是我拿来找bug的，类模板不能用头文件声明，要放到一个cpp 或者 hpp文件里

int main() {
    cyb::A<int> a(10);
}