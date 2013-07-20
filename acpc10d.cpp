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
    int n;
    scanf("%d", &n);
    
    int a[2][3];
    int br = 1;
    while (n) {
    	scanf("%d%d%d", &a[0][0], &a[0][1], &a[0][2]);
    	a[0][0] = inf;
    	a[0][2] += (a[0][2] >= 0 ? inf : a[0][1]);

    	bool odd = true;
    	for (int i = 1; i < n; ++i) {
    	    scanf("%d%d%d", &a[odd][0], &a[odd][1], &a[odd][2]);

    	    a[odd][0] += min(a[!odd][0], a[!odd][1]);
    	    a[odd][1] += min(a[odd][0], min(min(a[!odd][0], a[!odd][1]), a[!odd][2]));
    	    a[odd][2] += min(min(a[odd][1], a[!odd][1]), a[!odd][2]);
    	    odd = !odd;
    	}

    	printf("%d. %d\n", br++, a[!odd][1]);

    	scanf("%d", &n);
    }
    
    return 0;
}
