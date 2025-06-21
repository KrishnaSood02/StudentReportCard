#ifndef REPORT_CARD_H
#define REPORT_CARD_H

#include "student.h"

class ReportCard {
public:
    static void generate(const Student& s);
};

#endif