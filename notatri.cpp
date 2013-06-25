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
        for (int i = n-1; i > 1; --i) {
            int j = 0, k = i-1;
            while(j<k) {
                while(j<k && a[j]+a[k] >= a[i]) k--;
                sol += k-j;
                ++j;
            }
        }
        
        printf("%d\n", sol);
        
        scanf("%d", &n);
    }
    
    return 0;
}
