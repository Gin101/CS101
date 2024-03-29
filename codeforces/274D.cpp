#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 3e5 + 1;
const int maxM = 3e5 + 1;
int in[maxN] = {0};

struct Num {
    int val = 0;
    int idx = 0;
} p[maxN];
vector<int> e[maxN];

bool cmp(Num x, Num y) {
    return x.val < y.val;
}
int main() 
{
	int n = 0;
    int m = 0;
    cin >> n >> m;

	int idx = m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
            cin >> p[j].val;
			p[j].idx = j;
		}

		sort(p, p + m, cmp);
		idx++;
		int idx2 = 0;
        bool flag = false;
        while (idx2 < m) {
            if (p[idx2].val == -1) {
				idx2++;
				continue;
			}

            int tmp = idx2;
			while (tmp < m && p[idx2].val == p[tmp].val) {
				if (flag) {
					e[idx].push_back(p[tmp].idx);
					in[p[tmp].idx]++;
				}
				e[p[tmp].idx].push_back(idx + 1);
				in[idx + 1]++;
				tmp++;
			}
			idx++;
			idx2 = tmp;
			flag = true;
        }
	}

	queue<int> q;
	for (int i = 0; i < m; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}

	vector<int> result;
	while (!q.empty()) {
		if (q.front() < m) {
            result.push_back(q.front() + 1);
        }
		for (int i = 0; i < e[q.front()].size(); i++) {
			in[e[q.front()][i]]--;
			if (in[e[q.front()][i]] == 0) {
                q.push(e[q.front()][i]);
            }
		}

        q.pop();
	}

	if (result.size() < m) {
        cout << -1;
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << ' ';
        }
	}

    cout << endl;

    return 0;
}