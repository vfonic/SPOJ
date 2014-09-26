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

using namespace std;

int main() {
    int n,k;
    scanf("%d%d", &n, &k);

    map<int, int> nrs;
    
    int x;
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);

        map<int,int>::iterator it = nrs.find(x+k);
        if (it != nrs.end()) {
            sol += it->second;
        }
        it = nrs.find(x-k);
        if (it != nrs.end()) {
            sol += it->second;
        }
        
        it = nrs.find(x);
        if (it == nrs.end()) {
            nrs[x] = 1;
        } else {
            ++it->second;
        }
    }

    printf("%d\n", sol);
    
    return 0;
}
