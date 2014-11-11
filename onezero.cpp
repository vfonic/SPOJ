#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define inf 1000000000
#define MAXN 20000

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    int n;
    int been[MAXN];
    int which[MAXN];
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        scanf("%d", &n);

        if (n == 1) {
            printf("1\n");
            continue;
        }

        memset(been, -1, sizeof been);
        been[1] = 0;
        queue<int> kju;
        for (kju.push(1); !kju.empty(); kju.pop()) {
            int num = kju.front();

            if (!num) {
                stack<int> stog;
                while (been[num]) {
                    stog.push(which[num]);
                    num = been[num];
                }

                printf("1");
                while (!stog.empty()) {
                    printf("%d", stog.top());
                    stog.pop();
                }
                printf("\n");
                break;
            }

            for (int i = 0; i < 2; ++i) {
                int next = (num*10+i)%n;
                if (been[next] == -1) {
                    been[next] = num;
                    which[next] = i;
                    kju.push(next);
                }
            }
        }
    }
    
    return 0;
}
