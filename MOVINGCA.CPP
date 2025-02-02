#include <conio.h>
#include <graphics.h>
#include <dos.h>

#define screenheight getmaxy()
#define screenwidth getmaxx()

void drawCar(int displacement) {
    line(displacement, 300, 210 + displacement, 300);
    line(50 + displacement, 300, 75 + displacement, 270);
    line(75 + displacement, 270, 150 + displacement, 270);
    line(150 + displacement, 270, 165 + displacement, 300);
    line(displacement, 300, displacement, 330);
    line(210 + displacement, 300, 210 + displacement, 330);
    circle(65 + displacement, 330, 15);
    circle(65 + displacement, 330, 2);
    circle(145 + displacement, 330, 15);
    circle(145 + displacement, 330, 2);
    line(displacement, 330, 50 + displacement, 330);
    line(80 + displacement, 330, 130 + displacement, 330);
    line(210 + displacement, 330, 160 + displacement, 330);
}

void main() {
    int gd = DETECT, gm, i = 0;
    initgraph(&gd, &gm, "C://TURBOC3//bgi");
    setbkcolor(WHITE);
    setcolor(BLUE);

    while (!kbhit()) {
        drawCar(i);
        delay(50);
        cleardevice();
        i += 5;
        if (i > screenwidth) {
            i = -210;
        }
    }

    getch();
    closegraph();
}
