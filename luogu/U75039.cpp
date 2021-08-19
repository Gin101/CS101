#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int score[n];
    int maxScore = 0;
    int minScore = INT_MAX;
    int failPeople = 0;
    for (int i = 0; i < n; i++)
    {
        int chinese = 0;
        int maths = 0;
        int english = 0;
        cin >> chinese >> maths >> english;
        score[i] = chinese + maths + english;
        if (score[i] > maxScore)
        {
            maxScore = score[i];
        }
        if (score[i] < minScore)
        {
            minScore = score[i];
        }
        if (score[i] < 180)
        {
            failPeople++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ' ' << score[i] << endl;
    }
    cout << maxScore << ' ' <<  minScore << ' ' << failPeople << endl;

    return 0;
}