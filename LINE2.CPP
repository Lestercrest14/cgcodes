#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C://TURBOC3//BGI");
    setbkcolor(WHITE);
    
    for (int x = 0; x < 125; x++) {
        putpixel(25 + x, 25 + x, RED);
    }
    
    getch();
    closegraph();
}
