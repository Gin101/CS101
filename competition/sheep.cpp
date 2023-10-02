#include <iostream>
#include <string>

using namespace std;

const int maxN = 2e5 + 1;
int pre[maxN][26] = {{0}};

int main()
{
    int n = 0;
    int m = 0;
    string s;
    cin >> n >> m >> s;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            if (j + 97 != (int)s[i - 1]) {
                pre[i][j] = pre[i - 1][j];
            } else {
                pre[i][j] = pre[i - 1][j] + 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int l = 0;
        int r = 0;
        pair<char, char> pa;
        cin >> l >> r >> pa.first >> pa.second;

        if (pa.first == pa.second) {
            cout << (pre[r][(int)pa.first - 97] - pre[l - 1][(int)pa.first - 97]) * (pre[r][(int)pa.second - 97] - pre[l - 1][(int)pa.second - 97] - 1) / 2 << endl;
        } else {    
            // cout << pa.first << ' ' << pre[r][(int)pa.first - 97] << ' ' << pre[l - 1][(int)pa.first - 97] << endl;
            // cout << pa.second << ' ' << pre[r][(int)pa.second - 97] << ' ' << pre[l - 1][(int)pa.second - 97] << endl;
            cout << (pre[r][(int)pa.first - 97] - pre[l - 1][(int)pa.first - 97]) * (pre[r][(int)pa.second - 97] - pre[l - 1][(int)pa.second - 97]) << endl;
        }
    } 


    return 0;
}