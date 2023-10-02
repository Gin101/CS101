#include <iostream>

using namespace std;

int n = 0;
int m = 0;
int k = 0;
int b  = 0;
int result = 0;
void dfs(int x, int tot, int l) {
    if (x == k) {
        if (tot >= n) {
            result++;
        }
        return;
    }

    long long tmp = x ? l * b : 1;

    while (tot + tmp <= m) {
        dfs( x + 1, tot + tmp, tmp);
        tmp *= b;
    }
}
int main() 
{
    cin >> n >> m >> k >> b;

    dfs(0, 0, 0);   

    cout << result << endl;

    return 0;
}
