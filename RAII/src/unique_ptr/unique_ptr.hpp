#pragma once 
#include <iostream>
#include <algorithm>

namespace cyb {
    template<typename T>
    class unique_ptr {
    public:
        explicit unique_ptr( T* _ptr = nullptr );
        ~unique_ptr();
        unique_ptr(unique_ptr&& ) noexcept;
        unique_ptr& operator = (unique_ptr);
    public:
        T* get();
        T& operator *();
        T* operator ->(); 
        operator bool();
        void swap(unique_ptr& _ptr);  
        T* release();
        void reset(T* _ptr = nullptr) noexcept;
    private:
        T* ptr;
    };
    
    template<typename T>
    void swap(unique_ptr<T>& p1, unique_ptr<T>& p2);

}


// unique_ptr 
namespace cyb {

    // 下面是BIG 3 根据实际需求，没有实现拷贝构造函数
    template<typename T>
    unique_ptr<T>::unique_ptr( T* _ptr ) : ptr(_ptr) {
        // std::cout << "unique_ptr( T* _ptr )" << std::endl;
    }

    template<typename T>
    unique_ptr<T>::~unique_ptr() {
        // std::cout << "~unique_ptr() " << std::endl;
        delete ptr;
    }

    template<typename T>
    unique_ptr<T>::unique_ptr(unique_ptr<T>&& rhs) noexcept {
        // std::cout << "unique_ptr(unique_ptr<T>&& rhs)" << std::endl;
        ptr = rhs.release();
    }

    template<typename T>
    unique_ptr<T>& unique_ptr<T>::operator = (unique_ptr<T> rhs) {
        // std::cout << "unique_ptr<T>::operator = (unique_ptr<T> rhs)" << std::endl;
        this->swap(rhs);
        return *this;
    }

    // 以下四个函数是对指针功能的实现， []操作符需要考虑是不是数组指针，我比较菜，就没去实现
    template<typename T>
    T* unique_ptr<T>::get() {
        return ptr;
    }

    template<typename T>
    T& unique_ptr<T>::operator *() {
        return *ptr;
    }

    template<typename T>
    T* unique_ptr<T>::operator ->() {
        return ptr;
    }

    template<typename T>
    unique_ptr<T>::operator bool() {
        return ptr;
    }

    // 交换两个智能指针的指向 成员函数版
    template<typename T>
    void unique_ptr<T>::swap(unique_ptr<T>& rhs) {
        using std::swap;
        swap(ptr, rhs.ptr);
    }  

    // 交换两个智能指针的指向 非成员函数版
    template<typename T>
    void swap(unique_ptr<T>& p1, unique_ptr<T>& p2) {
        p1.swap(p2);
    }

    // 释放unique_ptr指向对象
    template<typename T>
    T* unique_ptr<T>::release() {
        T* _ptr = ptr;
        ptr = nullptr;
        return _ptr;
    }

    // 重设unique_ptr指向对象
    template<typename T> 
    void unique_ptr<T>::reset(T* _ptr) noexcept {
        unique_ptr<T>(_ptr).swap(*this);
    }
}
