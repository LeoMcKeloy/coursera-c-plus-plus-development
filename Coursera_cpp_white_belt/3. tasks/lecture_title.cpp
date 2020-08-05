#include <iostream>
using namespace std;

struct Specialization {
    string str;
    explicit Specialization(string new_specialization) {
        str = new_specialization;
    }
};

struct Course {
    string str;
    explicit Course(string new_course) {
        str = new_course;
    }
};

struct Week {
    string str;
    explicit Week(string new_week) {
        str = new_week;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(Specialization new_specialization, Course new_course, Week new_week) {
        specialization = new_specialization.str;
        course = new_course.str;
        week = new_week.str;
    }
};

int main() {
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );

    return 0;
}