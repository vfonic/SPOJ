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

int n, c;
int x[MAXN];

bool can_place_cows(int dist) {
	int last = x[0];
	int cows_placed = 1;
	for (int i = 1; i < n; ++i) {
	    if (x[i]-last >= dist) {
	    	last = x[i];
	    	++cows_placed;
	    }
	}

	return cows_placed >= c ? true : false;
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        scanf("%d%d", &n, &c);
        
        int lo = INT_MAX, hi = INT_MIN;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x[i]);
            if (x[i] > hi) hi = x[i];
            if (x[i] < lo) lo = x[i];
        }

        sort(x, x+n);
        while (lo < hi) {
        	int mid = lo + (hi-lo)/2;
        	if (can_place_cows(mid)) lo = mid+1;
        	else hi = mid;
        }

        printf("%d\n", lo-1);
    }
    
    return 0;
}
