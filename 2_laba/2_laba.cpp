#include <iostream>
#include "Stack.h"

int main()
{
    Stack stack(4);
    stack.push(2);
    stack.push(7);
    stack.push(9);
    
    std::cout << "������ �����: " << stack.size() << "\n";

    stack.pop();

    stack.print();
    return 0;
}
