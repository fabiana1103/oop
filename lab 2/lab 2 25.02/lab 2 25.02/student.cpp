#include <"student.h"> // include - se copie tot din student.h

int student::GetVarsta()
{
    return this->varsta; // return varsta; pt a evita ambiguitati
}

void student::SetVarsta(int varsta)
{
    this->varsta = varsta;
}

student::student(char* nume)