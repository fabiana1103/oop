#pragma once

class Student 
{
private:
	int varsta;
	char* nume;
	int nota_oop;
	int nota_mate;
	int nota_logica;

	void SetVarsta(int varsta);
public:
	int GetVarsta();

	student();
	student(char* nume);
};
