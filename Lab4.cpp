//
// Created by locadm on 9/21/2024.
//

#include "Lab4.h"

#include <iostream>
#include <regex>
#include<string>


void Lab4::main(std::string input) {
    std::cout << "Input: " << input << std::endl;

    const std::string result = modifyString(input, "\\d+");

    std::cout << "Result: " << result << std::endl;
}

std::string Lab4::modifyString(std::string &input, const std::string &regex) {
    const std::regex word_pattern(regex);
    std::string result;

    const auto start = std::sregex_iterator(input.begin(), input.end(), word_pattern);
    const auto end = std::sregex_iterator();

    for (auto match = start; match != end; ++match) {
        std::string word = match->str();
        result += word;
        result += std::to_string(word.length());
        result += " ";
    }
    return result;
}
