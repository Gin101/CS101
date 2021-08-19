#include <iostream>
#include <string>
#include <stack>

using namespace std;

const int maxN = 1000005;

int cnt[maxN] = {0};
int son[maxN][2] = {{0}};
bool flag[maxN] = {false};
bool c[maxN] = {false};
int n = 0;
bool dfs(int u, bool g) {
    cnt[u] ^= g;
    if (u <= n) {
        return cnt[u];
    }
    
    int x = dfs(son[u][0], g ^ flag[son[u][0]]);
    int y = dfs(son[u][1], g ^ flag[son[u][1]]);
    if (cnt[u] == 2) {
        if (x == 0) {
        	c[son[u][1]] = true;
        }
        if (y == 0) {
        	c[son[u][0]] = true;
        }
        
        return x & y;
    } else {
        if (x == 1) {
        	c[son[u][1]] = true;
        }
        if (y == 1) {
        	c[son[u][0]] = true;
        }
        
        return x | y;
    }
}
void dfs2(int u) {
    if (u <= n) {
    	return;
    }
    
    c[son[u][0]] |= c[u];
    c[son[u][1]] |= c[u];
    dfs2(son[u][0]);
    dfs2(son[u][1]);
}
int main() 
{
	string s;
    getline(cin, s);
    
    cin >> n;
    int idx = n;
    
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i];
    }
    
    stack<int> b;
    for (int i = 0; s[i]; i += 2) {
        if (s[i] == 'x') {
            int tmp = 0;
            i++;
            
            while (s[i] != ' ') {
                tmp = tmp * 10 + s[i] - '0';
                i++;
            }
            
            i--;
            b.push(tmp);
        } else if (s[i] == '&') {
            int tmp = b.top();
            b.pop();
            
            int tmp2 = b.top();
            b.pop();
            
            b.push(++idx);
            cnt[idx] = 2;
            son[idx][0] = tmp;
            son[idx][1] = tmp2;
        } else if (s[i] == '|') {
            int tmp = b.top();
            b.pop();
            int tmp2 = b.top();
            b.pop();
            b.push(++idx);
           cnt[idx] = 3;
            son[idx][0] = tmp;
            son[idx][1] = tmp2;
        } else if(s[i] == '!'){
            flag[b.top()] ^= 1;
        }
    }
    
    bool result = dfs(idx, flag[idx]);
    dfs2(idx);
    
    int q = 0;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
    	int x = 0;
        cin >> x;
        
        if (c[x]) {
        	cout << result << endl;
        } else {
        	cout << !result << endl;
        }
    }
    
    return 0;
}