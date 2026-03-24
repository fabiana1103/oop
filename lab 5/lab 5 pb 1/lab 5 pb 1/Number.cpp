#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <cstring>
#include <cstdio>

long long Number::ConvLaBaza10() const {
    long long rez = 0;
    long long putere = 1;
    int lungime = strlen(valoare);

    for (int i = lungime - 1; i >= 0; i--) {
        int cifra = 0;
        if (valoare[i] >= '0' && valoare[i] <= '9') cifra = valoare[i] - '0';
        else if (valoare[i] >= 'A' && valoare[i] <= 'F') cifra = valoare[i] - 'A' + 10;
        else if (valoare[i] >= 'a' && valoare[i] <= 'f') cifra = valoare[i] - 'a' + 10;

        rez += cifra * putere;
        putere *= this->baza;
    }
    return rez;
}

void Number::SeteazaDinBaza10(long long v, int bazaNoua) {
    if (this->valoare != nullptr) {
        delete[] this->valoare;
    }

    this->baza = bazaNoua;

    if (v == 0) {
        this->valoare = new char[2];
        strcpy(this->valoare, "0");
        return;
    }

    char temp[100];
    int poz = 0;

    while (v > 0) {
        int rest = v % bazaNoua;
        if (rest < 10) temp[poz++] = rest + '0';
        else temp[poz++] = rest - 10 + 'A';
        v /= bazaNoua;
    }

    this->valoare = new char[poz + 1];
    for (int i = 0; i < poz; i++) {
        this->valoare[i] = temp[poz - 1 - i];
    }
    this->valoare[poz] = '\0';
}

Number::Number(const char* val, int b) {
    this->baza = b;
    this->valoare = new char[strlen(val) + 1];
    strcpy(this->valoare, val);
}

Number::Number(int val) {
    this->baza = 10;
    this->valoare = nullptr;
    SeteazaDinBaza10(val, 10);
}

Number::~Number() {
    delete[] valoare;
}

Number::Number(const Number& obj) {
    this->baza = obj.baza;
    this->valoare = new char[strlen(obj.valoare) + 1];
    strcpy(this->valoare, obj.valoare);
}

Number::Number(Number&& obj) {
    this->valoare = obj.valoare;
    this->baza = obj.baza;

    obj.valoare = nullptr;
    obj.baza = 0;
}

Number& Number::operator=(const Number& obj) {
    if (this != &obj) {
        delete[] this->valoare;
        this->baza = obj.baza;
        this->valoare = new char[strlen(obj.valoare) + 1];
        strcpy(this->valoare, obj.valoare);
    }
    return *this;
}

Number& Number::operator=(Number&& obj) {
    if (this != &obj) {
        delete[] this->valoare;
        this->valoare = obj.valoare;
        this->baza = obj.baza;

        obj.valoare = nullptr;
    }
    return *this;
}

Number& Number::operator=(int val) {
    SeteazaDinBaza10(val, this->baza);
    return *this;
}

Number& Number::operator=(const char* str) {
    delete[] this->valoare;
    this->valoare = new char[strlen(str) + 1];
    strcpy(this->valoare, str);
    return *this;
}

Number operator+(const Number& n1, const Number& n2) {
    int bMax = (n1.baza > n2.baza) ? n1.baza : n2.baza;
    long long v1 = n1.ConvLaBaza10();
    long long v2 = n2.ConvLaBaza10();

    Number rez("0", bMax);
    rez.SeteazaDinBaza10(v1 + v2, bMax);
    return rez;
}

Number operator-(const Number& n1, const Number& n2) {
    int bMax = (n1.baza > n2.baza) ? n1.baza : n2.baza;
    long long v1 = n1.ConvLaBaza10();
    long long v2 = n2.ConvLaBaza10();

    Number rez("0", bMax);
    rez.SeteazaDinBaza10(v1 - v2, bMax);
    return rez;
}

Number& Number::operator+=(const Number& obj) {
    long long v1 = this->ConvLaBaza10();
    long long v2 = obj.ConvLaBaza10();
    int bMax = (this->baza > obj.baza) ? this->baza : obj.baza;

    SeteazaDinBaza10(v1 + v2, bMax);
    return *this;
}

Number& Number::operator--() {
    int lungime = strlen(this->valoare);
    if (lungime > 0) {
        for (int i = 0; i < lungime; i++) {
            this->valoare[i] = this->valoare[i + 1];
        }
    }
    return *this;
}

Number Number::operator--(int) {
    Number copie = *this;
    int lungime = strlen(this->valoare);
    if (lungime > 0) {
        this->valoare[lungime - 1] = '\0';
    }
    return copie;
}

char Number::operator[](int index) const {
    if (index >= 0 && index < strlen(this->valoare)) {
        return this->valoare[index];
    }
    return '\0';
}

bool operator>(const Number& n1, const Number& n2) { return n1.ConvLaBaza10() > n2.ConvLaBaza10(); }
bool operator<(const Number& n1, const Number& n2) { return n1.ConvLaBaza10() < n2.ConvLaBaza10(); }
bool operator>=(const Number& n1, const Number& n2) { return n1.ConvLaBaza10() >= n2.ConvLaBaza10(); }
bool operator<=(const Number& n1, const Number& n2) { return n1.ConvLaBaza10() <= n2.ConvLaBaza10(); }
bool operator==(const Number& n1, const Number& n2) { return n1.ConvLaBaza10() == n2.ConvLaBaza10(); }
bool operator!=(const Number& n1, const Number& n2) { return n1.ConvLaBaza10() != n2.ConvLaBaza10(); }

void Number::SwitchBase(int newBase) {
    long long v10 = ConvLaBaza10();
    SeteazaDinBaza10(v10, newBase);
}

void Number::Print() {
    printf("%s\n", this->valoare);
}

int Number::GetDigitsCount() {
    return strlen(this->valoare);
}

int Number::GetBase() {
    return this->baza;
}