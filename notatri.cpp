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
#define MAXN 2000

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    
    int a[MAXN];
    while (n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        
        int sol = 0;
        for (int i = 0; i < n-2; ++i) {
            for (int j = i+1; j < n-1; ++j) {
                int lo = j+1, hi = n;
                int mid = lo + (hi-lo)/2;
                while (lo < hi) {
                    if (a[i]+a[j] >= a[mid]) lo = mid+1;
                    else hi = mid;
                    mid = lo + (hi-lo)/2;
                }
                sol += mid-j-1;
            }
        }
        
        long long fac = (long long)n*(n-1)*(n-2)/6;
        printf("%d\n", (int)fac-sol);
        
        scanf("%d", &n);
    }
    
    return 0;
}
