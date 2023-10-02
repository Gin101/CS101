#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int maxNM = 1000;
int number[maxNM][maxNM] = {{0}};
int cache[maxNM][maxNM] = {{0}};

int main()
{
    // freopen("P7074.in", "r", stdin);

    int n = 0;
    int m = 0;  
    cin >> n >> m;
    for(int i = 0; i < n ; i++) {
        for (int j = 0; j < m; j++) {
            cin >> number[i][j];
        }
    }

    cache[0][0] = number[0][0];
    for(int i = 1;i < n; i++) {
        cache[i][0] = cache[i - 1][0] + number[i][0];
    }

    for(int i = 1; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cache[j][i] = cache[j][i - 1] + number[j][i];
            int tmp = number[j][i];
            for(int k = j + 1; k < n; k++) {
                tmp += number[k][i];
                cache[j][i] = max(cache[j][i], cache[k][i-1] + tmp);
            }
            tmp = number[j][i];
            for(int k = j - 1; k >= 0; k--) {
                tmp += number[k][i];
                cache[j][i] = max(cache[j][i], cache[k][i-1] + tmp);
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         printf("cache[%d][%d]: %d ", i, j, cache[i][j]);
    //     }
    //     cout << endl;
    // }

    cout << cache[n - 1][m - 1] << endl;

    return 0;
}