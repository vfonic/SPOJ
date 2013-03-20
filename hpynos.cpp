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
    
    set<int> seen;
    
    while (t != 1 && seen.find(t) == seen.end()) {
        seen.insert(t);
        int x = t;
        t = 0;
        while (x > 0) {
            t += (x%10)*(x%10);
            x /= 10;
        }
    }
    
    if (t == 1) printf("%d\n", seen.size());
    else printf("-1\n");
    return 0;
}
