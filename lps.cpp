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

int p = 10007;
int P[MAXN];
int H[MAXN];
char word[MAXN+1];

int r_H[MAXN];

int limit;

int hash(int idx, int length) {
    return H[idx+length-1]-H[idx-1]*P[length];
}

int r_hash(int idx, int length) {
    return r_H[idx+length-1]-r_H[idx-1]*P[length];
}

int odd_palin(int idx) {
    int r_idx = limit-idx-1;
    int lo = 1, hi = min(idx, r_idx)+1;
    if (hi == 1) return 0;
    
    // upper_bound
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if (hash(idx, mid+1) == r_hash(r_idx, mid+1)) lo = mid+1;
        else hi = mid;
    }
    return lo-1;
}

int even_palin(int idx) {
    int r_idx = limit-idx;
    int lo = 1, hi = min(idx-1, r_idx-1)+1;
    if (hi < lo) return 0;
    
    // upper_bound
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if (hash(idx, mid+1) == r_hash(r_idx, mid+1)) lo = mid+1;
        else hi = mid;
    }
    
    return lo-1;
}

int main() {
    scanf("%d", &limit);
    
    scanf("%s", word);
    
    P[0] = 1;
    H[0] = word[0];
    r_H[0] = word[limit-1];
    for (int i = 1; i < limit; ++i) {
        P[i] = P[i-1]*p;
        H[i] = H[i-1]*p+word[i];
        r_H[i] = r_H[i-1]*p+word[limit-i-1];
    }
    
    int maxpalin = 1;
    for (int i = 1; i < limit; ++i) {
        int lpalin = odd_palin(i)*2+1;
        if (lpalin > maxpalin) maxpalin = lpalin;
        
        if (word[i] == word[i-1]) {
            lpalin = even_palin(i)*2+2;
            if (lpalin > maxpalin) maxpalin = lpalin;
        }
    }
    
    printf("%d\n", maxpalin);
    return 0;
}
