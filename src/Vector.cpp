//
// Created by Damian Tissembaum on 19/03/2023.
//


#include "../include/Vector.h"

/* =================Constructors=================*/
/**

@brief Constructs a new Vector object with a given size and value.
@param size The size of the new vector.
@param value The initial value to be set for all elements in the vector.
*/
Vector::Vector(const size_t size,const int value)
    :m_size(size),m_capacity(size),m_data(new int [m_capacity]){
    for (size_t i = 0; i < size; ++i)
        m_data[i] = value;

}
/**

@brief Destructs a Vector object. Delete memory
*/
Vector::~Vector() {
    delete[] m_data;
}
/**

@brief Constructs a new Vector object by copying another vector.
@param other The vector to be copied.
*/
Vector::Vector(const Vector& other)
    :m_size(other.size()), m_capacity(other.capacity()), m_data(new int[m_capacity]){
    for (size_t i = 0; i < m_size; ++i)
        m_data[i] = other[i];
}

/**

@brief Constructs a new Vector object by moving another vector.
@param other The vector to be copied.
*/
Vector::Vector(Vector&& other) noexcept
        : m_size(other.size()), m_capacity(other.capacity()){
    for (size_t i = 0; i < m_size; ++i)
        m_data[i] = other[i];
    // Reset the source object
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_data = nullptr;
}

/* =================class functions=================*/
/**

@brief Inserts an element with a given value at a specific index in the vector.
@param index The index at which to insert the new element.
@param value The value to be assigned to the new element.
@throws std::out_of_range if the index is out of range (i.e., less than 0 or greater than the current size of the vector).
*/
void Vector::insert(size_t index, int value) {

    if (index < 0 || index > m_size)
        throw std::out_of_range("Index out of range");


    //resizing the capacity of the vector
    else if (m_size == m_capacity) {
        if (m_capacity == 0)
            m_capacity = 1;

        m_capacity = m_capacity < 128 ? 2 * m_capacity : m_capacity * 3 / 2;

        int* newData = new int[m_capacity];
        for (size_t i = 0; i < index; ++i) {
            newData[i] = m_data[i];
        }
        newData[index] = value;
        for (size_t i = index; i < m_size; ++i) {
            newData[i + 1] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
    }

    else {
        //moving the values one place right until getting to index received
        for (size_t i = m_size; i > index; --i) {
            m_data[i] = m_data[i - 1];
        }
        m_data[index] = value;
    }
    ++m_size;
}
/**

@brief Removes an element at a specific index in the vector.
@param index The index of the element to remove.
@throws std::out_of_range if the index is out of range (i.e., less than 0 or greater than or equal to the current size of the vector), or if the vector is empty.
*/
void Vector::erase(const size_t index) {

    if (empty())
        throw std::out_of_range("Vector is empty");

    if (index < 0 || index >= m_size)
        throw std::out_of_range("Index out of range");

    for (size_t i = index; i < m_size-1; i++)
        m_data[i] = m_data[i+1];

    m_size--;

}
/**

@brief Returns a pointer to the internal array of the vector.
@return int* A pointer to the internal array of the vector.
@return nullptr if the vector is empty.
*/
int *Vector::data() {
    if (empty())
        return nullptr;

    return &m_data[0];
}

/**

@brief Returns whether the vector is empty or not.
@return true if the vector is empty, false otherwise.
*/
bool Vector::empty() const {
    if (m_size == 0)
        return true;

    return false;
}

/**

@brief Returns the size of the vector.
@return size_t The size of the vector.
*/
size_t Vector::size() const {
    return m_size;
}

/**

@brief Returns the capacity of the vector.
@return size_t The capacity of the vector.
*/
size_t Vector::capacity() const {
    return m_capacity;
}
/**

@brief Clears the vector and deallocates all memory associated with it.
*/
void Vector::clear() {
    delete[] m_data;
    m_size = 0;
    m_capacity = 0;
    m_data = new int [m_capacity];
}
/**

@brief Resizes the vector to a new capacity and fills new elements with a given value.
@param newCapacity The new capacity of the vector.
@param value The value to be assigned to new elements.
*/
void Vector::resize(const size_t newCapacity, const int value) {
    std::cout << "value is: " << value;
    int* newData = new int[newCapacity];
    if (newCapacity > m_size){
        for (size_t i = 0; i < m_size; ++i)
            newData[i] = m_data[i];

        for (size_t i = m_size; i < newCapacity; ++i)
            newData[i] = value;

    }
    else{
        for (size_t i = 0; i < newCapacity; ++i)
            newData[i] = m_data[i];
    }

    m_capacity = newCapacity;
    delete[] m_data;
    m_data = newData;
    m_size = newCapacity;



}
/**

@brief Swaps the contents of this vector with another vector.
@param other The vector to swap with.
*/
void Vector::swap(Vector& other) {
    // swap the internal data
    int* temp_data = m_data;
    m_data = other.m_data;
    other.m_data = temp_data;

    // swap the size
    size_t temp_size = m_size;
    m_size = other.m_size;
    other.m_size = temp_size;

    // swap the capacity
    size_t temp_capacity = m_capacity;
    m_capacity = other.m_capacity;
    other.m_capacity = temp_capacity;
}
/**
@brief Adds an element to the end of the vector.
@param value The value of the element to add.
*/
void Vector::push_back(const int value) {
    insert(m_size, value);
}
/**
@brief Removes the last element from the vector.
*/
void Vector::pop_back() {
    erase(m_size-1);
}
/* =================operators overloading=================*/
/**

@brief Overloaded operator[] for accessing elements in the vector by index.
@param index The index of the element to access.
@return int& A reference to the element at the specified index.
@throws std::out_of_range if the index is out of range (i.e., less than 0 or greater than the current size of the vector).
*/
int &Vector::operator[](const size_t& index) {
    if (index < 0 || index > m_size)
        throw std::out_of_range("Index out of range");
    return m_data[index];
}
/**

@brief Overloaded operator[] for accessing elements in the vector by index.
@param index The index of the element to access.
@return const int& A const reference to the element at the specified index.
@throws std::out_of_range if the index is out of range (i.e., less than 0 or greater than the current size of the vector).
*/
const int& Vector::operator[](const size_t index) const {
    if (index < 0 || index > m_size)
        throw std::out_of_range("Index out of range");
    return m_data[index];
}

/**

@brief Overloaded copy assignment operator to copy one vector to another.
@param other The vector to be copied.
@return Vector& A reference to the new vector.
*/
Vector& Vector::operator=(const Vector& other)
{
    if (this != &other) {
        Vector temp(other); // create a temporary vector using the copy constructor
        swap(temp); // swap the current vector with the temporary vector
    }
    return *this;
}
/**
@brief Compares two vectors for equality.
@param other The vector to compare to.
@return true if the two vectors have the same size and the same elements in the same order, false otherwise.
*/
bool Vector::operator==(const Vector &other) const {
    if (m_size != other.size())
        return false;

    for (size_t i = 0; i < m_size; ++i) {
        if (m_data[i] != other[i])
            return false;

    }
    return true;
}

/**
@brief Determines whether one vector is less than another vector.
@param l The left-hand side vector.
@param r The right-hand side vector.
@return true if in lexicographic order an element of l is less than the corresponding element of r. False if the
 in lexicographic order an element of r is less than the corresponding element of l.
 If both vectors have the same elements, return true if the size of vector l is smaller than r
*/
bool operator<(const Vector& l, const Vector& r) {
    size_t minSize = l.size() < r.size() ? l.size() : r.size();

    for (size_t i = 0; i < minSize; ++i) {
        if (l[i] < r[i])
            return true;

        else if (l[i] > l[i])
            return false;

    }
    return l.size() < r.size();
}
/**
@brief Determines whether one vector is greater than another vector. Reuses operator <
@param l The left-hand side vector.
@param r The right-hand side vector.
@return true if in lexicographic order an element of l is greater than the corresponding element of r. False if the
 in lexicographic order an element of r is greater than the corresponding element of l.
 If both vectors have the same elements, return true if the size of vector l is greater than r
*/
bool operator>(const Vector& l, const Vector& r) {
    return r < l;
}

/**
@brief Determines whether one vector is less or equal than another vector. Reuses operator >
@param l The left-hand side vector.
@param r The right-hand side vector.
@return true if left vector is not greater thar right vector
*/
bool operator<=(const Vector& l, const Vector& r){
    return !(l>r);
}
/**
@brief Determines whether one vector is greater or equal than another vector. Reuses operator >
@param l The left-hand side vector.
@param r The right-hand side vector.
@return true if left vector is not less thar right vector
*/
bool operator>=(const Vector& l, const Vector& r){
    return !(l<r);
}
/**
@brief Compares two vectors for equality.
@param other The vector to compare to.
@return false if the two vectors have the same size and the same elements in the same order, false otherwise.
 */
bool operator!=(const Vector &l, const Vector &r) {
    return !(l==r);
}


