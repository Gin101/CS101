#include <iostream>
#include <queue>

using namespace std;

const int maxK = 1e6 + 1;
bool flag[maxK] = {false};
struct Node {
	int idx = 0;
    int val = 0;
};
deque<Node> d;

int main() 
{
    int k = 0;
	cin >> k;

    d.push_front(Node{1, 1});
    flag[1] = true;
    while (!d.empty()) {
        int idx = d.front().idx;
        int val = d.front().val;
        d.pop_front();
        if (idx == 0) {
            cout << val << endl;
            return 0;
        }

        if (!flag[10 * idx % k]) {
            d.push_front(Node{10 * idx % k, val});
            flag[10 * idx % k] = true;
        }
        if (!flag[idx + 1]) {
            d.push_back(Node{idx + 1, val + 1});
        }
    }

	return 0;
}