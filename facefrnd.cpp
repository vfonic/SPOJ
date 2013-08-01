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
#define MAXN 10000

using namespace std;

int friends[MAXN];

int main() {
    int t;
    scanf("%d", &t);
    
    int sol = 0;
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        int id;
        scanf("%d", &id);
        if (friends[id] == 1) --sol;
        friends[id] = -1;

        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &id);
            if (!friends[id]) {
                ++sol;
                friends[id] = 1;
            }
        }
    }
    printf("%d\n", sol);
    
    return 0;
}
