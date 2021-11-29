#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int maxN = 200001;
long long _result = 0;
int u[maxN] = {0};
int v[maxN] = {0};
int w[maxN] = {0};
int d[maxN] = {0};//depth
int num[maxN] = {0};
bool flag[maxN] = {false};
int dp[2 * maxN][20] = {{0}};
int dp2[2 * maxN][20] = {{0}};
vector<pair<int, int>> e[maxN];
vector<pair<pair<int, int>, pair<int, int>>> s;
 
void dfs(int x, int p, int val, int depth)  {
	dp[x][0] = p;
    dp2[x][0] = val;
	d[x] = depth;
	
	for (int i = 0; i < e[x].size(); i++)  {
        if (e[x][i].first != p) {
            dfs(e[x][i].first, x, e[x][i].second, depth + 1);
        }
    }
		
	depth--;
}
 
int ope(int x) {
	if (num[x] == x) {
        return x;
    }
	return num[x] = ope(num[x]);
}
 
int lca(int a, int b) {
	int result = 0;
	if (d[a] < d[b]) {
        swap(a, b);
    } 

	for (int i = 18; i >= 0; i--) {
        if (d[dp[a][i]] >= d[b]) {
            result = max(result, dp2[a][i]);
            a = dp[a][i];
        }
    }

	if (a == b) {
        return result;
    } 
	
	for (int i = 18; i >= 0; i--) {
        if (dp[a][i] != dp[b][i]) {
            result = max(max(result, dp2[a][i]), dp2[b][i]);
            a = dp[a][i];
            b = dp[b][i];
        }
    }

	result = max(result, max(dp2[a][0], dp2[b][0]));
	
	return result;
}
 
int main()
{ 
     
    int n = 0;
    int m = 0;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		s.push_back(make_pair(make_pair(w[i], i), make_pair(u[i], v[i])));
	}
	
	for (int i = 1; i <= n; i++) {
        num[i] = i;
    }
	
	sort(s.begin(), s.end());
	
	for (int i = 0; i < s.size(); i++) {
		if (ope(s[i].second.first) == ope(s[i].second.second)) {
            continue;
        } 

		e[s[i].second.first].push_back(make_pair(s[i].second.second, s[i].first.first)); 
        e[s[i].second.second].push_back(make_pair(s[i].second.first, s[i].first.first));
		flag[s[i].first.second] = true;
        _result += s[i].first.first;

        s[i].second.first = ope(s[i].second.first);
        s[i].second.second = ope(s[i].second.second);
        num[s[i].second.second] = s[i].second.first;
	}
	
	dfs(1, 0, 0, 1);// seek depth
	
	dp[1][0] = 1;
	for (int i = 1; i <= 18; i++) {
        for (int j = 1; j <= n; j++) {
			dp[j][i] = dp[dp[j][i - 1]][i - 1];
			dp2[j][i] = max(dp2[j][i - 1], dp2[dp[j][i - 1]][i - 1]);
		}
    }
		
	for (int i = 1; i <= m; i++) {
		if (flag[i]) {
            cout << _result << endl;
        } else {
            cout << _result + w[i] - lca(u[i], v[i]) << endl;
        }
	}
}