#include <conio.h>
#include <graphics.h>

void main() {
    // Initialize graphics library
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C://TURBOC3//BGI");

    // Set background color to white
    setbkcolor(15);

    // Draw 4 pixels on the screen with red color
    putpixel(25, 25, RED);
    putpixel(30, 25, RED);
    putpixel(35, 25, RED);
    putpixel(40, 25, RED);

    // Wait for user input
    getch();

    // Close the graphics mode
    closegraph();
}
