#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

const int maxN = 1e4;
int stick[maxN] = {0};

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> stick[i];
    }

    int result = INT_MAX;
    for (int i = 0; i <= n - k; i++) {
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += stick[j];
        }

        sum /= k;
        int tmp = 0;
        for (int j = i; j < i + k; j++) {
            tmp += abs(sum - stick[j]);
        }

        sum++;
        int tmp2 = 0;
        for (int j = i; j < i + k; j++) {
            tmp2 += abs(sum - stick[j]);
        }
        tmp = min(tmp, tmp2);

        result = min(result, tmp);
    }

    cout << result << endl;

    return 0;
}