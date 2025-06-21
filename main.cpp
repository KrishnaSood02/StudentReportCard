#include "student.h"
#include "report_card.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<Student> loadData(const string& filename) {
    vector<Student> students;
    ifstream fin(filename, ios::binary);
    if (fin) {
        Student s;
        while (fin.read(reinterpret_cast<char*>(&s), sizeof(Student)))
            students.push_back(s);
        fin.close();
    }
    return students;
}

void saveData(const string& filename, const vector<Student>& students) {
    ofstream fout(filename, ios::binary | ios::trunc);
    for (const Student& s : students)
        fout.write(reinterpret_cast<const char*>(&s), sizeof(Student));
    fout.close();
}

void addStudent(vector<Student>& students) {
    Student s;
    s.input();
    students.push_back(s);
    cout << "Student added successfully.\n";
}

void displayAll(const vector<Student>& students) {
    cout << "\nAll Students:\n";
    for(const Student& s : students) {
        s.display();
        cout << "-----------------\n";
    }
}

void searchStudent(const vector<Student>& students) {
    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;
    for(const Student& s : students) {
        if(s.getRollNo() == roll) {
            s.display();
            ReportCard::generate(s);
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent(vector<Student>& students) {
    int roll;
    cout << "Enter roll number to delete: ";
    cin >> roll;
    auto it = remove_if(students.begin(), students.end(),
                        [roll](const Student& s){ return s.getRollNo() == roll; });
    if(it != students.end()) {
        students.erase(it, students.end());
        cout << "Student deleted.\n";
    } else {
        cout << "Student not found.\n";
    }
}

void updateMarks(vector<Student>& students) {
    int roll;
    cout << "Enter roll number to update marks: ";
    cin >> roll;
    for(Student& s : students) {
        if(s.getRollNo() == roll) {
            int newMarks[5];
            cout << "Enter new marks for 5 subjects:\n";
            for(int i = 0; i < 5; i++) {
                cout << "Subject " << i+1 << ": ";
                cin >> newMarks[i];
            }
            s.setMarks(newMarks);
            cout << "Marks updated.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    const string filename = "data.txt";
    vector<Student> students = loadData(filename);

    int choice;
    do {
        cout << "\n1. Add Student\n2. Display All\n3. Search Student\n4. Delete Student\n5. Update Marks\n6. Save & Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: addStudent(students); break;
            case 2: displayAll(students); break;
            case 3: searchStudent(students); break;
            case 4: deleteStudent(students); break;
            case 5: updateMarks(students); break;
            case 6: saveData(filename, students); cout << "Data saved. Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 6);
    return 0;
}