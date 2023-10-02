#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;
 
const int maxV = 5e4 + 1;
const long long INF = 0x3f3f3f3f3f;
long long dis[maxV] = {0};
long long w[maxV] = {0};
struct Node {
    int idx;
    long long val;
} tmp;
vector<Node> edge[maxV];
 
int main()
{
	int t = 0;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		int v = 0;
		int e = 0;
		cin >> v >> e;
		
		for (int j = 1; j <= v; j++) {
            scanf("%lld", &w[j]);
		}
		
		for (int j = 0; j < e; j++) {
			int a = 0;
			int b = 0;
			long long c = 0;
            scanf("%d %d %lld", &a, &b, &c);
			
			tmp.idx = b;
			tmp.val = c;
			edge[a].push_back(tmp);
			tmp.idx = a;
			edge[b].push_back(tmp);
		}
		
		memset(dis, INF, sizeof(dis));
		dis[1] = 0;
	    priority_queue<pair<int, int> >q;
	    q.push(make_pair(-dis[1], 1));        
	    while (!q.empty()) {
            int idx = q.top().second;
            q.pop();
	    	for (int j = 0; j < edge[idx].size(); j++) {
	    		if (dis[edge[idx][j].idx] > dis[idx] + edge[idx][j].val) {
	    			dis[edge[idx][j].idx] = dis[idx] + edge[idx][j].val;
	    			q.push(make_pair(-dis[edge[idx][j].idx], edge[idx][j].idx));
				}
			}
	    }
	    
	    bool flag = false;
	    long long sum = 0;
	    for (int j = 1; j <= v; j++) {
	    	if (dis[j] == INF) {
	    		flag = true;
	    		break;
			}
			
			sum += w[j] * dis[j];
		}
        if (!flag) {
        	cout << sum << endl;
		} else {
			cout << "No Answer" << endl;
		}

        for (int j = 1; j <= v; j++) {
            edge[j].clear();
        }
    }

    return 0;
}