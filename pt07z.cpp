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
#define MAXN 10000

using namespace std;

vector<int> tree[MAXN];
int dist[MAXN];
int n;

int bfs(int node) {
    queue<int> kju;
    
    memset(dist, -1, sizeof dist);
    dist[node] = 0;
    kju.push(node);
    
    int limit;
    while (!kju.empty()) {
        int cur_node = kju.front(); kju.pop();
        
        limit = tree[cur_node].size();
        for (int i = 0; i < limit; ++i) {
            if (dist[tree[cur_node][i]] == -1) {
                kju.push(tree[cur_node][i]);
                dist[tree[cur_node][i]] = dist[cur_node]+1;
            }
        }
    }
    
    int maks = dist[node];
    int maks_node = node;
    for (int i = 0; i < n; ++i) {
        if (dist[i] > maks) { maks = dist[i]; maks_node = i; }
    }
    
    return maks_node;
}

int main()
{
    scanf("%d\n", &n);
    
    int u, v;
    for (int qwertz = 0; qwertz < n; ++qwertz) {
        scanf("%d%d", &u, &v);
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }
    
    int node = bfs(0);
    node = bfs(node);
    
    printf("%d\n", dist[node]);
    return 0;
}
