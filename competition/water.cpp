#include <iostream>

using namespace std;

int a[50] = {0};
int b[50] = {0};

void dfs(int tot, int result)  {

}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, 0);
    }

    return 0;
}