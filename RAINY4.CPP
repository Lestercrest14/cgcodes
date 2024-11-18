#include <stdlib.h>
#include <conio.h>
#include <dos.h>      // Include this for delay() function
#include <graphics.h>

#define screenwidth getmaxx()
#define screenheight getmaxy()
#define groundY screenheight * 0.75

void drawUmbrella(int x) {
    pieslice(x + 15, groundY - 120, 0, 180, 40);
    line(x + 15, groundY - 120, x + 15, groundY - 60);
}

void drawRain() {
    int rx, ry;
    for (int i = 0; i < 500; i++) {
        rx = rand() % screenwidth;
        ry = rand() % screenheight;
        if (ry < groundY - 120 || (rx < 20 || rx > screenwidth - 20)) {
            line(rx, ry, rx + 1, ry + 5);
        }
    }
}

void drawMan(int x, int legs_displacement) {
    circle(x, groundY - 90, 10);  // Head
    line(x, groundY - 80, x, groundY - 30);  // Body
    line(x, groundY - 70, x + 15, groundY - 60);  // Right arm
    line(x, groundY - 70, x - 15, groundY - 60);  // Left arm
    line(x, groundY - 30, x + 15 - legs_displacement, groundY - 10);  // Right leg
    line(x, groundY - 30, x - 15 + legs_displacement, groundY - 10);  // Left leg
}

void main() {
    int gd = DETECT, gm, x = 0, legs_displacement = 0;
    initgraph(&gd, &gm, "C://TURBOC3//BGI");
    setbkcolor(WHITE);
    setcolor(BLUE);

    while (!kbhit()) {
        line(0, groundY, screenwidth, groundY);  // Draw the ground
        drawRain();  // Draw rain
        legs_displacement = (legs_displacement + 2) % 20;  // Animate legs
        drawMan(x, legs_displacement);  // Draw the man
        drawUmbrella(x);  // Draw the umbrella
        delay(75);  // Wait before clearing screen
        cleardevice();  // Clear screen
        x = (x + 2) % screenwidth;  // Move man and umbrella
    }

    closegraph();
}
