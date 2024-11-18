#include <graphics.h>
#include <conio.h>
#include <iostream.h>

void dda(int xi, int yi, int xf, int yf) {
    int dx = xf - xi;
    int dy = yf - yi;
    float m = (float)dy / dx;
    float x = xi, y = yi;
    putpixel(x, y, RED);

    if (m <= 1) {
        while (x < xf) {
            x++;
            y += m;
            putpixel((int)x, (int)y, RED);
        }
    } else {
        while (y <= yf) {
            x += (1 / m);
            y++;
            putpixel((int)x, (int)y, RED);
        }
    }
}

void main() {
    int gd = DETECT, gm, xi, yi, xf, yf;
    initgraph(&gd, &gm, "C://TURBOC3//bgi");

    cout << "Enter value of xi, yi: ";
    cin >> xi >> yi;
    cout << "\nEnter value of xf, yf: ";
    cin >> xf >> yf;

    setbkcolor(WHITE);
    dda(xi, yi, xf, yf);

    getch();
    closegraph();
}
