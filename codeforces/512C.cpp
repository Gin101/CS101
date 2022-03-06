#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int maxN = 101;
string s[maxN];
int in[27] = {0};
int graph[27][27] = {{0}};
int main()
{
	int n = 0;
    cin >> n;

	for (int i = 1; i <= n; i++) {
        cin >> s[i];
    } 

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
            bool flag = false;
			int idx = min(s[i].size(), s[j].size());
			for (int k = 0; k < idx; k++) {
				if (s[i][k] != s[j][k]) {
                    in[s[j][k] - 'a']++;
					graph[s[i][k] - 'a'][s[j][k]-'a']++;

                    flag = true;
					break;
				}
			}

			if (!flag) {
				if (s[i].size() > s[j].size()) {
					cout << "Impossible" << endl;
					return 0;
				}
			}
		}
	}
     
	for (int i = 0; i < 26; i++) {
		if (in[i] == 0) {
            q.push(i);
        }
	}

	string tmp = "";
	while (!q.empty()) {
		tmp += char(q.front() + 'a');
		for (int i = 0; i < 26; i++) {
			if (graph[q.front()][i] > 0) {
				in[i] -= graph[q.front()][i];
				graph[q.front()][i] = 0;
				if (in[i] == 0) {
                    q.push(i);
                }
			}
		}
		q.pop();
	}

	if (tmp.size() < 26) {
        cout << "Impossible" << endl;
    } else {
        cout << tmp << endl;
    }
}

			    	 	        			  			  		