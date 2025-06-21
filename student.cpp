#include "student.h"
#include <iostream>
using namespace std;

Student::Student() : rollNo(0), name("") {
    for(int &mark : marks) mark = 0;
}

void Student::input() {
    cout << "Enter roll number: ";
    cin >> rollNo;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter marks for 5 subjects:\n";
    for(int i = 0; i < 5; i++) {
        cout << "Subject " << i+1 << ": ";
        cin >> marks[i];
    }
}

void Student::display() const {
    cout << "Roll No: " << rollNo << "\n";
    cout << "Name: " << name << "\n";
    cout << "Marks: ";
    for(int i = 0; i < 5; i++) cout << marks[i] << " ";
    cout << "\nAverage: " << calculateAverage() << "\n";
}

int Student::getRollNo() const {
    return rollNo;
}

void Student::setMarks(const int newMarks[5]) {
    for(int i = 0; i < 5; i++) marks[i] = newMarks[i];
}

int* Student::getMarks() {
    return marks;
}

string Student::getName() const {
    return name;
}

double Student::calculateAverage() const {
    int sum = 0;
    for(int i = 0; i < 5; i++) sum += marks[i];
    return sum / 5.0;
}