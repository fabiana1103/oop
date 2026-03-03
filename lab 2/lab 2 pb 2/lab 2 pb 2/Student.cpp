#include "Student.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstring> 

Student::Student()
{
    strncpy(name, "unknown", sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0'; 

    MathGrade = 1.0f;
    EnglishGrade = 1.0f;
    HistoryGrade = 1.0f;
}

void Student::setName(const char* studentName)
{
    strncpy(name, studentName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

const char* Student::getName() const
{
    return name;
}

void Student::setMathGrade(float grade)
{
    if (grade >= 1.0f && grade <= 10.0f) {
        MathGrade = grade;
    }
}

float Student::getMathGrade() const
{
    return MathGrade;
}

void Student::setEnglishGrade(float grade)
{
    if (grade >= 1.0f && grade <= 10.0f) {
        EnglishGrade = grade;
    }
}

float Student::getEnglishGrade() const
{
    return EnglishGrade;
}

void Student::setHistoryGrade(float grade)
{
    if (grade >= 1.0f && grade <= 10.0f) {
        HistoryGrade = grade;
    }
}

float Student::getHistoryGrade() const
{
    return HistoryGrade;
}

float Student::getAverageGrade() const
{
    return (MathGrade + EnglishGrade + HistoryGrade) / 3.0f;
}