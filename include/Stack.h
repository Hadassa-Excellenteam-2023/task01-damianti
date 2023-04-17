//
// Created by Damian Tissembaum on 20/03/2023.
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H


#include <cstdlib>
#include "Vector.h"

class Stack {
public:
    // constructors and copy assignment operator
    explicit Stack(size_t size = 0, int value = 0);
    Stack(const Stack& other);
    Stack(Stack&& other) noexcept;
    Stack& operator=(const Stack &other);
    Stack& operator+=(int number);
    Stack& operator-=(int number);
    Stack& operator+=(const Stack& other);
    Stack& operator*=(int number);
    Stack& operator/=(int number);
    Stack operator+(const Stack& other);

    // member functions
    bool isEmpty() const;
    void push(const int value);
    void pop();
    int top() const;  // returns the top element without removing it
    size_t size() const;


private:
    Vector m_vector;
};


bool operator<(const Stack& l, const Stack& r);
bool operator>(const Stack& l, const Stack& r);

#endif //UNTITLED_STACK_H
