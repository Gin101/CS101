#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

const int maxN = 10;
long long a[maxN][maxN] = {{0}};
int r[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int c[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row[maxN * maxN] = {0};
int col[maxN * maxN] = {0};

int main()
{
    long long n = 0;
    cin >> n;

    long long maxA = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j] - 48;
            if (maxA < a[i][j]) {
                maxA = a[i][j];
            } 
        }
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == maxA) {
                row[idx] = i;
                col[idx++] = j;
            }
        }
    }

    long long result = 0;
    for (int k = 0; k < idx; k++) {
        for (int i = 0; i < 8; i++) {
            long long tmp = maxA * pow(10, n - 1);
            int nr = row[k];
            int nc = col[k];
            for (long long j = 1; j < n; j++) {
                nr += r[i];
                nc += c[i];
                if (nr < 0) {
                    nr += n;
                } 
                if (nr >= n) {
                    nr -= n;
                }
                if (nc < 0) {
                    nc += n;
                }
                if (nc >= n) {
                    nc -= n;
                }
                tmp += a[nr][nc] * pow(10, n - 1 - j);
            }
            result = max(result, tmp);
        }
    }

    cout << result << endl;

    return 0;
}