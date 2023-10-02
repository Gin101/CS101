#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

const int maxN = 1e6;
int st[21][maxN * 2] = {0};

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        st[0][i + 1] = st[0][i] + (s[i] == '(' ? 1 : -1);
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j <= s.size(); j++) {
            st[i + 1][j] = min(st[i][j], st[i][j + (1 << i)]);
        }
    }

    int m = 0;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        int l = 0;
        int r = 0;
        scanf("%d %d", &l, &r);

        int idx = 0;
        while ((1 << (idx + 1)) <= (r - l + 1)) {
            idx++;
        }

        printf("%d\n", r - l + 1 - (st[0][l - 1] + st[0][r] - 2 * min(st[idx][l - 1], st[idx][r - (1 << idx) + 1])));
    }

    return 0;
}