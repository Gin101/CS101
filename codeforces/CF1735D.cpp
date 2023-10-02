#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    vector<vector<int> > num(n, vector<int>(k));
    map<vector<int>, int> mp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> num[i][j];
        }
    }
	
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> tmp(k);
            for (int l = 0; l < k; l++) {
                tmp[l] = (6 - num[i][l] - num[j][l]) % 3;
            }
            mp[tmp]++;
        }
    }
	
    int result = 0;
    for (int i = 0; i < n; i++) {
        int cnt = mp[num[i]];
        result += mp[num[i]] * (mp[num[i]] - 1) / 2;
    }

    cout << result << endl;

    return 0;
}