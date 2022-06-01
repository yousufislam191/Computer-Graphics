#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <string.h>

using namespace std;

void EightPlot(float xc, float yc, int x, float y)
{
    putpixel(x + xc, y + yc, RED);
    putpixel(x + xc, -y + yc, YELLOW);
    putpixel(-x + xc, -y + yc, GREEN);
    putpixel(-x + xc, y + yc, YELLOW);
    putpixel(y + xc, x + yc, BLUE);
    putpixel(y + xc, -x + yc, RED);
    putpixel(-y + xc, -x + yc, 15);
    putpixel(-y + xc, x + yc, 6);
}

void MidPointCircle(float xc, float yc, float r)
{
    int x = 0;
    float y = r;

    float p = 1 - r;
    // float p = (5 / 4) - r;

    while (x <= y)
    {
        if (p < 0)
        {
            p = p + (2 * x) + 3;
            y = y;
        }
        else
        {
            p = p + 2 * (x - y) + 5;
            y--;
        }
        EightPlot(xc, yc, x, y);
        x++;

        delay(2);
    }
}

int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, " ");

    float xc, yc, r;

    cout << "Enter the center values of xc and yc: ";
    cin >> xc >> yc;

    cout << "Enter the value of radius: ";
    cin >> r;

    MidPointCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}