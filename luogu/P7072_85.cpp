#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int maxN = 100000;
int number[maxN] = {0};
int old[maxN] = {0};
int result[maxN] = {0};
bool flag[maxN] = {false};

bool cmp(int x, int y) {
    return x > y;
}

int main()
{
    freopen("P7072.in", "r", stdin);

    int n = 0;
    int w = 0;
    cin >> n >> w;

    for (int i = 0; i < n; i++) {
        cin >> number[i];
        old[i] = number[i];
    }

    sort(number, number + n, cmp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (number[j] == old[i] && !flag[j]) {
                result[j] = number[j];
                flag[j] = true;
                break;
            }
        }

        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (flag[j]) {
                tmp++;
                if (tmp == max(1, (i + 1) * w / 100)) {
                    cout << result[j] << ' ';
                    break;
                }
            }
        }
    }

    cout << endl;

    return 0;
}