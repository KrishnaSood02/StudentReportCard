#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int rollNo;
    std::string name;
    int marks[5]; // 5 subjects

public:
    Student();
    void input();
    void display() const;
    int getRollNo() const;
    void setMarks(const int newMarks[5]);
    int* getMarks();
    std::string getName() const;
    double calculateAverage() const;
};

#endif