#include <iostream>

using namespace std;

const int maxN = 100;
int num[maxN] = {0};
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int idx = 0;
    int result = 1;
    while (idx + num[idx] < n - 1) {
        int maxNum = 0;
        int maxIdx = 0;
        for (int i = 1; i <= num[idx]; i++) {
            if (i + num[i + idx] > maxNum) {
                maxNum = i + num[i + idx];
                maxIdx = i + idx;
            }
        }

        result++;
        idx = maxIdx;
    }

    cout << result << endl;

    return 0;
}