#pragma once 

class Number
{
private:
    char* valoare;
    int baza;

    long long ConvLaBaza10() const;
    void SeteazaDinBaza10(long long v, int bazaNoua);

public:
    Number(const char* val, int b);
    Number(int val);
    ~Number();

    Number(const Number& obj);
    Number(Number&& obj);

    Number& operator=(const Number& obj);
    Number& operator=(Number&& obj);

    Number& operator=(int val);
    Number& operator=(const char* str);

    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);
    Number& operator+=(const Number& obj);

    char operator[](int index) const;

    Number& operator--();
    Number operator--(int);

    friend bool operator>(const Number& n1, const Number& n2);
    friend bool operator<(const Number& n1, const Number& n2);
    friend bool operator>=(const Number& n1, const Number& n2);
    friend bool operator<=(const Number& n1, const Number& n2);
    friend bool operator==(const Number& n1, const Number& n2);
    friend bool operator!=(const Number& n1, const Number& n2);

    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount();
    int  GetBase();
};