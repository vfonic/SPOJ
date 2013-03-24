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
#define MAXN 66
#define MOD 1000000007

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    
    int maxNumber[MAXN];
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        long long sol = 1;
        bool error = false;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &maxNumber[i]);
        }
        sort(maxNumber, maxNumber+n);
        
        for (int i = n-1; i >= 0; --i) {
            maxNumber[i] -= i;
            if (maxNumber[i] < 1) { error = true; break; }
            sol = (sol * maxNumber[i]) % MOD;
        }
        
        if (error) { printf("0\n"); }
        else { printf("%lld\n", sol); }
    }
    
    printf("KILL BATMAN\n");
    return 0;
}
