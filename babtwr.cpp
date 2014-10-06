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
#define MAXN 30
#define swap(a,b) { a ^= b; b ^= a; a^= b; }

using namespace std;

int n;
int x[MAXN], y[MAXN], z[MAXN];
map<pair<int, int>, int> dp[30];

int rek(int width = INT_MAX, int depth = INT_MAX, int size = 0) {
    if (size == 30) return 0;

    pair<int, int> wid_dep = make_pair(width, depth);
    if (dp[size].find(wid_dep) != dp[size].end()) return dp[size][wid_dep];

    dp[size][wid_dep] = 0;
    for (int i = 0; i < n; ++i) {
        if (y[i] < width && z[i] < depth) {
            dp[size][wid_dep] = max(dp[size][wid_dep],
                x[i] + rek(y[i], z[i], size+1));
        }
        if (x[i] < width && y[i] < depth) {
            dp[size][wid_dep] = max(dp[size][wid_dep],
                z[i] + rek(x[i], y[i], size+1));
        }
        if (x[i] < width && z[i] < depth) {
            dp[size][wid_dep] = max(dp[size][wid_dep],
                y[i] + rek(x[i], z[i], size+1));
        }
    }

    return dp[size][wid_dep];
}

int main() {
    scanf("%d", &n);
    while(n) {
        for (int i = 0; i < n; ++i) {
            dp[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &x[i], &y[i], &z[i]);
            
            if (x[i] > y[i]) swap(x[i], y[i]);
            if (y[i] > z[i]) swap(y[i], z[i]);
            if (x[i] > y[i]) swap(x[i], y[i]);
        }

        printf("%d\n", rek());

        scanf("%d", &n);
    }
    
    return 0;
}
