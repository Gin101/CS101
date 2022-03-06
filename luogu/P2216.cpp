#include <iostream>
#include <limits.h>

using namespace std;

const int maxN = 100;
int g[maxN][maxN] = {0};
pair<int, int> result[maxN][maxN];
pair<int, int> result2[maxN][maxN];
pair<int, int> q[maxN];
pair<int, int> q2[maxN];	

int main() 
{
    int a = 0;
    int b = 0;
    int n = 0;
    cin >> a >> b >> n;
	
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> g[i][j];
        }
    }

	int _result = INT_MAX;
    int head1 = 0;
    int head2 = 0;
    int tail1 = 0;
    int tail2 = 0;
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) { 
			while (head1 < tail1 && g[i][j] > q[tail1 - 1].first) {
                tail1--;
            }
			while (head2 < tail2 && g[i][j] < q2[tail2 - 1].first) {
                tail2--;
            }
			q[tail1++] = make_pair(g[i][j], j);
			q2[tail2++] = make_pair(g[i][j], j);
			
			if (j < n) {
                continue;
            }
			
			while (q[head1].second < j - n + 1) {
                head1++;
            }
			while (q2[head2].second < j - n + 1) {
                head2++;
            }
			
			result[i][j] = make_pair(q[head1].first, q2[head2].first);
		}
	}

	for (int i = n; i <= b; i++) {
		head1 = 0;
        tail1 = 0;
        head2 = 0;
        tail2 = 0;
		for (int j = 0; j <= a; j++) {
			while (head1 < tail1 && result[j][i].first > q[tail1 - 1].first) {
                tail1--;
            }
			while (head2 < tail2 && result[j][i].second < q2[tail2 - 1].first) {
                tail2--;
            }
			q[tail1++] = make_pair(result[j][i].first, j);
			q2[tail2++] = make_pair(result[j][i].second, j);
			
			if (j < n) {
                continue;
            }
			
			while (q[head1].second < j - n + 1) head1++;
			while (q2[head2].second < j - n + 1) head2++;
			
			_result = min(_result, q[head1].first - q2[head2].first);
			result2[j][i] = make_pair(q[head1].first, q2[head2].first);
		}
	}
	
	cout << _result << endl;
	
	return 0;
} 