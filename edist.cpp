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
#define MAXN 2001

using namespace std;

char x[MAXN], y[MAXN];
int dp[MAXN][MAXN];

int rec(int i = 0, int j = 0) {
    if (dp[i][j] != -1) return dp[i][j];

    if (x[i] == '\0' && y[j] == '\0') return dp[i][j] = 0;
    if (x[i] == '\0') return dp[i][j] = 1+rec(i, j+1);
    if (y[j] == '\0') return dp[i][j] = 1+rec(i+1, j);

    return dp[i][j] = min(min(
        1+rec(i+1, j), // insert in x
        1+rec(i, j+1)), // remove from x
        rec(i+1,j+1)+(x[i] != y[j]) // replace x with y
    );
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        scanf("%s", x);
        scanf("%s", y);

        memset(dp, -1, sizeof dp);
        int sol = rec();
        printf("%d\n", sol);
    }
    
    return 0;
}
