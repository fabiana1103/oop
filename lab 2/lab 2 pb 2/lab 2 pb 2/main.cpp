#include <iostream>

#include "Student.h"
#include "Comparisons.h"

void PrintResult(const char* crit, int res, const Student& s1, const Student& s2)
{
    std::cout << "comparison by " << crit << ": ";
    if (res == 0) std::cout << s1.getName() << " and " << s2.getName() << " are equal.\n";
    else if (res == 1) std::cout << s1.getName() << " is greater.\n";
    else std::cout << s2.getName() << " is greater.\n";
}

int main()
{
    Student student1;
    student1.setName("mara");
    student1.setMathGrade(5.0f);
    student1.setEnglishGrade(8.0f);
    student1.setHistoryGrade(10.0f);

    Student student2;
    student2.setName("ion");
    student2.setMathGrade(7.0f);
    student2.setEnglishGrade(7.5f);
    student2.setHistoryGrade(9.0f);

    std::cout << student1.getName() << "'s average: " << student1.getAverageGrade() << std::endl;
    std::cout << student2.getName() << "'s average: " << student2.getAverageGrade() << std::endl;
    std::cout << "--------------------------------\n";

    PrintResult("name", CompareName(student1, student2), student1, student2);
    PrintResult("math", CompareMath(student1, student2), student1, student2);
    PrintResult("english", CompareEnglish(student1, student2), student1, student2);
    PrintResult("history", CompareHistory(student1, student2), student1, student2);
    PrintResult("average", CompareAverage(student1, student2), student1, student2);

    return 0;
}