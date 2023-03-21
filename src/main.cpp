#include "../include/Vector.h"
#include "../include/Stack.h"
#include <iostream>
#include <cassert>

int main() {
    try{
        // create a vector with 3 elements, initialized to 2
        Vector v1(3, 2);

        // test the copy constructor
        Vector v2(v1);
        assert(v1 == v2);

        // test the assignment operator
        Vector v3 = v1;
        assert(v3 == v1);

        // test the data function
        int* ptr = v1.data();
        assert(ptr != nullptr && *ptr == 2);

        // test the empty function
        assert(!v1.empty() && Vector().empty());

        // test the clear function
        v1.clear();
        assert(v1.empty() && v1.capacity() == 0);

        // test the insert function
        v2.insert(2, 8);
        assert(v2[2] == 8);
        assert(v2[3] == 2);
        assert(v2.size() == 4);

        // test the resize function
        v2.resize(6, 4);
        assert(v2.size() == 6);
        assert(v2.capacity() == 6);
        std::cout << " place 3: " << v2[3] << " place 4: " << v2[4] << " place 5: " << v2[5] << std::endl;
        assert(v2[3] == 2 && v2[4] == 4 && v2[5] == 4);

        // test the push_back function
        v2.push_back(6);
        assert(v2.size() == 7);
        assert(v2.capacity() == 12);
        assert(v2[6] == 6);

        // test the pop_back function
        v2.pop_back();
        assert(v2.size() == 6);
        assert(v2.capacity() == 12);
        assert(v2[5] == 4);

        // test the erase function
        v2.erase(1);
        assert(v2.size() == 5);
        assert(v2.capacity() == 12);
        assert(v2[1] == 8);

        // test the comparison operators
        Vector v4(2, 3);
        Vector v5(2, 3);
        Vector v6(3, 3);
        Vector v7(2, 4);

        assert(v4 == v5);
        assert(!(v4 != v5));
        assert(v4 <= v5);
        assert(v4 >= v5);
        assert(!(v4 < v5));
        assert(!(v4 > v5));

        assert(v4 != v6);
        assert(!(v4 == v6));
        assert(v4 < v6);
        assert(v4 <= v6);
        assert(!(v4 > v6));
        assert(!(v4 >= v6));

        assert(v4 != v7);
        assert(!(v4 == v7));
        assert(v4 < v7);
        assert(v4 <= v7);
        assert(!(v4 > v7));
        assert(!(v4 >= v7));

        std::cout << "All Vector's tests passed!" << std::endl;

        // create a new stack with size 5 and initial value 0
        Stack myStack(5, 0);

        // check if the stack is empty
        std::cout << "Is stack empty? " << myStack.isEmpty() << std::endl;

        // add some elements to the stack
        myStack.push(1);
        myStack.push(2);
        myStack.push(3);

        // check the size of the stack
        std::cout << "Stack size: " << myStack.size() << std::endl;

        // print the top element of the stack
        std::cout << "Top of stack: " << myStack.top() << std::endl;

        // remove the top element from the stack
        myStack.pop();

        // print the top element of the stack again
        std::cout << "Top of stack: " << myStack.top() << std::endl;

        // add 5 to all elements of the stack
        myStack += 5;

        // print the top element of the stack again
        std::cout << "Top of stack: " << myStack.top() << std::endl;

        // subtract 3 from all elements of the stack
        myStack -= 3;

        // print the top element of the stack again
        std::cout << "Top of stack: " << myStack.top() << std::endl;

        // multiply all elements of the stack by 2
        myStack *= 2;

        // print the top element of the stack again
        std::cout << "Top of stack: " << myStack.top() << std::endl;

        // divide all elements of the stack by 4
        myStack /= 4;

        // print the top element of the stack again
        std::cout << "Top of stack: " << myStack.top() << std::endl;

        // create another stack and add it to the first stack
        Stack otherStack(3, 10);
        myStack += otherStack;

        // print the top element of the stack again
        std::cout << "Top of stack: " << myStack.top() << std::endl;

        // compare the size of the two stacks
        std::cout << "myStack < otherStack? " << (myStack < otherStack) << std::endl;
        std::cout << "myStack > otherStack? " << (myStack > otherStack) << std::endl;

    }catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
