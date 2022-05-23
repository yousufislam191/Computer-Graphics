#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include <math.h>

using namespace std;

void DDA(int x0, int x1, int y0, int y1) {
    float dx = abs(x1 - x0);
    float dy = abs(y1 - y0);

    float x, y, steps;

    if(dx >= dy) {
        steps = dx;
    }
    else {
        steps = dy;
    }

    dx = dx/steps;  
    dy = dy/steps;  
    x = x0;  
    y = y0;

    for (int i = 0; i <= steps; i++)
    {
        putpixel(x, y, WHITE);
        x += dx;  
        y += dy; 
    }
    
}

void checkCondition(int x1, int x2, int y1, int y2) {
    if(x1 < x2) {
        DDA(x1, x2, y1, y2);
    }
    else {
        float temp = x1;
        x1 = x2;
        x2 = temp;

        cout << x1;
        cout << x2;

        DDA(x1, x2, y1, y2);
    }
}

int main()
{
    int gdriver=DETECT, gmode;
    initgraph(&gdriver, &gmode, " ");
    

    int x0, x1, y0, y1;

    cout <<"Enter co-ordinates of first point x0 & y0: ";
    cin >> x0 >> y0;

    cout <<"Enter co-ordinates of second point x1 & y1: ";
    cin >> x1 >> y1;

    checkCondition(x0, x1, y0, y1);

    
    getch();
    closegraph();
    return 0;
}