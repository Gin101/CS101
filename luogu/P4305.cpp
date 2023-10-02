#include <iostream>
#include <map>
#include <cstring>
#include <stdio.h>

using namespace std;

const int maxN = 5e4;
int result[maxN] = {0};
map<int, bool> mp;
int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        mp.clear();
        int idx = 0;
        for (int j = 0; j < n; j++) {
            int num = 0;
            scanf("%d", &num);

            if (!mp.count(num)) {
                result[idx++] = num;
            } 
            mp[num] = true;
        }
        for (int j = 0; j < idx; j++) {
            printf("%d ", result[j]);
        }
        cout << endl;
    }

    return 0;
}