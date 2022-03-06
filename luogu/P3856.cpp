#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int maxLen = 101;
int num[maxLen][30] = {{0}};
int num2[maxLen][30] = {{0}};
int num3[maxLen][30] = {{0}};
long long result[maxLen][maxLen][maxLen] = {{{0}}};
long long dfs(int u, int v, int w) {
    long long sum = 1;
    if (result[u][v][w] != -1) {
        return result[u][v][w];
    }

    for (int i = 0; i < 26; i++) {
        if (num[u][i] && num2[v][i] && num3[w][i]) {
            sum += dfs(num[u][i], num2[v][i], num2[w][i]);
        }
    }

    return result[u][v][w] = sum;
}
void pre(int len, int tmp[maxLen][30], string s) {
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            tmp[i][j] = tmp[i + 1][j];
        }
        tmp[i][s[i] - 97] = i + 1;
    }
}

int main()
{
    memset(result, -1, sizeof(result));

    string a;
    string b;
    string c;
    cin >> a >> b >> c;

    pre(a.size(), num, a);
    pre(b.size(), num2, b);
    pre(c.size(), num3, c);

    cout << dfs(0, 0, 0) - 1 << endl;

    return 0;
}