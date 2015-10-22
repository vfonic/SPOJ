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

int union_find[MAXN];
int size[MAXN];

int root(int index) {
    int root = index;
    while (root != union_find[root])
        root = union_find[root];
    while (index != root) {
        int newindex = union_find[index];
        union_find[index] = root;
        index = newindex;
    }
    return root;
}

bool unite(int from, int to) {
    int union_find_from = root(from), union_find_to = root(to);
    if (union_find_from == union_find_to) return false;
    
    if (size[union_find_from] < size[union_find_to]) { union_find[union_find_from] = union_find_to; size[union_find_to] += size[union_find_from]; }
    else { union_find[union_find_to] = union_find_from; size[union_find_from] += size[union_find_to]; }
    return true;
}

int main()
{
    cin.sync_with_stdio(false);//Toggles on or off synchronization of all the iostream standard streams
    //with their corresponding standard C streams
    //if it is called before the program performs its first input or output operation.
    //Thus cin will be as fast as scanf.
    int n,m;
    scanf("%d%d", &n, &m);
    
    if (n <= m) { printf("NO\n"); return 0; }
    
    
    for (int i = 1; i <= n; ++i) {
        union_find[i] = i;
        size[i] = 1;
    }
    
    int from, to;
    for (int qwertz = 0; qwertz < m; ++qwertz) {
        scanf("%d%d", &from, &to);
        
        if (!unite(from, to)) { printf("NO\n"); return 0; }
    }
    
    printf("YES\n");
    return 0;
}
