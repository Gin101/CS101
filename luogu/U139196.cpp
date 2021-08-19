#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
//	freopen("name.in", "r", stdin);
//	freopen("name.out", "w", stdout);
	int n = 0;
	cin >> n;
	
	const int maxName = 100;

	string word[maxName];
	string again[maxName];
	int idx = 0;
	int cnt = 0;
	string s;
	
	while (cin >> s) {
		word[idx] = s;
		idx++;
	}
	
	for (int i = 0; i < idx; i++) {
		string tmp = word[i];
		if (tmp[0] >= 'A' && tmp[0] <= 'Z') {
			bool flag = true;
			for (int j = 0; j < cnt; j++) {
				if (again[j] == tmp) {
					flag = false;
					break;
				}	
			}
			
			if (!flag) {
				continue;
			}
			
			tmp[0] = tmp[0] - 'A' + 'a';
			string name = tmp;
			bool isName = true;
			for (int j = 0; j < idx; j++) {
				if (word[j] == name) {
					isName = false;
					break;
				}
			}
			if (isName) {
				cout << word[i] << endl;
				again[cnt++] = word[i];
			}
		}
	}
	
	return 0;
}
