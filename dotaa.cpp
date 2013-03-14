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

int main()
{
    int t;
    
    scanf("%d", &t);
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        int n, m, D;
        scanf("%d %d %d", &n, &m, &D);
        int H;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &H);
            while (H > D) { H -= D; --m; }
        }
        if (m <= 0) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
