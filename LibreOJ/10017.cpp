#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

double dis(double ax, double ay, double bx, double by) {
    return sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
}

const double INF = 0x3f3f3f3f;
double ax = 0;
double ay = 0;
double dx = 0;
double dy = 0;
double p = 0;
double q = 0;
double r = 0;
double mx = 0;
double my = 0;
double nx = 0;
double ny = 0;
double ope() {
    double tmp = dis(ax, ay, mx, my) / p;
    tmp += dis(mx, my, nx, ny) / r;
    tmp += dis(nx, ny, dx, dy) / q;
    return tmp;
}
int main() 
{
    double bx = 0;
    double by = 0;
    double cx = 0;
    double cy = 0;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy >> p >> q >> r;

    double result = INF;
    for (double i = 0; i <= 1; i += 0.0002) {
        mx = ax + (bx - ax) * i;
        my = ay + (by - ay) * i;
        for (double j = 0; j <= 1; j += 0.0002) {
            nx = cx + (dx - cx) * j;
            ny = cy + (dy - cy) * j;
            result = min(result, ope());
        }
    }

    printf("%.2lf\n", result);

    return 0;
}