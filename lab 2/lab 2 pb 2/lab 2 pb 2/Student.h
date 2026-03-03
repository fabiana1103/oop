#ifndef STUDENT_H
#define STUDENT_H

class Student
{
    char name[50];
    float MathGrade;
    float EnglishGrade;
    float HistoryGrade;

public:
    Student();

    void setName(const char* studentName);
    const char* getName() const;

    void setMathGrade(float grade);
    float getMathGrade() const;

    void setEnglishGrade(float grade);
    float getEnglishGrade() const;

    void setHistoryGrade(float grade);
    float getHistoryGrade() const;

    float getAverageGrade() const;
};

#endif 