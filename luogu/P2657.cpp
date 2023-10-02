#include <iostream>

using namespace std;

int a = 0;
int b = 0;
int result = 0;
void dfs(long long nw, int last) {
    if (nw > b) {
        return;
    }

    if (nw <= b && nw >= a) {
        result++;
    }

    for (int i = last + 2; i <= 9; i++) {
        dfs(1ll * nw * 10 + i, i);
    }
    for (int i = last - 2; i >= 0; i--) {
        dfs(1ll * nw * 10 + i, i);
    }

    return;
}
int main() 
{
    cin >> a >> b;

    dfs(0, -1);

    cout << result << endl;

    return 0;
}