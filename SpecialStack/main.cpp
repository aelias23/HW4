/*
* Name: Abdiel Elias
* Date: 11/24/2024
* Program Name: Special Stack
*
*
*/
#include "SpecialStack.h"

void SpecialStack::push(int value) {
    dataStack.push(value);
}


void SpecialStack::pop() {
    if (dataStack.empty()) {
        throw std::runtime_error("Stack underflow - Cannot pop from an empty stack");
    }
    dataStack.pop();
}

int SpecialStack::peek() const {
    if (dataStack.empty()) {
        throw std::runtime_error("Stack is empty - No top element to peek");
    }
    return dataStack.top();
}

bool SpecialStack::empty() const {
    return dataStack.empty();
}

void SpecialStack::printStack() const {
    std::stack<int> temp = dataStack;
    std::cout << "Stack contents (top to bottom): ";
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

void SpecialStack::popOdd() {
    if (dataStack.empty()) {
        throw std::runtime_error("Stack is empty - No odd number to pop");
    }

    bool found = false;
    while (!dataStack.empty()) {
        int value = dataStack.top();
        dataStack.pop();

        if (!found && value % 2 != 0) {
            found = true;
        } else {
            tempStack.push(value);
        }
    }


    while (!tempStack.empty()) {
        dataStack.push(tempStack.top());
        tempStack.pop();
    }

    if (!found) {
        throw std::runtime_error("No odd number to pop");
    }
}

void SpecialStack::popEven() {
    if (dataStack.empty()) {
        throw std::runtime_error("Stack is empty - No even number to pop");
    }

    bool found = false;
    while (!dataStack.empty()) {
        int value = dataStack.top();
        dataStack.pop();

        if (!found && value % 2 == 0) {
            found = true;
        } else {
            tempStack.push(value);
        }
    }


    while (!tempStack.empty()) {
        dataStack.push(tempStack.top());
        tempStack.pop();
    }

    if (!found) {
        throw std::runtime_error("No even number to pop");
    }
}
