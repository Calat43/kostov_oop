#include <iostream>
#include "container.h"

int main()
{
    Container<int> c;
    for (int i = 0; i < 42; ++i) {
        c.addFirst(i);
    }
    std::cout << c.getSize() << std::endl;
    while(c.getSize() != 5) {
        std::cout << c.getLast() << " ";
        c.removeLast();
    }
    std::cout << std::endl;
    c.clean();
    std::cout << c.getSize() << std::endl;
    return 0;
}