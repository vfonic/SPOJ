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
    scanf("%d\n", &t);
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        int n;
        scanf("%d", &n);
        
        int i = 1, sol = 0;
        while (n > 0) {
            if (n&i) {
                ++sol;
                n -= i;
            }
            i <<= 1;
        }
        printf("%d\n", sol);
    }
    
    return 0;
}
