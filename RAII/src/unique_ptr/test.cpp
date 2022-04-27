#include "unique_ptr.hpp"
// #include <memory>
struct Foo {
    Foo(int a, int b) : x(a), y(b) {}
    int x;
    int y;
};


void test01() {
// 测试BIG 3 的功能 
    cyb::unique_ptr<int> pi(new int(10)); 
    cyb::unique_ptr<int> pi1(std::move(pi));
    cyb::unique_ptr<int> pi2(new int(20));
    pi2 = std::move(pi1);
}

void test02() {
    cyb::unique_ptr<Foo> pf(new Foo(10, 20));
    std::cout << "pf->x = " << pf->x << std::endl;
    std::cout << "(*pf).y = " << (*pf).y  << std::endl;
    if (pf) std::cout << "pf == true" << std::endl; 
}

void test03() {
    cyb::unique_ptr<int> pi_a(new int(10));
    cyb::unique_ptr<int> pi_b(new int(20));
    printf("before swap, pi_a = %d, pi_b = %d\n", *pi_a, *pi_b);
    cyb::swap(pi_a, pi_b);
    printf("after swap, pi_a = %d, pi_b = %d\n", *pi_a, *pi_b);
    pi_a.swap(pi_b);
    printf("after another swap, pi_a = %d, pi_b = %d\n", *pi_a, *pi_b);
}

void test04() {
    cyb::unique_ptr<int> pi(new int(10));
    printf("before reset, %lld, *pi = %d\n", pi.get(), *pi);
    pi.reset((new int(20)));
    printf("after reset, %lld, *pi = %d\n", pi.get(), *pi);

    int* p = pi.release();
    if (pi.get() == nullptr) {
        printf("pi.release successfully, *p == %d\n", *p);
    }

}

int main() {
    
    // test01();
    // test02();
    // test03();
    test04();

}