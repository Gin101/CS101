
#include <iostream>
#include <cstring>

using namespace std;

int n = 0;
const int maxT = 8;
const int maxC = 11;
int num[maxT][maxT] = {{0}};
int box[maxC] = {0};
int result[maxC] = {0};
int result2[maxC] = {0};
int result3[maxC] = {0};
int tmpNum[maxT][maxT] = {{0}};
int tmpBox[maxC] = {0};
bool flag[maxT][maxT] = {{0}};
void clean() {
	bool flag2 = true;
	while (flag2) {
		flag2 = false;
		bool flag3 = true;
		while (flag3) {
			flag3 = false;
			for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 8; j++) {
                    if (num[i][j] == 0 && num[i][j + 1] != 0) {
                        num[i][j] = num[i][j + 1];
                        num[i][j + 1] = 0;
                        flag3 = true;
                    }
                }
            }
		}

		memset(flag, false, sizeof(flag));
		for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 8; j++) {
                if (i != 0 && i < 4 && num[i][j] != 0 && num[i][j] == num[i - 1][j] && num[i][j] == num[i + 1][j]) {
                    num[i][j] = 1;
                    num[i - 1][j] = 1;
                    num[i + 1][j] = 1;
                    flag2 = true;
                }

                if (j != 0 && num[i][j] != 0 && num[i][j] == num[i][j - 1] && num[i][j] == num[i][j + 1]) {
                    num[i][j] = 1;
                    num[i][j - 1] = 1;
                    num[i][j + 1] = 1;
                    flag2 = true;
                }
            }
        }
		if (flag2) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 8; j++) {
                    if (num[i][j] != 0) {
                        box[num[i][j]]--;
                        num[i][j] = 0;
                    }
                }
            }
		}
	}
}

void dfs (int now) {
	if (now > n) {
        for (int i = 0; i < 11; i++) {
            if (box[i] != 0) {
                return;
            }

            for (int i = 1; i <= n; i++) {
                cout << result[i] << ' ' << result2[i] << ' ' << result3[i] << endl;
            }

            exit(0);
        }
	}

    for (int i = 0; i < 11; i++) {
        if (box[i] != 0 && box[i] < 3) {
            return;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tmpNum[i][j] = num[i][j];
            memcpy(tmpBox, box, sizeof(tmpBox));
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            if (tmpNum[i][j] != 0) {
                if (i < 4 && tmpNum[i + 1][j] != tmpNum[i][j]) {
                    memcpy(box, tmpBox, sizeof(box));
                    for (int k = 0; k < 8; k++)
                }
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            if (tmpNum[i][j] != 0) {
                if (i < 4 && tmpNum[i + 1][j] != tmpNum[i][j]) {
                    memcpy(box, tmpBox, sizeof(box));
                    for 
                }
            }
        }
    }
	for(int i=0;i<5;++i){
		for(int j=0;j<8;++j)
		if(ylzt[i][j]){
			if(i<4&&ylzt[i+1][j]!=ylzt[i][j]){
				memcpy(tong,yltong,sizeof tong);
				for(int i=0;i<9;++i)for(int j=0;j<9;++j)
				bl[i][j]=ylzt[i][j];
				int x=bl[i][j];
				bl[i][j]=bl[i+1][j];
				bl[i+1][j]=x;
				ansx[now]=i,ansy[now]=j,yd[now]=1;
				clean();
				dfs(now+1);
			}
			if(i&&!ylzt[i-1][j]){
				memcpy(tong,yltong,sizeof tong);
				for(int i=0;i<9;++i)for(int j=0;j<9;++j)
				bl[i][j]=ylzt[i][j];
				bl[i-1][j]=bl[i][j];
				bl[i][j]=0;
				ansx[now]=i,ansy[now]=j,yd[now]=-1;
				clean();
				dfs(now+1);
			}
		}
	}
	for(int i=0;i<9;++i)for(int j=0;j<9;++j)
	bl[i][j]=ylzt[i][j];
	memcpy(tong,yltong,sizeof tong);
}
int main()
{
    cin >> n;

	for (int i = 0; i < 5; i++) {
        int t = 0;
        int idx = 0;
        while (cin >> t && t != 0) {
            num[i][idx++] = t;
            box[t]++;
        }   
	}

	dfs(1);

    cout << -1 << endl;

	return 0;
}