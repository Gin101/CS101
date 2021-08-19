#include <iostream>
#include <algorithm>

using namespace std;

int v = 0;
int g = 0;
const int maxV = 25;
const int maxG = 15;
int c[maxV] = {0};
int n[maxG][maxV] = {0};
bool flag[maxG] = {false};
int num[maxV] = {0};
int result = 0;
void dfs(int cnt, int vita[]) {
    bool flag2 = true;
    for (int i = 0; i < v; i++) {
        if (vita[i] < c[i]) {
            flag2 = false;
            break;
        }
    }

    if (flag2) {
        result = min(result, cnt);                                                                       
    }
}

int main()
{
    cin >> v;

    for (int i = 0; i < v; i++) {
        cin >> c[i];
    }

    cin >> g;

    for (int i = 0; i < g; i++) {
        for (int j = 0; j < v; j++) {
            cin >> n[i][j];
        }
    }

    dfs(0, num);

    return 0;
}