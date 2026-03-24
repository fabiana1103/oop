#include <iostream>
#include <cstdio>
#include "Number.h"

int main()
{
    Number n1("10110010", 2);
    Number n2("734", 8);
    Number n3("FF", 16);

    printf("n1 are %d cifre si e scris in baza %d\n", n1.GetDigitsCount(), n1.GetBase());
    for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
    {
        printf("n1[%d]=%c\n", tr, n1[tr]);
    }

    n1.Print();
    n2.Print();
    n1 = (n2 + n3 - n1) + n1;
    n1.SwitchBase(2);
    n1.Print();

    if (n1 > n2) printf("n1 e mai mare decat n2\n");
    else printf("n2 e mai mare decat n1\n");

    Number n4 = 12345;
    n1 = 255;
    n4 += n1;
    n4.Print();

    n4 = "13579";
    n4.Print();
    --n4;
    n4.Print();
    n4--;
    n4.Print();

    return 0;
}