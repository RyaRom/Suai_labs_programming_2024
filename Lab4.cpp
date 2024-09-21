//
// Created by locadm on 9/21/2024.
//

#include "Lab4.h"

#include <iostream>
#include <regex>
#include<string>


void Lab4::main() {
    const std::regex word_pattern("\\d+");
    std::string line;
    std::string result;
    std::cout << "Enter a line: ";
    std::getline(std::cin, line);

    const auto start = std::sregex_iterator(line.begin(), line.end(), word_pattern);
    const auto end = std::sregex_iterator();

    for (auto match = start; match != end; ++match) {
        std::string word = match->str();
        result += word;
        result += std::to_string(word.length());
        result += " ";
    }

    std::cout << "Result: " << result << std::endl;
}
