//
//  robot.cpp
//  
//
//  Created by jianbochen on 2022/4/26.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>

using namespace std;

const int maxN = 500;
const int maxM = 500;
char graph[maxN][maxM] = {{0}};
queue<pair<int, int> > q;

int main()
{
    freopen("robot.in", "r", stdin);
    freopen("robot.out", "w", stdout);
    
    int t = 0;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        
        int n = 0;
        int m = 0;
        cin >> n >> m;
        
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> graph[i][j];
                if (graph[i][j] == 'R') {
                    q.push(make_pair(i, j));
                }
            }
        }
        
        bool flag = false;
        for (int j = 0; j < s.size() && !flag; j++) {
            int idxrow = q.front().first;
            int idxcol = q.front().second;
            do {
                int row = q.front().first;
                int col = q.front().second;
                switch(s[j]) {
                    case 'W': {
                        row--;
                        break;
                    } case 'A': {
                        col--;
                        break;
                    } case 'S': {
                        row++;
                        break;
                    } case 'D': {
                        col++;
                    }
                }
                
                if (row < 0 || row == n || col < 0 || col == m) {
                    cout << "YES" << endl;
                    flag = true;
                    break;
                } else {
                    if (graph[row][col] != '*') {
                        q.push(make_pair(row, col));
                    }
                }
                
                q.push(make_pair(q.front().first, q.front().second));
                q.pop();
            } while(q.front().first != idxrow && q.front().second != idxcol);
        }
        
        if (!flag) {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
