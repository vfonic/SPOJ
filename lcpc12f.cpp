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

int main() {
    int t;
    scanf("%d", &t);
    
    int C[MAXN];
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        int x, n;
        scanf("%d%d", &x, &n);
        
        memset(C, 0, sizeof C);
        
        long long sol = 0;
        int nr;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nr);
            if (x < nr) continue;
            sol += C[x-nr];
            ++C[nr];
        }
        
        printf("%d. %lld\n", qwertz+1, sol);
    }
    
    return 0;
}
