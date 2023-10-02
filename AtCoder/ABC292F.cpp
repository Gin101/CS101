#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    double a = 0;
    double b = 0;
    cin >> a >> b;

    printf("%.10lf\n", min(2.0 * sqrt(b * b - sqrt(3) * a * b + a * a), 2.0 * (double)min(a, b) / sqrt(3)));

    return 0;
}