#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename T>
class MyStack {
public:
    MyStack();
    MyStack(const MyStack& obj);
    MyStack(MyStack&& obj);
    ~MyStack();


public:
    MyStack& operator=(const MyStack& obj);
    MyStack& operator=(MyStack&& obj);
    T& top();
    const T& top() const;
    bool empty() const;
    size_t size() const;
    void push(const T& val);
    void pop();

private:
    void swap(T* first,T* second); 


private:
    T* m_arr;
    size_t m_size;
    size_t m_capacity;

};


template <typename T>
void MyStack<T>::swap(T* first,T* second) {
        std::swap(first->m_arr,second->m_arr);
        std::swap(first->m_size,second->m_size);
        std::swap(first->m_capacity,second->m_capacity);
    }

template <typename T>
MyStack<T>::MyStack() : m_arr(nullptr), m_size(0), m_capacity(0) {}


template <typename T>
MyStack<T>::MyStack(const MyStack& obj) {
    m_capacity = obj.m_capacity;
    m_size = obj.m_size;
    m_arr = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = obj.m_arr[i];
    }
}


template <typename T>
MyStack<T>::MyStack(MyStack&& obj) : m_arr(nullptr),m_capacity(0),m_size(0) {
    swap(this,&obj);
}

template<typename T>
MyStack<T>::~MyStack() {
    delete[] m_arr;
}

template <typename T>
MyStack<T>& MyStack<T>::operator=(const MyStack& other) {
    if (this != &other) {
        delete[] m_arr;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_arr = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            m_arr[i] = other.m_arr[i];
        }
    }
    return *this;
}

template <typename T>
MyStack<T>& MyStack<T>::operator=(MyStack&& other) {
    if (this != &other) {
        delete[] m_arr;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_arr = other.m_arr;
        other.m_size = 0;
        other.m_capacity = 0;
        other.m_arr = nullptr;
    }
    return *this;
}


template<typename T>
T& MyStack<T>::top() {
    if ( 0 == m_size) {
        throw std::runtime_error("Empty stack");
    }
    return m_arr[m_size - 1];
}


template<typename T>
const T& MyStack<T>::top() const{
    if ( 0 == m_size) {
        throw std::runtime_error("Empty stack");
    }
    return m_arr[m_size - 1];
}


template<typename T>
bool MyStack<T>::empty() const{
    return 0 == m_size;
}

template<typename T>
size_t MyStack<T>::size() const{
    return m_size;
}

template<typename T>
void MyStack<T>::push(const T& val) {
    if (m_size + 1 >= m_capacity) {
        m_capacity *= 2;
        T* tmp = new T[m_capacity];

        for (size_t i = 0; i < m_size; ++i) {
            tmp[i] = m_arr[i];
        }

        delete[] m_arr;
        m_arr = tmp;
    }

    m_arr[m_size] = val;
    ++m_size;
}

template<typename T>
void MyStack<T>::pop() {
    if ( 0 == m_size) {
        throw std::runtime_error("Empty stack");
    }
    m_size--;
}



#endif //SATAC_H