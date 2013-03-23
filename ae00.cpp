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
    
    int i = 0;
    int sol = t;
    for (int qwertz = 2; qwertz <= t; ++qwertz) {
        for (i = qwertz; i < t; ++i) {
            if (i*qwertz > t) break;
            ++sol;
        }
        if (i == qwertz) break;
    }
    printf("%d\n", sol);
    return 0;
}
