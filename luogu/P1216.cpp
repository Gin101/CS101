#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxR = 1000;
int number[maxR][maxR] = {{0}};

int main()
{
    int r = 0;
    cin >> r;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> number[i][j];
        }
    }

    for (int i = r - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            number[i][j] += max(number[i + 1][j], number[i + 1][j + 1]); 
        }
    }

    cout << number[0][0] << endl;


    return 0;
}