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
    
    for (int qwertz = 1; qwertz <= t; ++qwertz) {
        long long r;
        scanf("%lld", &r);
        printf("Case %d: %.2f\n", qwertz, 4*r*r+0.25);
    }
    
    return 0;
}
