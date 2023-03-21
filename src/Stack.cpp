/**

@file Stack.h
@brief This file contains the implementation of a stack class based on a vector.
*/
#pragma once
#include "../include/Stack.h"


/* =================Constructors=================*/
/*
@brief Constructs a new Stack object with a given size and value.
@param size The size of the new stack.
@param value The initial value to be set for all elements in the stack.
*/
Stack::Stack(size_t size, int value)
: m_vector(size, value){
}
/**
@brief Constructs a new Stack object by copying another stack.
@param other The stack to be copied.
*/
Stack::Stack(const Stack &other)
: m_vector(other.m_vector){
}
Stack::Stack(Stack &&other) noexcept
: m_vector(std::move(other.m_vector)){

}


/* =================class functions=================*/
/**
@brief Determines whether the stack is empty.
@return true if the stack is empty, false otherwise.
*/
bool Stack::isEmpty() const {
    return m_vector.empty();
}
/**
@brief Adds a new element to the top of the stack.
@param value The value of the element to add.
*/
void Stack::push(const int value) {
    m_vector.push_back(value);
}

/**
@brief Removes the top element from the stack.
*/
void Stack::pop() {
    m_vector.pop_back();
}

/**
@brief Returns the top element of the stack without removing it.
@return int The value of the top element.
@throws std::out_of_range if the stack is empty.
*/
int Stack::top() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return m_vector[m_vector.size() - 1];
}

/**

@brief Returns the size of the Stack.
@return size_t The size of the Stack.
*/
size_t Stack::size() const {
    return m_vector.size();
}
/* =================operators overloading=================*/
/**
@brief Overloaded operator to add a number to all elements of the stack.
@param number The number to add.
@return Stack& A reference to the modified stack.
*/
Stack& Stack::operator+=(const int number) {
    for (size_t i = 0; i < m_vector.size();++i){
        m_vector[i] += number;
    }
    return *this;
}
/**
@brief Overloaded operator to subtract a number from all elements of the stack.
@param number The number to subtract.
@return Stack& A reference to the modified stack.
*/
Stack &Stack::operator-=(int number) {
    return *this += -number;
}
/**
@brief Overloaded operator to multiply all elements of the stack by a number.
@param number The number to multiply by.
@return Stack& A reference to the modified stack.
*/
Stack &Stack::operator*=(int number) {
    for (size_t i = 0; i < m_vector.size();++i){
        m_vector[i] *= number;
    }
    return *this;
}
/**
@brief Overloaded operator to divide all elements of the stack by a number.
@param number The number to divide by.
@return Stack& A reference to the modified stack.
@throws std::overflow_error if number is zero.
*/
Stack &Stack::operator/=(int number) {
    if (number == 0)
        throw std::overflow_error("Divide by zero exception");

    for (size_t i = 0; i < m_vector.size();++i){
        m_vector[i] /= number;
    }
    return *this;
}
/**
@brief Overloaded operator to compare two stacks for less than.
@param l The left-hand side stack.
@param r The right-hand side stack.
@return true if the size of the left-hand side stack is less than the size of the right-hand side stack, false otherwise.
*/
bool operator<(const Stack &l, const Stack &r) {
    return l.size() < r.size();
}
/**
@brief Overloaded operator to compare two stacks for greater than.
@param l The left-hand side stack.
@param r The right-hand side stack.
@return true if the size of the left-hand side stack is greater than the size of the right-hand side stack, false otherwise.
*/
bool operator>(const Stack &l, const Stack &r) {
    return r<l;
}
/**
@brief Overloaded operator to add two stacks together.
@param other The stack to add to this stack.
@return Stack A new stack containing the elements of this stack and the other stack.
*/
Stack Stack::operator+(const Stack& other){

    Stack result(*this);
    for (int i = 0; i < other.size(); i++)
        result.push(other.m_vector[i]);

    return result;
}

/**
 @brief Adds another stack to this stack.

 This operator modifies this stack to contain the elements of this stack followed by the elements of the other stack.

@param other The stack to add to this stack.
@return Stack& A reference to this stack.
*/
Stack &Stack::operator+=(const Stack &other) {
    *this = *this + other;
    return *this;
}
