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

#define inf 1000000000
#define MAXN 100000

using namespace std;

long long dp[64][10];
int n;

long long rek(int current_digit, int index) {
    if (index == n-1) return 10 - current_digit;
    
    if (dp[index][current_digit] != -1) return dp[index][current_digit];
    
    dp[index][current_digit] = 0;
    for (int i = current_digit; i < 10; ++i) {
        dp[index][current_digit] += rek(i, index+1);
    }
    return dp[index][current_digit];
}

int main()
{
    int t;
    
    scanf("%d", &t);
    
    for (int qwertz = 1; qwertz <= t; ++qwertz) {
        scanf("%d%d", &n, &n);
        
        memset(dp, -1, sizeof dp);
        printf("%d %lld\n", qwertz, rek(0, 0));
    }
    
    return 0;
}
