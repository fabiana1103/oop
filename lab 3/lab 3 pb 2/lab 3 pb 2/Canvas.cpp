#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height) : width(width), height(height)
{
    matrix = new char* [height];
    for (int i = 0; i < height; ++i)
    {
        matrix[i] = new char[width];
        for (int j = 0; j < width; ++j)
        {
            matrix[i][j] = ' ';
        }
    }
}

Canvas::~Canvas()
{
    for (int i = 0; i < height; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Canvas::Clear()
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            matrix[i][j] = ' ';
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        matrix[y][x] = ch; 
    }
}

void Canvas::Print()
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cout << matrix[i][j];
        }
        std::cout << '\n';
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = std::abs(x2 - x1);
    int dy = -std::abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx + dy;
    int e2;

    while (true)
    {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;

        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    DrawLine(left, top, right, top, ch);       
    DrawLine(right, top, right, bottom, ch);  
    DrawLine(right, bottom, left, bottom, ch); 
    DrawLine(left, bottom, left, top, ch);     
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int y = top; y <= bottom; ++y)
    {
        for (int x = left; x <= right; ++x)
        {
            SetPoint(x, y, ch);
        }
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int cx = 0;
    int cy = ray;
    int d = 3 - 2 * ray;

    while (cy >= cx)
    {
        SetPoint(x + cx, y + cy, ch);
        SetPoint(x - cx, y + cy, ch);
        SetPoint(x + cx, y - cy, ch);
        SetPoint(x - cx, y - cy, ch);
        SetPoint(x + cy, y + cx, ch);
        SetPoint(x - cy, y + cx, ch);
        SetPoint(x + cy, y - cx, ch);
        SetPoint(x - cy, y - cx, ch);

        cx++;
        if (d > 0)
        {
            cy--;
            d = d + 4 * (cx - cy) + 10;
        }
        else
        {
            d = d + 4 * cx + 6;
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = x - ray; i <= x + ray; ++i)
    {
        for (int j = y - ray; j <= y + ray; ++j)
        {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
            {
                SetPoint(i, j, ch);
            }
        }
    }
}