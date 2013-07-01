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
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        int x, y;
        scanf("%d%d", &y, &x);
        
        if (x != y && x+2 != y) { printf("No Number\n"); continue; }
        
        if (x%2 == 0) {
            printf("%d\n", x+y);
        } else {
            printf("%d\n", x+y-1);
        }
    }
    
    return 0;
}
