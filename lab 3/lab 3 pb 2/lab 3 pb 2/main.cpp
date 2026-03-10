#include <iostream>
#include "Canvas.h"

int main()
{
    Canvas canvas(60, 30);
    canvas.DrawRect(2, 2, 20, 10, 'a');
    canvas.FillRect(30, 5, 35, 10, '+');
    canvas.SetPoint(30, 15, '.');
    canvas.DrawLine(2, 12, 20, 25, '-');
    canvas.DrawCircle(10, 20, 5, '#');
    canvas.FillCircle(45, 20, 6, '*');
    canvas.Print();
    canvas.Clear();
    canvas.SetPoint(5, 5, '|');
    canvas.Print();

    return 0;
}