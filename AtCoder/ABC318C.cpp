#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 2e5;
int f[maxN] = {0};

int main()
{
    int n = 0;
    int d = 0;
    int p = 0;
    cin >> n >> d >> p;

    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }  

    sort(f, f + n, greater<int>());

    int cnt = 0;
    long long sum = 0;
    long long result = 0;
    for (int i = 0; i < n; i++) {
        sum += f[i];
        cnt++;
        if (cnt == d || i == n - 1) {
            if (sum > p) {
                result += p;
            } else {
                result += sum;
            }
            sum = 0;
            cnt = 0;
        }
    }

    cout << result << endl;

    return 0;
}