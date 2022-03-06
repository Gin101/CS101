#include <iostream>

using namespace std;

const int maxNum = 1040;
int knr[maxNum] = {0};
int knc[maxNum] = {0};

int main()
{
    int r = 0;
    int c = 0;
    cin >> r >> c;

    char c;
    int kr = 0;// the king's row
    int kc = 0;// the king's col
    cin >> c >> kc;
    kr = c - 'A';
    kc--;

    int idx = 0;
    while (cin >> c >> knc[idx]) {
        knr[idx++] = c - 'A';
    }

    

    return 0;
}