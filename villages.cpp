#include <algorithm>
#include <bitset>
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
#define MAXN 1000

using namespace std;

bitset<MAXN> neighbours[MAXN];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    int x, y;
    bitset<MAXN> bit;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x, &y);
        neighbours[x-1].set(y-1);
    }

    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            bitset<MAXN> mask = neighbours[i] & neighbours[j];
            int cnt = mask.count();
            sol += cnt * (cnt-1) / 2;
        }
    }

    printf("%lld\n", sol);
    
    return 0;
}
