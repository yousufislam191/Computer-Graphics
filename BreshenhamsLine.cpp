#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

using namespace std;

void breshenhamsLine(float x1, float x2, float y1, float y2)
{
    float dx, dy, p, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    x = x1;
    y = y1;

    p = (2*dy) - dx;

    while(x1 < x2)
    {
       if(p >= 0)
       {
           putpixel(x, y, RED);
           p = p + 2*(dy - dx);
           y = y + 1;
       }
       else
       {
           putpixel(x, y, RED);
           p = p + 2*dy;
           y = y;
       }
        x = x + 1;
    }
}

void checkCondition(float x1, float x2, float y1, float y2) {
    if(x1 < x2) {
        breshenhamsLine(x1, x2, y1, y2);
    }
    else {
        float temp = x1;
        x1 = x2;
        x2 = temp;

        // cout << x1;
        // cout << x2;

        breshenhamsLine(x1, x2, y1, y2);
    }
}

int main()
{
    int gdriver=DETECT, gmode;
    initgraph(&gdriver, &gmode, " ");
    

    float x1, x2, y1, y2;

    cout <<"Enter co-ordinates of first point x1 & y1: ";
    cin >> x1 >> y1;

    cout <<"Enter co-ordinates of second point x2 & y2: ";
    cin >> x2 >> y2;

    checkCondition(x1, x2, y1, y2);

    
    getch();
    closegraph();
    return 0;
}
