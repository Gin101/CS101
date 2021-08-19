
#include <iostream>

using namespace std;

const int maxN = 101;
bool flag[maxN] = {false};
int main()
{
    int n = 0;
    cin >> n;

	for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;

        flag[num] = true;
    }

	for (int i = 100; i >= 1; i--) {
        if (flag[i]) {
            for (int j = i - 1; j >= 1; j--) {
                if (flag[j]) {
                    flag[i / j] = true;
                }
            }
        }
    }

    int result = 0;
	for (int i = 1; i <= 100; i++) {
        if (flag[i]) {
            result++;
        }
    }
	
    cout << result << endl;

    return 0;
}