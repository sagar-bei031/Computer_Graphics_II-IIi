#include "LineClipper.hpp"

// Calculate region code for a point (x, y)
int LineClipper::calculateCode(int x, int y, int x_min, int x_max, int y_min, int y_max)
{
    int code = INSIDE;

    if (x < x_min)
        code |= LEFT;
    else if (x > x_max)
        code |= RIGHT;
    if (y < y_min)
        code |= TOP;
    else if (y > y_max)
        code |= BOTTOM;

    return code;
}

using namespace LineClipper;

// Cohen-Sutherland line clipping algorithm
bool clipLine(int &x0, int &y0, int &x1, int &y1, int x_min, int x_max, int y_min, int y_max)
{
    int code0 = calculateCode(x0, y0, x_min, x_max, y_min, y_max);
    int code1 = calculateCode(x1, y1, x_min, x_max, y_min, y_max);
    bool accept = false;

    while (true)
    {
        if (!(code0 | code1))
        { // Trivially accepted
            accept = true;
            break;
        }
        else if (code0 & code1)
        { // Trivially rejected
            break;
        }
        else
        {
            int x, y;
            int codeOut = (code0 != 0) ? code0 : code1;

            // Find intersection point
            if (codeOut & TOP)
            {
                x = x0 + (x1 - x0) * (y_min - y0) / (y1 - y0);
                y = y_min;
            }
            else if (codeOut & BOTTOM)
            {
                x = x0 + (x1 - x0) * (y_max - y0) / (y1 - y0);
                y = y_max;
            }
            else if (codeOut & RIGHT)
            {
                y = y0 + (y1 - y0) * (x_max - x0) / (x1 - x0);
                x = x_max;
            }
            else if (codeOut & LEFT)
            {
                y = y0 + (y1 - y0) * (x_min - x0) / (x1 - x0);
                x = x_min;
            }

            if (codeOut == code0)
            {
                x0 = x;
                y0 = y;
                code0 = calculateCode(x0, y0, x_min, x_max, y_min, y_max);
            }
            else
            {
                x1 = x;
                y1 = y;
                code1 = calculateCode(x1, y1, x_min, x_max, y_min, y_max);
            }
        }
    }

    return accept;
}