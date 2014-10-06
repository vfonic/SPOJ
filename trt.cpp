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
#define MAXN 2000

using namespace std;

int n;
int a[MAXN];
int dp[MAXN][MAXN];

int rek(int age = 1, int left_pos = 0, int right_pos = n-1) {
    if (left_pos == right_pos) return age*a[left_pos];

    if (dp[left_pos][right_pos]) return dp[left_pos][right_pos];

    dp[left_pos][right_pos] = max(age*a[left_pos] + rek(age+1, left_pos+1, right_pos),
                                  age*a[right_pos] + rek(age+1, left_pos, right_pos-1));
    return dp[left_pos][right_pos];
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int sol = rek();

    printf("%d\n", sol);
    
    return 0;
}
