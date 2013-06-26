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
#define MAXN 4000

using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    
    int n;
    scanf("%d", &n);
    int n_squared = n*n;
    
    int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    }
    
    int *ab_sums = new int[MAXN * MAXN], *cd_sums = new int[MAXN * MAXN];
    for (int i = 0; i < n; ++i) {
        int n_i = n*i;
        for (int j = 0; j < n; ++j) {
            ab_sums[j+n_i] = a[i] + b[j];
            cd_sums[j+n_i] = -c[i] - d[j];
        }
    }
    
    sort(ab_sums, ab_sums + n_squared);
    sort(cd_sums, cd_sums + n_squared);
    
    int i = 0, j = 0;
    int sol = 0;
    while (i < n_squared && j < n_squared) {
        while (i < n_squared && j < n_squared && ab_sums[i] != cd_sums[j]) {
            if (ab_sums[i] < cd_sums[j]) ++i;
            else ++j;
        }
        if (i == n_squared || j == n_squared) break;
        
        int val = ab_sums[i], tmp_sol = 0;
        while (i < n_squared && ab_sums[i] == val) { ++tmp_sol; ++i; }
        int tmp_sol2 = 0;
        while (j < n_squared && cd_sums[j] == val) { ++tmp_sol2; ++j; }
        sol += tmp_sol*tmp_sol2;
    }
    
    printf("%d\n", sol);
    return 0;
}
