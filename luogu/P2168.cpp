#include <iostream>
#include <queue>

using namespace std;

struct Node {
    long long w = 0;
    int h = 0;
    bool operator< (Node x) const{
        return (x.w != w) ? w > x.w : h > x.h;
    } 
} tmp;

priority_queue<Node> q;

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        long long w = 0;
        cin >> w;

        tmp.w = w;
        tmp.h = 1;
        q.push(tmp);
    }

    for (int i = 0; k > 2 && (i < ((k - n % (k - 1)) % (k - 1))); i++) {
        tmp.w = 0;
        tmp.h = 1;
        q.push(tmp);
    }

    long long result = 0;
    while (q.size() >= k) {
        long long sum = 0;
        int h = 0;
        for (int i = 0; i < k; i++) {
            sum += q.top().w;
            h = max(h, q.top().h);
            q.pop();
        }

        tmp.w = sum;
        tmp.h = h + 1;
        q.push(tmp);
        result += sum;
    }

    cout << result << endl << q.top().h - 1 << endl;

    return 0;
}