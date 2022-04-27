# 为什么要设计出array，使用C数组不香吗
下面我给出几个例子来反驳这个论题。
### 1. C数组在传参过程中会发生数组退化，即数组的长度信息被隐藏了。


```cpp
#include <iostream>

void getSize(int a[]) {
    // size 会自动判断该类型可不可以去size， 这里传递c数组会报错， 所以传统c在传参会加上长度信息
    // std::cout << "after pass, sizeof a is : " << std::size(a) << std::endl; 
    std::cout << "sizeof a is : " << sizeof(a) << std::endl;  // 返回只针对的大小
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    // 返回的是数组的长度
    std::cout << "size a is :" << std::size(a) << std::endl; 
    // 返回的是数组的字节数（因为此时编译器会考虑数组长度的问题）
    std::cout << "sizeof a is :" << sizeof(a) << std::endl;  
    getSize(a); 
}
```

输出结果：![image-20220425235101371](../../../../typora_picure/image-20220425235101371.png)

```cpp
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
```



![image-20220426001615111](../../../../typora_picure/image-20220426001615111.png)

###  2. C数组没有很好的复制功能，它无法成为map等关联容器的key

```cpp
#include <iostream>
#include <unordered_map>

typedef char key_t[8];

int main() {
    std::unordered_map<key_t, int> mp;
    key_t key{"hello"};
    mp[key] = 5;
    std::cout << mp[key] << std::endl;
}
```

直接使用Ctype的数组，会报很长一段错（这也跟map里面的实现有关）。这里就要使用array。



```cpp
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

```

但是两个都无法作为unordered_map 的key，因为两种stl的实现方法不同， 要想array使用unordered_map，我们需要为其在std的命名空间实现hash仿函数的特例，用来获取hash值。但是对于普通用户来说，写出一个很烂的hash往往会达到o(n)的时间复杂度，数据冲突很大，或者数据很分散导致内存占用大，所以这里使用map o(logn)往往是更好的选择。

### 3. 标准库的array提供了迭代器itor，而迭代器是stl与算法之间的桥梁，这使得数组可以更规范使用c++提供的标准算法，而Ctype的数组需要使用地址来使用。

但是要记得标准库设计出来的迭代器不完全是一个指针，它还需要配合萃取机完成算法对于该对象的各种提问，这里可以参考侯捷老师的c++stl与泛型编程。
