#include <iostream>

using namespace std;

const int maxN = 2e5 + 1;
int boxX[maxN] = {0};
int boxY[maxN] = {0};
int result[maxN] = {0};
int boxR[maxN] = {0};
void ope(int idx, int cnt) {
    if (idx == 0) {
        return;
    }

    result[idx] = cnt;
    ope(boxR[idx], cnt + 1);
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        boxX[x - 1]++;
        boxY[y - 1]++;
        boxR[x] = y;
    }

    int cntX = 0;
    int cntY = 0;
    for (int i = 0; i < n; i++) {
        if (boxX[i] == 0) {
            cntX++;
        }
        if (boxY[i] == 0) {
            cntY++;
        }

        if (cntX == 2 || cntY == 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        if (boxY[i] == 0) {
            ope(i + 1, 1);
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}