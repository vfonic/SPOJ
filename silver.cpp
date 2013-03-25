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
    
    while(t) {
        int x = t;
        int sol = -1;
        while (x) {
            ++sol;
            x >>= 1;
        }
        printf("%d\n", sol);
        
        scanf("%d", &t);
    }
    
    return 0;
}
