#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxL = 2000;
string a;
string b;
int result[maxL][maxL] = {{0}};
int dp(int idxa, int idxb) { 
    if (result[idxa][idxb] != -1) {
        return result[idxa][idxb];
    }

    if (idxa == 0) {
        return result[idxa][idxb] = idxb;
    } 
    if (idxb == 0) {
        return result[idxa][idxb] = idxa;
    }

    int flag = 1;
    if (a[idxa - 1] == b[idxb - 1]) {
        flag = 0;
    }

    return result[idxa][idxb] = min(min(dp(idxa - 1, idxb), dp(idxa, idxb - 1)) + 1, dp(idxa - 1, idxb - 1) + flag);
}
int main()
{
    cin >> a >> b;

    memset(result, -1, sizeof(result));

    dp(a.size(), b.size());

    cout << result[a.size()][b.size()] << endl;

    return 0;
}