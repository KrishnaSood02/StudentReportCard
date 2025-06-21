#include "report_card.h"
#include <iostream>
using namespace std;

void ReportCard::generate(const Student& s) {
    cout << "\n====== Report Card ======\n";
    s.display();
    cout << "========================\n";
    double avg = s.calculateAverage();
    if(avg >= 90) cout << "Grade: A+\n";
    else if(avg >= 80) cout << "Grade: A\n";
    else if(avg >= 70) cout << "Grade: B\n";
    else if(avg >= 60) cout << "Grade: C\n";
    else if(avg >= 50) cout << "Grade: D\n";
    else cout << "Grade: F\n";
    cout << "========================\n";
}