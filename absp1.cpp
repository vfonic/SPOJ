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
#define MAXN 10000

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    int n;
    int x;
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        scanf("%d", &n);
        
        long long sol = 0, diff = 0;
        long long past = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);

            diff += i*(x-past);
            sol += diff;

            past = x;
        }

        printf("%lld\n", sol);
    }
    
    return 0;
}
