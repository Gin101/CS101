#include <iostream>
#include <vector>

using namespace std;

const int maxN = 5000;
struct Node {
    int next = 0;
    int val = 0;
} tmp;
vector<Node> e[maxN];

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u = 0;
        int v = 0;
        int d = 0;
        cin >> u >> v >> d;

        tmp.val = d;
        tmp.next = v - 1;
        e[u - 1].push_back(v - 1);
        tmp.next = u - 1;
        e[v - 1].push_back(u - 1);
    }

    return 0;
}