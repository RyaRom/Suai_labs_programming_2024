//
// Created by locadm on 9/26/2024.
//

#ifndef LAB6_H
#define LAB6_H
#include "utils/Scanner.h"

class Lab6 {
public:
    template<typename T>
    static void main();
};

template<typename T>
void Lab6::main() {
    auto *list = new LinkedList<T>();
    int count;
    std::cout << "Enter count of elements in list: " << std::endl;
    std::cin >> count;
    Scanner::fill_list(list, count);
    std::cout << "List: " << std::endl;
    list->print();

    T elem;
    std::cout << "Enter elem E" << std::endl;
    std::cin >> elem;

    list->deleteSublist(list->freq(elem));
    std::cout << "List after deleting sublist: " << std::endl;
    list->print();

    delete list;
}


#endif //LAB6_H
