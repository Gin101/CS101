#include <iostream>
#include <queue>

using namespace std;

const int maxH = 10;
const int maxW = 10;
int a[maxH][maxW] = {{0}};
queue<pair<int, int> > q;

int main()
{
    int h = 0;
    int w = 0;
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    q.push(make_pair(0, 0));
    while (!q.empty()) {
        pair<int, int> right = make_pair(q.front().first, q.front().second + 1);
        pair<int, int> down = make_pair(q.front().first + 1, q.front().second);
        if (right.second < w) {
            q.push(right);
        }
        if (down.first < h) {
            q.push(down);
        }
        q.pop();
    }

    return 0;
}