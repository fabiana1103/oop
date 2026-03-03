#include "Comparisons.h"
#include <cstring> 

int CompareName(const Student& s1, const Student& s2)
{
    int result = strcmp(s1.getName(), s2.getName());

    if (result == 0) return 0;
    if (result > 0) return 1;
    return -1;
}

int CompareMath(const Student& s1, const Student& s2)
{
    if (s1.getMathGrade() == s2.getMathGrade()) return 0;
    if (s1.getMathGrade() > s2.getMathGrade()) return 1;
    return -1;
}

int CompareEnglish(const Student& s1, const Student& s2)
{
    if (s1.getEnglishGrade() == s2.getEnglishGrade()) return 0;
    if (s1.getEnglishGrade() > s2.getEnglishGrade()) return 1;
    return -1;
}

int CompareHistory(const Student& s1, const Student& s2)
{
    if (s1.getHistoryGrade() == s2.getHistoryGrade()) return 0;
    if (s1.getHistoryGrade() > s2.getHistoryGrade()) return 1;
    return -1;
}

int CompareAverage(const Student& s1, const Student& s2)
{
    if (s1.getAverageGrade() == s2.getAverageGrade()) return 0;
    if (s1.getAverageGrade() > s2.getAverageGrade()) return 1;
    return -1;
}