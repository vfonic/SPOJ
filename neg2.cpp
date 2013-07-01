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
#define MAXN 100000

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    bool negative = false;
    if (t == 0) { printf("%d\n", 0); return 0; }
    
    if (t < 0) {
        // -1, 2, -4, 8, -16, 32...
        negative = true;
        t = -t;
    }
    
    int a[64] = {0}, pok = 0;
    bool carrying = false;
    int cur = 0;
    while (t || carrying) {
        bool yes = t & 1;
        
        if (yes && carrying) { cur = 0; carrying = true; }
        else if (yes || carrying) { cur = 1; carrying = negative; }
        else { cur = 0; carrying = false; }
        
        a[pok++] = cur;
        negative = !negative;
        t >>= 1;
    }
    
    for (int i = pok-1; i >= 0; --i) {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
