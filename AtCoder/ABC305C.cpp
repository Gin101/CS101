#include <iostream>

using namespace std;

int h = 0;
int w = 0;
const int maxH = 500;
const int maxW = 500;
char s[maxH][maxW];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};
bool check(int r, int c) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < h && nc >= 0 && nc < w && s[nr][nc] == '#') {
            cnt++;
        }
    }
    if (cnt >= 2) {
        return true;
    }
    return false;
}

int main()
{
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> s[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.' && check(i, j)) {
                cout << i + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}