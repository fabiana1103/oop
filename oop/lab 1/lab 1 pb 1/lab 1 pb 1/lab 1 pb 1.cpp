#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int functie(const char* s)
{
    int res = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        res = res * 10 + (s[i] - '0');
        i++;
    }
    return res;
}

int main()
{
    int sum = 0, y;
    char x[100];
    FILE* fin = fopen("in.txt", "r");
    if (fin == NULL) {
        printf("nu exista fisierul\n");
        return 1;
    }
    while (fscanf(fin, "%99s", x) == 1)
    {
        y = functie(x);
        sum = sum + y;
    }
    printf("%d\n", sum);
    fclose(fin);
    return 0;
}