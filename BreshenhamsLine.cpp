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

    while(x < x2)
    {
       if(p >= 0)
       {
           p = p + 2*(dy - dx);
           y = y + 1;
       }
       else
       {
           p = p + (2*dy);
           y = y;
       }
       putpixel(x, y, RED);
        x++;

        delay(10);
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
    setbkcolor(WHITE);
    cleardevice();
    

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



/* Algorithm of Bresenham’s Line Drawing Algorithm
==================================================
Step 1: Start.

Step 2: Now, we consider Starting point as (x1, y1) and endingpoint (x2, y2).

Step 3: Now, we have to calculate ?x and ?y.

              ?x = x2-x1

                    ?y = y2-y1

              m = ?y/?x               

Step 4: Now, we will calculate the decision parameter pk with following formula.

                       pk = 2?y-?x

Step 5: Theinitial coordinates of the line are (xk, yk), and the next coordinatesare (xk+1, yk+1). Now, we are going to calculate two cases for decision parameter pk

 Case 1:  If pk < 0

              Then

                pk+1 =pk +2?y

                xk+1 = xk +1

                yk+1 = yk                           

Case 2:  If pk >= 0

              Then

                pk+1 =pk +2?y-2?x

                xk+1 =xk +1

                yk+1 =yk +1                          

Step 6: We will repeat step 5 until we found the ending point of the line and the total number of iterations =?x-1.

Step 7: Stop. */