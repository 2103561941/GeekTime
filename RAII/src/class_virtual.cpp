/*
使用RAII巧妙解决多态忘记释放内存的问题
*/

#include <iostream>

using namespace std;

template<typename T>
class Raii{
public:
    Raii(T* _ptr = nullptr) {
        ptr = _ptr;
        cout << "use ctor" << endl;
    }
    ~Raii() {
        delete ptr;
        cout << "use dtor" << endl;
    }

private:
    T* ptr;
};

int* 
 

int main() {




}