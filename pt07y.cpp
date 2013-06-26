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
#define MAXN 10001

using namespace std;

vector<int> edges[MAXN];
bool bio[MAXN];

bool bfs(int from, int index) {
    if (bio[index]) return false;
    bio[index] = true;
    
    for (int i = 0; i < (int)edges[index].size(); ++i) {
        if (edges[index][i] != from && !bfs(index, edges[index][i])) return false;
    }
    return true;
}

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    
    if (n <= m) { printf("NO\n"); return 0; }
    
    int from, to;
    for (int qwertz = 0; qwertz < m; ++qwertz) {
        scanf("%d%d", &from, &to);
        
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!bio[i]) {
            if (!bfs(0, i)) {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}
