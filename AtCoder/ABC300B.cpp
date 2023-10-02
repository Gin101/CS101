#include <iostream>

using namespace std;

const int maxH = 30;
const int maxW = 30;
char a[maxH][maxW];
char b[maxH][maxW];
int HA[maxH] = {0};
int WA[maxW] = {0};
int HB[maxH] = {0};
int WB[maxW] = {0};

int main()
{   
    int h = 0;
    int w = 0;
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                HA[i]++;
                WA[j]++;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> b[i][j];
            if (b[i][j] == '#') {
                HB[i]++;
                WB[j]++;
            }
        }
    }

    bool result = false;
    for (int i = 0; i < w; i++) {
        bool flag = true;
        for (int j = 0; j < w; j++) {
            if (WA[j] != WB[j]) {   
                flag = false;
                break;
            }
        }

        if (flag) {
            result = true;
            break;
        }

        int tmp = WA[0];
        for (int j = 0; j < w - 1; j++) {
            WA[j] = WA[j + 1];
        }
        WA[w - 1] = tmp;
    }

    bool result2 = false;
    for (int i = 0; i < h; i++) {
        bool flag = true;
        for (int j = 0; j < h; j++) {
            if (HA[j] != HB[j]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            result2 = true;
            break;
        }

        int tmp = HA[0];
        for (int j = 0; j < h - 1; j++) {
            HA[j] = HA[j + 1];
        }
        HA[h - 1] = tmp;
    }

    if (result && result2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}