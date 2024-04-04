
#include "CircularLinkedList.h"
#include <iostream>
#include <string>

int main() {
    CircularLinkedList<int> intList;
    intList.push(1);
    intList.push(2);
    intList.push(3);
    intList.push(3);
    intList.remove(2);
    intList.push(3);
    intList.push(3);
    intList.push(3);
    intList.push(2);

    


    std::cout << "Integer list:" << std::endl;
    for (int i = 0; i < intList.get_size(); i++) {
        std::cout << intList.get(i) << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    CircularLinkedList<std::string> stringList;
    stringList.push("Hello");
    stringList.push("World");

    std::cout << "String list:" << std::endl;
    for (int i = 0; i < stringList.get_size(); i++) {
        std::cout << stringList.get(i) << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "Iterator:" << std::endl;
    auto it = intList.begin();
    while (it != intList.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    return 0;
}
