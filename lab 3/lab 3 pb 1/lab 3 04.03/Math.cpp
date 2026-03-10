#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <stdarg.h>
#include <string.h>

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return a + b;
}

int Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return a * b;
}

int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...) // int Math::Add(int count, int arr[])
{
	int sum = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
		sum = sum + va_arg(args, int); // sum=sum+arr[i];
	va_end(args);
	return sum;
}

char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr) return nullptr;
	if (b == nullptr) return nullptr;

	int length = strlen(a) + strlen(b) + 1;

	char* c = new char[length];

	strcpy(c, a);
	strcat(c, b); 

	return c;
}