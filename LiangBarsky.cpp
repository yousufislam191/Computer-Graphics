#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

void liangBarsky(int xmin, int ymin, int xmax, int ymax, int x1, int x2, int y1, int y2)
{
    setcolor(RED);
    rectangle(xmin, ymin, xmax, ymax);
    line(x1, y1, x2, y2);

    int dx = x2 - x1;
    int dy = y2 - y1;

    int p[4], q[4];

    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;
    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;

    float t1, t2, t[4];

    for (int i = 0; i < 4; i++)
    {
        if (p[i] != 0)
        {
            t[i] = (float)q[i] / p[i];
        }
        else
        {
            if (p[i] == 0 && q[i] < 0)
            {
                cout << "line completely outside the window";
            }
            else
            {
                if (p[i] == 0 && q[i] >= 0)
                {
                    cout << "line completely inside the window";
                }
            }
        }
    }

    if (t[0] > t[2])
    {
        t1 = t[0];
    }
    else
    {
        t1 = t[2];
    }
    if (t[1] < t[3])
    {
        t2 = t[1];
    }
    else
    {
        t2 = t[3];
    }
    if (t1 < t2)
    {
        int xx1, yy1, xx2, yy2;
        xx1 = x1 + t1 * dx;
        xx2 = x1 + t2 * dx;
        yy1 = y1 + t1 * dy;
        yy2 = y1 + t2 * dy;
        cout << "line after clipping:";
        setcolor(WHITE);
        line(xx1, yy1, xx2, yy2);
    }
    else
    {
        cout << "line lies out of the window";
    }
}

void checkCondition(int x1, int x2, int y1, int y2)
{
    if (x1 < x2)
    {
        int xmax, xmin, ymax, ymin;

        cout << "Enter the lower co-ordinates of window xmin & ymin: ";
        cin >> xmin >> ymin;

        cout << "Enter the upper co-ordinates of window xmax & ymax.\nand must be greater than xmin and ymin: ";
        cin >> xmax >> ymax;

        liangBarsky(xmin, ymin, xmax, ymax, x1, x2, y1, y2);
    }
    else
    {
        float temp = x1;
        x1 = x2;
        x2 = temp;

        // cout << x1;
        // cout << x2;

        int xmax, xmin, ymax, ymin;

        cout << "Enter the lower co-ordinates of window xmin & ymin: ";
        cin >> xmin >> ymin;

        cout << "Enter the upper co-ordinates of window xmax & ymax: ";
        cin >> xmax >> ymax;

        liangBarsky(xmin, ymin, xmax, ymax, x1, x2, y1, y2);
    }
}

int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, " ");

    int x1, y1, x2, y2;

    cout << "Enter co-ordinates of first point x0 & y0: ";
    cin >> x1 >> y1;

    cout << "Enter co-ordinates of second point x1 & y1: ";
    cin >> x2 >> y2;

    checkCondition(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}