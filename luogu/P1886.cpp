#include <iostream>
#include <queue>

using namespace std;

const int maxN = 1e6;
int a[maxN] = {0};
struct Num {
    int val = 0;
    int idx = 0;
};
deque<Num> maxR;
deque<Num> minR;
int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        Num tmp;
        tmp.val = a[i];
        tmp.idx = i;
        if (!minR.empty() && minR.front().idx + k == i) {
            minR.pop_front();
        }
        while (!minR.empty() && minR.back().val > a[i]) {
            minR.pop_back();
        }
        minR.push_back(tmp);

        if (i >= k - 1) {
            cout << minR.front().val << ' ';
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        Num tmp;
        tmp.val = a[i];
        tmp.idx = i;
        if (!maxR.empty() && maxR.front().idx + k == i) {
            maxR.pop_front();
        }
        while (!maxR.empty() && maxR.back().val < a[i]) {
            maxR.pop_back();
        }
        maxR.push_back(tmp);

        if (i >= k - 1) {
            cout << maxR.front().val << ' ';
        }
    }
    cout << endl;

    return 0;
}