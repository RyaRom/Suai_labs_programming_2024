//
// Created by locadm on 9/21/2024.
//

#ifndef LAB4_H
#define LAB4_H
#include <string>


class Lab4 {
public:
    static void main();

private:
    static std::string modifyString(std::string &input, const std::string &regex);

    static bool verifyFile(const std::string &file_name);

    static void createFile(const std::string &file_name);

    static std::string readFile(const std::string &file_name);

    static void writeInFile(const std::string &file_name, const std::string &content);
};


#endif //LAB4_H
