//
//  bing.cpp
//  
//
//  Created by jianbochen on 2022/4/26.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("bing.in", "r", stdin);
    freopen("bing.out", "w", stdout);
    
    int t = 0;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;
        
        int result = 0;
        for (int j = 1; j * j <= n - 1; j++) {
            if ((n - 1) % j == 0) {
                if (j * j == n - 1) {
                    result++;
                } else {
                    result += 2;
                }
            }
        }
        
        for (int j = 1; j * j <= n - 2; j++) {
            if ((n - 2) % j == 0) {
                if (j * j == n - 2) {
                    result++;
                } else {
                    result += 2;
                }
            }
        }
        
        cout << n - result << endl;
    }
    
    return 0;
}
