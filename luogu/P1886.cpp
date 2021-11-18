#include <iostream>
#include <queue>

using namespace std;

const int maxN = 1e6;
int a[maxN] = {0};
priority_queue<int> q;
queue<int> q2;

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
        q.push(a[i]);
        q2.push(a[i]);
    }



    return 0;
}