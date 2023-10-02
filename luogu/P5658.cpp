#include <iostream>
#include <string>

using namespace std;

const int maxN = 1e6;
int f[maxN] = {0};
int fr[maxN] = {0};
long long k[maxN] = {0};
int main() 
{
    int n = 0;
    string s;
    cin >> n >> s;

    fr[1] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> f[i];

        int &idx = fr[i];
        if (s[i - 1] == ')') {
            idx = fr[f[i]];
            while (fr[idx] != idx) {
                idx = fr[idx];
            }

            if (s[idx - 1] == '(') {
                k[i] = k[idx = f[idx]] + 1;
            } else {
                idx = i;
            }
        } else {
            idx = i;
        }
    }

    long long result = 0;
    for (int i = 1; i <= n; i++) {
        result ^= (k[i] += k[f[i]]) * i;
    }
    cout << result << endl;

    return 0;
}