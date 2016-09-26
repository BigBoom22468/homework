#include <stdio.h>
int main() {
    int x1, y1, x2, y2, x3, y3, x0, y0, c, d;
    scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x0, &y0);
    c = (((x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0)) * ((x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0)));
    d = (((x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0)) * ((x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0)));
    printf ("%d %d\n", c, d);
    if ((c > 0) && (d > 0)) {
        printf ("YES");
    }
    else {
        printf ("NO");
    }
    return 0;
}
