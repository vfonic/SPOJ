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
#define MAXN 200000

using namespace std;

int p = 10007;
int H[MAXN];
int P[MAXN];
string s;
int limit;

int h(int idx, int length) {
    return H[idx+length]-H[idx-1]*P[length+1];
}

int lcp(int mini, int idx) {
    if (s[mini] != s[idx]) return 0;
    
    int lo = 1, hi = limit;
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if (h(mini, mid) == h(idx, mid)) lo = mid+1;
        else hi = mid;
    }
    return lo;
}

int main() {
    cin.sync_with_stdio(false);
    cin >> s;
    limit = s.size();
    s += s;
        
    P[0] = 1;
    H[0] = s[0];
    int i;
    for (i = 1; i < (int)s.size(); ++i) {
        P[i] = P[i-1]*p;
        H[i] = H[i-1]*p + s[i];
    }
    
    int mini = 0;
    for (int i = 1; i < limit; ++i) {
        int elcepe = lcp(mini, i);
        if (s[mini+elcepe] > s[i+elcepe]) mini = i;
    }
    
    cout << mini << endl;
    return 0;
}
