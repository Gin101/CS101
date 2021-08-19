#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxBox = 601;
int box[maxBox] = {0};

int main()
{

    int n = 0;
    int w = 0;
    cin >> n >> w;
    
    for (int i = 0; i < n; i++) {
        int score = 0;
        cin >> score;
        box[score]++;

        int num = max(1, (i + 1) * w / 100);
        for (int j = 600; j >= 0; j--) {
            num -= box[j];
            if (num <= 0) {
                cout << j << ' ';
                break;
            }
        }
    }
    
    cout << endl;

    return 0;
}