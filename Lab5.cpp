#include <cstdint>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Lab5.h"
#define FNAME_R  "C:\\Users\\locadm\\CLionProjects\\Suai_labs_programming_2024\\files\\db.dat"
#define FNAME_W  "C:\\Users\\locadm\\CLionProjects\\Suai_labs_programming_2024\\files\\db_output.dat"
using namespace std;


void Lab5::main() {
    if (!db_verify()) {
        db_create();
    }

    int input = 1;

    while (input != 0) {
        cout <<
                "0. Exit\n"
                "1. Add new record\n"
                "2. Show all records\n"
                "3. Find by section name\n"
                "4. Find by leader name\n"
                "5. Find by place\n"
                "6. Find by start time\n"
                "7. Find by members count\n"
                "8. Sort by section name\n"
                "9. Sort by leader name\n"
                "10. Sort by place\n"
                "11. Sort by start time\n"
                "12. Sort by members count\n"
                "13. Show search results\n"
                "14. Drop all data\n"
                "Enter your choice: ";
        cin >> input;

        switch (input) {
            case 1:
                db_add();
                break;
            case 2:
                db_print(FNAME_R);
                break;
            case 3:
                db_find_by_and_write(SortField::SECTION);
                break;
            case 4:
                db_find_by_and_write(SortField::LEADER_NAME);
                break;
            case 5:
                db_find_by_and_write(SortField::PLACE);
                break;
            case 6:
                db_find_by_and_write(SortField::START_TIME);
                break;
            case 7:
                db_find_by_and_write(SortField::MEMBERS);
                break;
            case 8:
                db_sort_by_and_write(SortField::SECTION);
                break;
            case 9:
                db_sort_by_and_write(SortField::LEADER_NAME);
                break;
            case 10:
                db_sort_by_and_write(SortField::PLACE);
                break;
            case 11:
                db_sort_by_and_write(SortField::START_TIME);
                break;
            case 12:
                db_sort_by_and_write(SortField::MEMBERS);
                break;
            case 13:
                db_print(FNAME_W);
                break;
            case 14:
                db_create();
                break;
            default:
                break;
        }
    }
}

void Lab5::db_create() {
    ofstream outFileR(FNAME_R, ios::binary);
    ofstream outFileW(FNAME_W, ios::binary);
}

bool Lab5::db_verify() {
    ifstream inFileR(FNAME_R, ios::binary);
    ifstream inFileW(FNAME_W, ios::binary);

    return inFileR.good() && inFileW.good();
}

void Lab5::db_add() {
    if (!db_verify()) {
        return;
    }
    ofstream outFile(FNAME_R, ios::binary | ios::app);

    while (true) {
        ScienceConference conference;
        cout << "Enter start time\n";
        const time_t timestamp = read_time();
        if (timestamp == -1) {
            continue;
        }
        conference.start_time = timestamp;

        cout << "Enter section name\n";
        cin.getline(conference.section, 100);

        cout << "Enter leader name\n";
        cin.getline(conference.leader_name, 100);

        cout << "Enter place\n";
        cin.getline(conference.place, 100);

        cout << "Enter members count\n";
        cin >> conference.members;

        outFile.write(reinterpret_cast<char *>(&conference), sizeof(ScienceConference));

        cout << "Continue? [Y/N]";
        char c;
        cin >> c;
        if (c != 'Y' && c != 'y') {
            outFile.close();
            return;
        }
    }
}

void Lab5::db_override_array(ScienceConference *conferences, size_t count) {
    if (!db_verify()) {
        return;
    }
    ofstream outFile(FNAME_W, ios::binary | ios::trunc);

    for (size_t i = 0; i < count; ++i) {
        outFile.write(reinterpret_cast<char *>(&conferences[i]), sizeof(ScienceConference));
    }
    outFile.close();
    delete[] conferences;
}

void Lab5::db_sort_by_and_write(SortField field) {
    if (!db_verify()) {
        return;
    }

    ifstream inFile(FNAME_R, ios::binary | ios::in);
    ofstream outFile(FNAME_W, ios::binary | ios::app);
    ScienceConference conference;
    auto *conferences = new ScienceConference[DB_LIMIT];

    int max = 0;
    for (int i = 0; i < DB_LIMIT; ++i) {
        if (!inFile.read(reinterpret_cast<char *>(&conference), sizeof(ScienceConference))) {
            break;
        }
        max++;
        conferences[i] = conference;
    }
    quick_sort_conf(conferences, compare_by_field, &field, max);

    db_override_array(conferences, max);
}

void quick_sort_conf(ScienceConference *conf,
                     int (*compare_by_field)(const ScienceConference *confA, const ScienceConference *confB,
                                             const SortField *field_ptr), SortField *field, const size_t size) {
    if (size <= 1) {
        return;
    }

    const ScienceConference pivot = conf[size / 2];
    int i = 0;
    int j = size - 1;

    while (i <= j) {
        while (compare_by_field(&conf[i], &pivot, field) < 0) {
            i++;
        }
        while (compare_by_field(&conf[j], &pivot, field) > 0) {
            j--;
        }
        if (i <= j) {
            std::swap(conf[i], conf[j]);
            i++;
            j--;
        }
    }

    quick_sort_conf(conf, compare_by_field, field, j + 1);
    quick_sort_conf(conf + i, compare_by_field, field, size - i);
}

int compare_by_field(
    const ScienceConference *confA, const ScienceConference *confB, const SortField *field_ptr) {
    switch (*field_ptr) {
        case SortField::SECTION:
            return strcmp(confA->section, confB->section);
        case SortField::LEADER_NAME:
            return strcmp(confA->leader_name, confB->leader_name);
        case SortField::PLACE:
            return strcmp(confA->place, confB->place);
        case SortField::START_TIME:
            return confA->start_time < confB->start_time ? -1 : (confA->start_time > confB->start_time ? 1 : 0);
        case SortField::MEMBERS:
            return confA->members < confB->members ? -1 : (confA->members > confB->members ? 1 : 0);
    }
    return 0;
}

void Lab5::db_find_by_and_write(SortField field) {
    if (!db_verify()) {
        return;
    }

    ifstream inFile(FNAME_R, ios::binary | ios::in);
    ofstream outFile(FNAME_W, ios::binary | ios::trunc);
    ScienceConference conference;

    cout << "enter the " << sortFieldToString(field) << endl;

    time_t time;
    uint16_t members;
    string other;
    switch (field) {
        case SortField::START_TIME:
            time = read_time();
            break;
        case SortField::MEMBERS:
            cin >> members;
            break;
        default:
            cin >> other;
            break;
    }

    for (int i = 0; i < DB_LIMIT; ++i) {
        if (!inFile.read(reinterpret_cast<char *>(&conference), sizeof(ScienceConference))) {
            break;
        }
        switch (field) {
            case SortField::PLACE:
                if (conference.place == other) {
                    outFile.write(reinterpret_cast<char *>(&conference), sizeof(ScienceConference));
                }
                break;
            case SortField::LEADER_NAME:
                if (conference.leader_name == other) {
                    outFile.write(reinterpret_cast<char *>(&conference), sizeof(ScienceConference));
                }
                break;
            case SortField::SECTION:
                if (conference.section == other) {
                    outFile.write(reinterpret_cast<char *>(&conference), sizeof(ScienceConference));
                }
                break;
            case SortField::START_TIME:
                if (conference.start_time == time) {
                    outFile.write(reinterpret_cast<char *>(&conference), sizeof(ScienceConference));
                }
                break;
            case SortField::MEMBERS:
                if (conference.members == members) {
                    outFile.write(reinterpret_cast<char *>(&conference), sizeof(ScienceConference));
                }
                break;
        }
    }
    inFile.close();
    outFile.close();
}

void Lab5::db_print(const string &f_name) {
    if (!db_verify()) {
        return;
    }
    ifstream inFile(f_name, ios::binary | ios::in);
    ScienceConference conference;

    while (inFile.read(reinterpret_cast<char *>(&conference), sizeof(ScienceConference))) {
        string timeStr = parse_time(conference.start_time);
        cout << timeStr << " "
                << conference.section << " "
                << conference.leader_name << " "
                << conference.place << " "
                << conference.members << endl;
    }

    inFile.close();
}

time_t Lab5::read_time() {
    string input;
    cout << "Enter start time (YYYY-MM-DD HH:MM:SS): ";
    getline(cin, input);

    tm tm = {};
    istringstream ss(input);
    ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S");

    if (ss.fail()) {
        cerr << "Error parsing time" << endl;
        return -1;
    }

    return mktime(&tm);
}


string Lab5::parse_time(const time_t time) {
    char buff[20];
    strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", localtime(&time));
    return std::string(buff);
}
