#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

using namespace std;

void EightPlot(float xc, float yc, int x, float y) {
    putpixel(x+xc,y+yc,RED);  
    putpixel(x+xc,-y+yc,YELLOW);  
    putpixel(-x+xc,-y+yc,GREEN);  
    putpixel(-x+xc,y+yc,YELLOW);  
    putpixel(y+xc,x+yc,BLUE);  
    putpixel(y+xc,-x+yc,RED);  
    putpixel(-y+xc,-x+yc,15);  
    putpixel(-y+xc,x+yc,6);
}

void BresenhamCircle(float xc, float yc, float r) {
    int x=0;
    float y=r, d= 3-(2*r);
    EightPlot(xc, yc, x, y);

    while(x<=y) {
        if(d < 0) {
            d = d+(4*x)+6;
            y = y;
        }
        else {
            d = d+(4*(x-y))+10;
            y = y-1;
        }
        x = x+1;
        EightPlot(xc, yc, x, y);
    }
}


int main()
{
    int gdriver=DETECT, gmode;
    initgraph(&gdriver, &gmode, " ");
    

    float xc, yc, r;

    cout <<"Enter the values of xc and yc: ";
    cin >> xc >> yc;

    cout <<"Enter the value of radius: ";
    cin >> r;

    BresenhamCircle(xc, yc, r);

    
    getch();
    closegraph();
    return 0;
}





/* Bresenham's Circle Algorithm:
================================
Step1: Start Algorithm

Step2: Declare p, q, x, y, r, d variables
        p, q are coordinates of the center of the circle
        r is the radius of the circle

Step3: Enter the value of r

Step4: Calculate d = 3 - 2r

Step5: Initialize       x=0
          &nbsy= r

Step6: Check if the whole circle is scan converted
            If x > = y
            Stop

Step7: Plot eight points by using concepts of eight-way symmetry. The center is at (p, q). Current active pixel is (x, y).
                putpixel (x+p, y+q)
                putpixel (y+p, x+q)
                putpixel (-y+p, x+q)
                putpixel (-x+p, y+q)
                putpixel (-x+p, -y+q)
                putpixel (-y+p, -x+q)
                putpixel (y+p, -x+q)
                putpixel (x+p, -y-q)

Step8: Find location of next pixels to be scanned
            If d < 0
            then d = d + 4x + 6
            increment x = x + 1
            If d ≥ 0
            then d = d + 4 (x - y) + 10
            increment x = x + 1
            decrement y = y - 1

Step9: Go to step 6

Step10: Stop Algorithm */