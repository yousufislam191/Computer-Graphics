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