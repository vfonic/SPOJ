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
#define MAXNUM 1000000

using namespace std;

int multiples[MAXNUM], sz[MAXNUM+1];
int a[MAXN], b[MAXN];
int n;

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++sz[a[i]];
        b[i] = a[i];
    }

    sort(a, a+n);

    for (int i = 0; i < n; i += sz[a[i]]) {
        for (int j = a[i]; j <= MAXNUM; j += a[i]) {
            multiples[j] += sz[a[i]];
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d\n", multiples[b[i]]-1);
    }
    
    return 0;
}
