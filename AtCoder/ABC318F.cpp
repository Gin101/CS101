#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

int main() 
{
    int n = 0;
    cin >> n;

    vector<long long> x(n);
    vector<long long> l(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    vector<array<long long, 3> > v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v.push_back({x[i] - l[j], j, 1});
            v.push_back({x[i] + l[j] + 1, j, -1});
        }
    }

    ranges :: sort(v);

    long long result = 0;
	vector<int> cnt(n);
    for (int i = 0; i < v.size(); i++) {
        auto [x, j, p] = v[i];
        cnt[j] += p;
        if (i + 1 < n && v[i + 1][0] == x) {
            continue;
        }

        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (cnt[j] < j + 1) {
                flag = true;
            }
        }

        if (!flag) {
            result += v[i + 1][0] - x;
        }
    }
	
    cout << result << endl;

	return 0;
}