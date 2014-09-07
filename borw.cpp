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
#define MAXN 202

using namespace std;

int n;
int a[MAXN];
int sol;
int dp[MAXN][MAXN][MAXN];

int rek(int dec_idx, int inc_idx, int idx) {
    if (dp[dec_idx][inc_idx][idx] != -1) return dp[dec_idx][inc_idx][idx];
    if (idx == n) return 0;

    if (a[idx] < a[dec_idx]) {
        dp[dec_idx][inc_idx][idx] = rek(idx, inc_idx, idx+1);
    }
    if (a[idx] > a[inc_idx]) {
        if (dp[dec_idx][inc_idx][idx] == -1)
            dp[dec_idx][inc_idx][idx] = rek(dec_idx, idx, idx+1);
        else
            dp[dec_idx][inc_idx][idx] = min(rek(dec_idx, idx, idx+1), dp[dec_idx][inc_idx][idx]);
    }

    if (dp[dec_idx][inc_idx][idx] == -1)
        dp[dec_idx][inc_idx][idx] = 1 + rek(dec_idx, inc_idx, idx+1);
    else
        dp[dec_idx][inc_idx][idx] = min(1 + rek(dec_idx, inc_idx, idx+1), dp[dec_idx][inc_idx][idx]);

    return dp[dec_idx][inc_idx][idx];
}

int main() {
    a[MAXN-2] = inf;
    a[MAXN-1] = -inf;
    while (true) {
        scanf("%d", &n);
        
        if (n == -1) return 0;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        memset(dp, -1, sizeof dp);

        sol = rek(MAXN-2, MAXN-1, 0);

        printf("%d\n", sol);
    }
    
    return 0;
}
