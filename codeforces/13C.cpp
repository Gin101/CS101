#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> q;

int main()
{
    int n = 0;
    cin >> n;

    long long result = 0;
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;

        q.push(num);

        if (q.top() > num) {
            result += q.top() - num;
            q.pop();
            q.push(num);
        }
    }

    cout << result << endl;

    return 0;
}