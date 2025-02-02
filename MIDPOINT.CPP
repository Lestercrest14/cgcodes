#include <graphics.h>
#include <conio.h>
#include <iostream.h>

void plotPixel(int x, int y, int Xcenter, int Ycenter) {
    putpixel(x + Xcenter, y + Ycenter, RED);
    putpixel(y + Xcenter, x + Ycenter, RED);
    putpixel(x + Xcenter, -y + Ycenter, RED);
    putpixel(-y + Xcenter, x + Ycenter, RED);
    putpixel(-x + Xcenter, y + Ycenter, RED);
    putpixel(y + Xcenter, -x + Ycenter, RED);
    putpixel(-x + Xcenter, -y + Ycenter, RED);
    putpixel(-y + Xcenter, -x + Ycenter, RED);
}

void drawcircle(int Xcenter, int Ycenter, int radius) {
    int x = 0, y = radius, P = 1 - radius;
    plotPixel(x, y, Xcenter, Ycenter);

    while (x <= y) {
        if (P < 0) {
            x++;
            P = P + 2 * x + 1;
        } else {
            x++;
            y--;
            P = P + 2 * x + 1 - 2 * y;
        }
        plotPixel(x, y, Xcenter, Ycenter);
    }
}

void main() {
    int gd = DETECT, gm, x, y, r;
    initgraph(&gd, &gm, "C://TURBOC3//bgi");

    cout << "Enter radius of circle: ";
    cin >> r;
    cout << "Enter coordinates of center(x and y): ";
    cin >> x >> y;

    setbkcolor(WHITE);
    drawcircle(x, y, r);

    getch();
    closegraph();
}

