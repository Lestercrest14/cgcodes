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
    int P[2][2] = {{100, 100}, {200, 200}};
    int T1[] = {25, 0};
    int T2[] = {75, 0};
    int T3[] = {150, 0};
    
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C://TURBOC3//bgi");
    setbkcolor(WHITE);
    
    drawLine(P, BLUE);
    
    translateLine(P, T1);
    drawLine(P, RED);
    
    translateLine(P, T2);
    drawLine(P, CYAN);
    
    translateLine(P, T3);
    drawLine(P, GREEN);
    
    getch();
    closegraph();
}
