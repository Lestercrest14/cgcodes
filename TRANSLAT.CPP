#include <graphics.h>
#include <conio.h>

void drawLine(int P[][2], int color) {
    setcolor(color);
    line(P[0][0], P[0][1], P[1][0], P[1][1]);
}

void translateLine(int P[][2], int T[]) {
    P[0][0] = P[0][0] + T[0];
    P[0][1] = P[0][1] + T[1];
    P[1][0] = P[1][0] + T[0];
    P[1][1] = P[1][1] + T[1];
}

void main() {
    int P[2][2] = {{100, 100}, {200, 200}}; // Define points
    int T[] = {100, 10}; // Translation vector
    
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C://TURBOC3//bgi");
    setbkcolor(WHITE);
    
    drawLine(P, BLUE);  // Draw original line in blue
    translateLine(P, T); // Translate the line
    drawLine(P, RED);   // Draw translated line in red
    
    getch();
    closegraph();
}

