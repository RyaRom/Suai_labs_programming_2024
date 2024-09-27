#include "Lab4.h"

#include <fstream>
#include <iostream>
#include <regex>
#include<string>
#define FNAME_R  "C:\\Users\\locadm\\CLionProjects\\Suai_labs_programming_2024\\files\\input.txt"
#define FNAME_W  "C:\\Users\\locadm\\CLionProjects\\Suai_labs_programming_2024\\files\\output.txt"
using namespace std;

void Lab4::main() {
    if (!verifyFile(FNAME_W)) {
        createFile(FNAME_W);
    }
    if (!verifyFile(FNAME_R)) {
        cout << "File not found: " << FNAME_R << endl;
        return;
    }
    string input = readFile(FNAME_R);
    cout << "Input: " << input << endl;

    writeInFile(FNAME_W, modifyString(input, "\\d+"));

    cout << "Result: " << readFile(FNAME_W) << endl;
}

string Lab4::modifyString(string &input, const string &regex) {
    const std::regex word_pattern(regex);
    string result;

    const auto start = sregex_iterator(input.begin(), input.end(), word_pattern);
    const auto end = sregex_iterator();

    for (auto match = start; match != end; ++match) {
        string word = match->str();
        result += word;
        result += to_string(word.length());
        result += " ";
    }
    return result;
}

bool Lab4::verifyFile(const std::string &file_name) {
    const ifstream inFileW(file_name);
    return inFileW.good();
}

void Lab4::createFile(const std::string &file_name) {
    ofstream outFileW(file_name);
    outFileW.close();
}

string Lab4::readFile(const string &file_name) {
    ifstream inFileR(file_name, ios::in);

    stringstream ss;
    string input;
    while (getline(inFileR, input)) {
        ss << input;
    }

    inFileR.close();
    return ss.str();
}

void Lab4::writeInFile(const string &file_name, const string &content) {
    ofstream outFileW(file_name, ios::out);

    outFileW << content;
    outFileW.close();
}
