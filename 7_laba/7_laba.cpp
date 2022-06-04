#include <iostream>
#include <algorithm>
#include "Buffer.h"
#include "Error.h"




int main() {
    try {
        RingBuffer<int> example_buffer(6);
        example_buffer.add(2);
        example_buffer.add_begin(5);
        example_buffer.add_end(78);
        example_buffer.add_element(1, 45);
        example_buffer.add_element(4, 95);
        example_buffer.delete_start();
        example_buffer.add(23);
        example_buffer.add(34);

        auto iterator_example_buffer = example_buffer.begin();
        *iterator_example_buffer++ = 28;


        std::cout << "Estimated value of the ring buffer \n5 28 95 78 23 34 \n";
        std::cout << "The resulting values" << std::endl;
        for (auto itr = example_buffer.begin(); itr != example_buffer.end(); itr++) {
            std::cout << *itr << " ";
        }

        std::cout << "\nSorted buffer, example for STL container \n";
        std::sort(example_buffer.begin(), example_buffer.end());
        for (auto itr = example_buffer.begin(); itr != example_buffer.end(); itr++) {
            std::cout << *itr << " ";
        }

        example_buffer.resize(10);

        std::cout << std::endl << "capacity: " << example_buffer.capacity() << " size: " << example_buffer.size();
    }
    catch (MyException& exception)
    {
        std::cout << '\n' << "Error: " << exception.Error() << '\n';
    }

    return 0;
}