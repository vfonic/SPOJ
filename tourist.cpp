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
#include <string>
#include <vector>

#define inf 1000000

#define MAXN 102
using namespace std;

int w, h;
char city[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];

int zvezda(int x, int y)
{
    if (city[x-1][y-1] == '#') return -inf;
    else return city[x-1][y-1] == '*' ? 1 : 0;
}

int main()
{
    int t;
    
    scanf("%d", &t);
    
    for (int qwertz = 0; qwertz < t; ++qwertz)
    {
        scanf("%d %d", &w, &h);
        
        for (int i = 0; i < h; ++i)
        {
            scanf("%s", city[i]);
        }
        
        memset(dp, 0, sizeof dp);
        
        for (int i = 1; i <= h; ++i)
        {
            for (int j = 1; j <= w; ++j)
            {
                if (zvezda(i,j) == -inf)
                    continue;
                int sum = i+j;
                int limit = min(sum,100);
                for (int k = i; k <= limit; ++k)
                {
                    dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), max(dp[i-1][j][k-1], dp[i][j-1][k-1])) + zvezda(i,j);
                    if (i != k)
                        dp[i][j][k] += zvezda(k, sum-k);
                }
            }
        }
        printf("%d\n", dp[h][w][h]);
    }
    
    return 0;
}
