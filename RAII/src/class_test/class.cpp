#include "class.h"
namespace cyb {
    template<typename T>
    A<T>::A(T x) : a(x) {
        std::cout << "use ctor" << std::endl;
    }
}