#include <iostream>
#include "Math.h"

int main()
{
    std::cout << "Add(int, int): " << Math::Add(5, 10) << std::endl;
    std::cout << "Add(int, int, int): " << Math::Add(5, 10, 15) << std::endl;

    std::cout << "Add(double, double): " << Math::Add(3.7, 4.2)  << std::endl;
    std::cout << "Add(double, double, double): " << Math::Add(1.5, 2.5, 3.5) << std::endl;

    std::cout << "Mul(int, int): " << Math::Mul(3, 4) << std::endl;
    std::cout << "Mul(int, int, int): " << Math::Mul(2, 3, 4) << std::endl;

    std::cout << "Mul(double, double): " << Math::Mul(2.5, 3.0) << std::endl;
    std::cout << "Mul(double, double, double): " << Math::Mul(1.5, 2.0, 3.0) << std::endl;

    std::cout << "Variadic Add(5 args): " << Math::Add(5, 10, 20, 30, 40, 50) << std::endl;

    const char* part1 = "sir ";
    const char* part2 = "adaugat";
    char* combinedString = Math::Add(part1, part2);

    if (combinedString != nullptr)
    {
        std::cout << "String Add: " << combinedString << std::endl;

        delete[] combinedString;
    }

    char* nullTest = Math::Add(part1, nullptr);
    if (nullTest == nullptr)
    {
        std::cout << "String Add with nullptr correctly returned nullptr." << std::endl;
    }

    return 0;
}