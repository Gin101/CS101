#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxBOX = 601;
int box[maxBOX] = {0};

int main()
{
    // freopen("P7072.in", "r", stdin);

    int n = 0;
    int w = 0;
    cin >> n >> w;
    
    for (int i = 0; i < n; i++) {
        int score = 0;
        cin >> score;
        box[score]++;

        int number = max(1, (i + 1) * w / 100);
        for (int j = 600; j >= 0; j--) {
            number -= box[j];
            if (number <= 0) {
                cout << j << ' ';
                break;
            }
        }
    }
    
    cout << endl;

    return 0;
}