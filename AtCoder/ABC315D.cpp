#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxH = 2000;
const int maxW = 2000;
int ch[maxH][26] = {{0}};
int cw[maxW][26] = {{0}};
int main()
{
    int h = 0;
    int w = 0;
    cin >> h >> w;

    string s;
    for (int i = 0; i < h; i++) {
        cin >> s;
        for (int j = 0; j < w; j++) {
            ch[i][s[j] - 'a']++;
            cw[j][s[j] - 'a']++;
        }
    }

    bool flag = true;
    int mh = h;
    int mw = w;
    while (flag) {
        flag = false;
        vector<pair<int, int> > dh;
        vector<pair<int, int> > dw;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < 26; j++) {
                if (mw > 1 && ch[i][j] == mw) {
                    dh.push_back(make_pair(i, j));
                    flag = true;
                }
            }
        }

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < 26; j++) {
                if (mh > 1 && cw[i][j] == mh) {
                    dw.push_back(make_pair(i, j));
                    flag = true;
                }
            }
        }

        for (auto di : dh) {
            ch[di.first][di.second] = 0;
            mh--;

            for (int i = 0; i < w; i++) {
                if (cw[i][di.second] > 0) {
                    cw[i][di.second]--;
                }
            }
        }

        for (auto di : dw) {
            cw[di.first][di.second] = 0;
            mw--;

            for (int i = 0; i < h; i++) {
                if (ch[i][di.second] > 0) {
                    ch[i][di.second]--;
                }
            }
        }
    }

    cout << mh * mw << endl;

    return 0;
}