#include <iostream>

using namespace std;

int n = 0;
const int maxN = 9;
int tmp[maxN] = {0};
bool flag[maxN] = {false};
void dfs(int now, int cnt, int num[]) {
    num[cnt] =  now + 1;
    if (cnt == n - 1) {
        for (int i = 0; i < n; i++) {
            cout << "    " << num[i];
        }
        cout << endl;
        
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            flag[i] = true;
            dfs(i, cnt + 1, num);
            flag[i] = false;
        }
    }   
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        flag[i] = true;
        dfs(i, 0, tmp);
        flag[i] = false;
    }

    return 0;
}