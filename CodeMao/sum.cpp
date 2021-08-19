#include <iostream>
#include <stdio.h>

using namespace std;

const int maxN = 1e5;
int num[maxN] = {0};
int c[maxN] = {0};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        // cin >> num[i];
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < n; i++) {
        // cin >> c[i];
        scanf("%d", &c[i]);
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j += 2) {
            if (c[i] == c[j]) {
                result += ((i + j + 2) * (num[i] + num[j])) % 10007;
                result %= 10007;
            }
        }
    }

    // cout << result << endl;
    printf("%lld\n", result);

    return 0;
}