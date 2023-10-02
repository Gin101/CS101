#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxN = 1001;
const int maxM = 1001;
const int maxK = 1e5 + 1;
int r[4] = {-1, 0, 1, 0};
int c[4] = {0, 1, 0, -1};
char graph[maxN][maxM];
int h[maxN][maxM][4] = {{{0}}};
int op[maxK] = {0};
int len[maxK] = {0};
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];
        }
    }

    replace(graph[0], graph[0] + sizeof(graph), '\0', '#');
	
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            h[i][j][0] = graph[i][j] == '#' ? -1 : h[i - 1][j][0] + 1;
            h[i][j][3] = graph[i][j] == '#' ? -1 : h[i][j - 1][3] + 1;
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            h[i][j][2] = graph[i][j] == '#' ? -1 : h[i + 1][j][2] + 1;
            h[i][j][1] = graph[i][j] == '#' ? -1 : h[i][j + 1][1] + 1;
        }
    }
	
    int k = 0;
    cin >> k;

    for (int i = 0; i < k; i++) {
        char dir;
        cin >> dir >> len[i];

        if (dir == 'N') {
            op[i] = 0;
        } else if (dir == 'E') {
            op[i] = 1;
        } else if (dir == 'S') {
            op[i] = 2;
        } else {
            op[i] = 3;
        }
    }
	
    string result;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (graph[i][j] < 'A' || graph[i][j] > 'Z') {
                continue;
            }
            int newr = i;
            int newc = j;
            int idx = 0;
            while (idx < k) {
                if (h[newr][newc][op[idx]] < len[idx]) {
                    break;
                }
                newr += r[op[idx]] * len[idx];
                newc += c[op[idx]] * len[idx];
                idx++;
            }
            if (idx == k) {
                result += graph[i][j];
            }
        }
    }
	
    sort(result.begin(), result.end());
    cout << (result.empty() ? "no solution" : result) << endl;

	return 0;
}