#include "Stack.h"

Stack:: ~Stack() 
{
    while (!empty())
        pop();
}

Stack::Stack(int _size) : _size(_size), deep(0), head(nullptr) {}

Stack::Stack(const Stack& other) : _size(_size) {
    head = nullptr;
    int i = other.size() - 1;
    while (i > -1) {
        this->push(other.top());
        i--;
    }
}

void Stack::push(int data) {
    if (deep != _size) {

        stack_node* temp = head;
        head = new stack_node(data, temp);
        temp = nullptr;
        deep++;
    }
}

bool Stack::empty() const
{
    return head == nullptr; 
}

void Stack::pop() 
{
    if (!empty()) 
    {
        stack_node* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        deep--;
    }
}

int Stack::size() const {
    return deep;
}

int Stack::top() const {
    return head->data;
}

void Stack::print() const {
    if (!empty()) {
        stack_node* temp = head;
        for (int size = deep; size > 0; --size) {
            std::cout << temp->data << "\n";
            temp = temp->next;
        }
    }
    else {
        std::cout << "Error, stack is empty";
    }
}




