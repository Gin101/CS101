#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int maxNM = 2e5;
int a[maxNM] = {0};
int box[maxNM] = {0};

priority_queue<int> result;
priority_queue<int, vector<int>, greater<int> > tmp;
int main()
{
    int m = 0;
    int n = 0;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int u = 0;
        cin >> u;

        box[u - 1]++;
    }

    int cnt = 1;
    for (int i = 0; i < m; i++) {
        result.push(a[i]);
        if (result.size() > cnt) {
            tmp.push(result.top());
            result.pop();
        }
        while (box[i] != 0) {
            cout << result.top() << endl;
            if (!tmp.empty()) {
                result.push(tmp.top());
                tmp.pop();
            }
            cnt++;

            box[i]--;
        }
    }

    return 0;
}