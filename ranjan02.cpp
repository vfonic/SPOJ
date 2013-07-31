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

unsigned long long f[100];

unsigned long long fun(int n) {
    if (f[n]) return f[n];
    return f[n] = 3*fun(n-1)+2;
}

int main() {
    int t;
    scanf("%d", &t);

    f[1] = 2;
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", fun(n));
    }
    
    return 0;
}
