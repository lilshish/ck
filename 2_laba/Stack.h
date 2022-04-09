#pragma once
#include <iostream>
class Stack { 
private:
    struct stack_node 
    {
        int data;
        stack_node* next;

        stack_node(int data, stack_node* next = nullptr) : data(data), next(next) {}

    };
    stack_node* head;
    const int _size;
    int deep;
public:
    ~Stack();

    Stack(const Stack& other);

    Stack();

    Stack(int _size);

    void push(int);

    void pop();

    bool empty() const;

    int size() const;

    int top() const;

    void print() const;
};


