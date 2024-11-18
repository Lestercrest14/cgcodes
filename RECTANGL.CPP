#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C://TURBOC3//BGI");

    setbkcolor(WHITE);

    for (int topx = 25; topx <= 150; topx++) {
        putpixel(topx, 25, RED);
    }

    for (int bottomx = 25; bottomx <= 150; bottomx++) {
        putpixel(bottomx, 225, RED);
    }

    for (int lefty = 25; lefty <= 225; lefty++) {
        putpixel(25, lefty, RED);
    }

    for (int righty = 25; righty <= 225; righty++) {
        putpixel(150, righty, RED);
    }

    getch();
    closegraph();
}
