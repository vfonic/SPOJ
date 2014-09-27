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
#define MAXN 1000000
#define swap(a,b) a^=b; b^=a; a^=b;

using namespace std;

int gcd(int a, int b) {
    if (b > a) { swap(a,b); }

    while (b) {
        a -= a/b*b;
        swap(a,b);
    }

    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int a[MAXN];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int gcd_all = gcd(a[2]-a[1], a[1]-a[0]);
    for (int i = 3; i < n; ++i) {
        int diff = a[i] - a[i-1];
        gcd_all = gcd(gcd_all, diff);
    }

    int sol = 0;
    for (int i = 1; i < n; ++i) {
        int diff = a[i] - a[i-1];
        sol += diff/gcd_all-1;
    }

    printf("%d\n", sol);
    
    return 0;
}
