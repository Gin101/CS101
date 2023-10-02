#include <iostream>
#include <map>

using namespace std;

map<long long, pair<long long, long long> > mp;
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        long long t = 0;
        long long w = 0;
        long long s = 0;
        cin >> t >> w >> s;

        mp[t] = make_pair(w, s);
    }
	
    for (int i = 1; i <= n; i++) {
        long long tmp = 1;
        long long result = 0;

        while (!mp.empty() && tmp <= mp.rbegin() -> first) {
            auto it = mp.lower_bound(tmp);
            result += (it -> second).first;
            tmp = it -> first + (it -> second).second;
            mp.erase(it);
        }

        cout << result << endl;
    }
	
    return 0;
}