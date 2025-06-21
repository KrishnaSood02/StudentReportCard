# Student Report Card Management System

A console-based C++ application to manage student records, grades, and generate report cards. This project demonstrates file I/O, OOP principles, and basic data management.

## Features

- Add, display, search, and delete student records
- Update student grades
- Generate report cards
- File-based data persistence

## How to Run

1. Compile the project:

   ```bash
   g++ main.cpp student.cpp report_card.cpp -o reportcard
   ```

2. Run the executable:

   ```bash
   ./reportcard
   ```

## Files

- `main.cpp` — Main menu and program logic
- `student.h`, `student.cpp` — Student class and its methods
- `report_card.h`, `report_card.cpp` — ReportCard class and its methods
- `data.txt` — Persists student data