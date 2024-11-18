#include <graphics.h>
#include <conio.h>
#include <iostream.h>

#define TRUE 1
#define FALSE 0

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

const int x_max = 400;
const int y_max = 200;
const int x_min = 100;
const int y_min = 100;

int computeCode(double x, double y) {
    int code = INSIDE;
    if (x < x_min) {
        code = code | LEFT;
    } else if (x > x_max) {
        code = code | RIGHT;
    }
    if (y < y_min) {
        code = code | BOTTOM;
    } else if (y > y_max) {
        code = code | TOP;
    }
    return code;
}

void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int codel = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = FALSE;

    while (TRUE) {
        if ((codel == 0) && (code2 == 0)) {
            accept = TRUE;
            break;
        } else if (codel & code2) {
            break;
        } else {
            int code_out;
            int x, y;
            if (codel != 0) {
                code_out = codel;
            } else {
                code_out = code2;
            }

            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            if (code_out == codel) {
                x1 = x;
                y1 = y;
                codel = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    } else {
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C://TURBOC3//bgi");

    setbkcolor(WHITE);
    setcolor(BLUE);

    rectangle(x_min, y_min, x_max, y_max);

    cohenSutherlandClip(75, 75, 150, 150);
    cohenSutherlandClip(250, 50, 250, 250);
    cohenSutherlandClip(425, 110, 350, 190);

    getch();
    closegraph();
}
