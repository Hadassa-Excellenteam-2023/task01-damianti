//
// Created by Damian Tissembaum on 19/03/2023.
//

#ifndef UNTITLED_VECTOR_H
#define UNTITLED_VECTOR_H
#include <cstdlib>
#include <iostream>
#include <stdexcept>


class Vector {
public:
    explicit Vector(size_t size = 0, int value = 0);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector();
    Vector& operator=(const Vector& other);
    bool operator==(const Vector& other) const;

    int& operator[](const size_t& index);
    const int& operator[](size_t index) const ;
    int* data();
    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    void clear();
    void resize(size_t newCapacity, int value = 0);
    void push_back(int value);
    void pop_back();
    void insert (size_t index, int value);
    void erase (size_t index);

protected:

    size_t m_capacity;
    size_t m_size;
    int* m_data = nullptr;

private:
    void swap(Vector& other);
};


bool operator<(const Vector& l, const Vector& r);
bool operator>(const Vector& l, const Vector& r);

bool operator!=(const Vector& l, const Vector& r);
bool operator<=(const Vector& l, const Vector& r);
bool operator>=(const Vector& l, const Vector& r);

#endif //UNTITLED_VECTOR_H
