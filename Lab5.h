//
// Created by locadm on 9/25/2024.
//

#ifndef LAB5_H
#define LAB5_H
#include <stdint.h>

typedef struct ScienceConference {
    char section[100];
    char leader_name[100];
    char place[100];
    time_t start_time;
    uint16_t members;
} ScienceConference;

enum class SortField {
    SECTION,
    LEADER_NAME,
    PLACE,
    START_TIME,
    MEMBERS
};

int compare_by_field(
    const ScienceConference *confA, const ScienceConference *confB, const SortField *field_ptr);

void quick_sort_conf(ScienceConference *conf,
                     int (*compare_by_field)(const ScienceConference *confA, const ScienceConference *confB,
                                             const SortField *field_ptr), SortField *field, size_t size);

class Lab5 {
public:
    static void main();

private:
    static void db_create();

    static bool db_verify();

    static void db_add();

    static void db_sort_by_and_write(SortField field);

    static void db_find_by_and_write(SortField field);

    static void db_print(const std::string &f_name);

    static void db_override_array(ScienceConference *conferences, size_t count);

    static time_t read_time();


    static std::string parse_time(time_t time);
};

constexpr const char *sortFieldToString(const SortField field) {
    switch (field) {
        case SortField::SECTION: return "SECTION";
        case SortField::LEADER_NAME: return "LEADER_NAME";
        case SortField::PLACE: return "PLACE";
        case SortField::START_TIME: return "START_TIME";
        case SortField::MEMBERS: return "MEMBERS";
        default: return "UNKNOWN";
    }
}

constexpr int DB_LIMIT = 1000;


#endif //LAB5_H
