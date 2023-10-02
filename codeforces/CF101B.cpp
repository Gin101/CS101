#include <iostream>
#include <algorithm>

using namespace std;

const int maxM = 1e5 + 1;
const int MOD = 1e9 + 7;
pair<int, int> bus[maxM];
int num[maxM] = {1};
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> bus[i].second >> bus[i].first;
    }

    sort(bus + 1, bus + m + 1);

    int cnt = 0;
    int idx = 1;
    int idx2 = 0;
    int result = 0;
    while (idx <= m) {
        idx2 = idx;
        while (idx2 <= m && bus[idx2].first == bus[idx].first) {
            int tmp = lower_bound(bus, bus + idx, pair<int, int> (bus[idx2].second, 0)) - bus;
            if (tmp > 0) {
                cnt = (num[idx - 1] - num[tmp - 1] + MOD) % MOD;
            } else {
                cnt = num[idx - 1];
            }
            num[idx2] = (num[idx2 - 1] + cnt) % MOD;
            if (bus[idx2].first == n) {
                result = (result + cnt) % MOD;
            }
            idx2++;
        }
        idx = idx2;
    }
    
    cout << result << endl;

    return 0;
}			 				  		    		 	 	 			