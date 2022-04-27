//
//  sequence.cpp
//  
//
//  Created by jianbochen on 2022/4/26.
//

#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

const int maxN = 1e5;
int a[maxN] = {0};
int box[maxN] = {0};
map<int, int> mp;
int main()
{
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    
    int n = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i < n; i++) {
        a[i] ^= a[i - 1];
    }
    
    int result = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            result++;
            continue;
        }
        
        if (!mp.count(a[i])) {
            mp[a[i]] = idx++;
        }
        box[mp[a[i]]]++;
    }
    
    for (int i = 0; i < idx; i++) {
        if (box[i] >= 2) {
            result += box[i] - 1;
        }
    }
    
    if (n - result >= 2) {
        cout << n - result << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
