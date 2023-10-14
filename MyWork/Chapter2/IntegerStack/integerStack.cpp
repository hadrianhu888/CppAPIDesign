/**
 * @file integerStack.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <vector>

#define MAX_SIZE 100

class IntegerStack {
    private:
        std::vector<int> stack;
        void push(int value);
        int pop();
        int size();
    public:
        IntegerStack(){};
        int peek();
        bool isEmpty();
        bool isFull();
        void print();
        void Push(int value);
        int Pop();
        int Size();
};

void IntegerStack::push(int value) { stack.push_back(value); }

int IntegerStack::pop() {
    int value = stack.back();
    stack.pop_back();
    return value;
}

int IntegerStack::peek() { return stack.back(); }

int IntegerStack::size() { return stack.size(); }

bool IntegerStack::isEmpty() { return stack.empty(); }

bool IntegerStack::isFull() { return false; }

void IntegerStack::print() {
    std::cout << "Stack: ";
    for (int i = 0; i < stack.size(); i++) {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}

void IntegerStack::Push(int value) {
    if (isFull()) {
        std::cout << "Stack is full" << std::endl;
    } else {
        push(value);
    }
}

int IntegerStack::Pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return -1;
    } else {
        return pop();
    }
}

int IntegerStack::Size() { return size(); }

int main() {
    IntegerStack stack;
    std::cout << "Stack isEmpty: " << stack.isEmpty() << std::endl;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.print();
    std::cout << "Stack peek: " << stack.peek() << std::endl;
    std::cout << "Stack pop: " << stack.Pop() << std::endl;
    stack.print();
    std::cout << "Stack size: " << stack.Size() << std::endl;
    return 0;
}