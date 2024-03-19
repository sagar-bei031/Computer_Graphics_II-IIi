#include "LineClipper.hpp"

// Calculate region code for a point (x, y)
int CSA::calculateCode(int x, int y, int x_min, int x_max, int y_min, int y_max)
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

// Cohen-Sutherland line clipping algorithm
bool CSA::clipLine(int &x1, int &y1, int &x2, int &y2, int x_min, int x_max, int y_min, int y_max)
{
    int code1 = calculateCode(x1, y1, x_min, x_max, y_min, y_max);
    int code2 = calculateCode(x2, y2, x_min, x_max, y_min, y_max);
    bool accept = false;

    while (true)
    {
        if (!(code1 | code2))
        { // Trivially accepted
            accept = true;
            break;
        }
        else if (code1 & code2)
        { // Trivially rejected
            break;
        }
        else
        {
            int x = 0, y = 0; // initialize 0 to remove gcc warrning [-Wmaybe-uninitialized]
            int codeOut = (code1 != 0) ? code1 : code2;

            // Find intersection point
            if (codeOut & TOP)
            {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (codeOut & BOTTOM)
            {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (codeOut & RIGHT)
            {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (codeOut & LEFT)
            {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            if (codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = calculateCode(x1, y1, x_min, x_max, y_min, y_max);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = calculateCode(x2, y2, x_min, x_max, y_min, y_max);
            }
        }
    }

    return accept;
}

// Liang-Barsky Line Clipping ALgorithm
bool LBA::clipLine(int &x1, int &y1, int &x2, int &y2, int x_min, int x_max, int y_min, int y_max)
{
    float t1 = 0, t2 = 1, dx = x2 - x1, dy = y2 - y1;

    // Calculate p and q values for each direction
    float p[] = {-dx, dx, -dy, dy};
    float q[] = {(float)(x1 - x_min), (float)(x_max - x1), (float)(y1 - y_min), (float)(y_max - y1)};

    // Traverse through each direction
    for (int i = 0; i < 4; i++)
    {
        if (p[i] == 0)
        {
            if (q[i] < 0)
                return false; // Line is parallel and outside the clipping window
        }
        else
        {
            float t = q[i] / p[i];
            if (p[i] < 0)
            {
                if (t > t1)
                    t1 = t;
            }
            else
            {
                if (t < t2)
                    t2 = t;
            }
        }
    }

    if (t1 > t2)
        return false; // Line segment lies completely outside the clipping window

    // Calculate new coordinates
    int new_x1 = x1 + t1 * dx;
    int new_y1 = y1 + t1 * dy;
    int new_x2 = x1 + t2 * dx;
    int new_y2 = y1 + t2 * dy;

    // Update the coordinates with clipped values
    x1 = new_x1;
    y1 = new_y1;
    x2 = new_x2;
    y2 = new_y2;

    return true; // Line segment lies partially or completely inside the clipping window
}