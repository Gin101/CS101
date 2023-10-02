#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;

const int maxN = 2e5;
priority_queue<int, vector<int>, greater<int> > num[maxN];
priority_queue<int, vector<int>, greater<int> > box[maxN];

int main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        int op = 0;
        int x = 0;
        scanf("%d %d", &op, &x);

        if (op == 1) {
            int y = 0;
            scanf("%d", &y);

            box[y - 1].push(x);
            num[x - 1].push(y);
        } else if (op == 2) {
            priority_queue<int, vector<int>, greater<int> > tmp = box[x - 1];
            while (!tmp.empty()) {
                cout << tmp.top() << ' ';
                tmp.pop();
            }
            cout << endl;
        } else {
            int pre = num[x - 1].top();
            cout << num[x - 1].top() << ' ';
            priority_queue<int, vector<int>, greater<int> > tmp = num[x - 1];
            tmp.pop();
            while (!tmp.empty()) {
                if (tmp.top() != pre) {
                    cout << tmp.top() << ' ';
                }
                tmp.pop();
            }
            cout << endl;
        }
    }

    return 0;
}