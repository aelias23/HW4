#ifndef SPECIALSTACK_H
#define SPECIALSTACK_H
#include "SpecialStack.h"


#include <stack>
#include <iostream>
#include <stdexcept>

class SpecialStack {
private:
    std::stack<int> dataStack;
    std::stack<int> tempStack;

public:
    void push(int value);
    void pop();
    int peek() const;
    bool empty() const;
    void printStack() const;
    void popOdd();
    void popEven();
};

#endif
