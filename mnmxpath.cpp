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
#define MAXN 100001

using namespace std;

void ucitaj(int *a, int n, int *prva_jedinica, int *br_jed, int *prva_bliza_nula, int *zadnja_nula) {
    char s[MAXN];
    scanf("%s", s);
    
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
        if (a[i]) {
            if (*prva_jedinica == -1) *prva_jedinica = i;
            ++(*br_jed);
        } else {
            if (*prva_bliza_nula == -1) *prva_bliza_nula = i;
            *zadnja_nula = i;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        int n;
        scanf("%d", &n);
        
        int a[MAXN];
        int prva_jedinica_a = -1;
        int br_jed_a = 0;
        int prva_bliza_nula_a = -1, zadnja_nula_a = -1;
        ucitaj(a, n, &prva_jedinica_a, &br_jed_a, &prva_bliza_nula_a, &zadnja_nula_a);
        
        int m;
        scanf("%d", &m);
        int b[MAXN];
        int prva_jedinica_b = -1;
        int br_jed_b = 0;
        int prva_bliza_nula_b = -1, zadnja_nula_b = -1;
        ucitaj(b, m, &prva_jedinica_b, &br_jed_b, &prva_bliza_nula_b, &zadnja_nula_b);
        
        if (prva_jedinica_a == -1 || prva_jedinica_b == -1) { printf("0 0\n"); continue; }
        if (prva_bliza_nula_a == -1 && prva_bliza_nula_b == -1) { printf("%d %d\n", n+m-1, n+m-1); continue; }
        if (prva_bliza_nula_a == -1) { printf("%d %d\n", n-1+br_jed_b, br_jed_b); continue; }
        if (prva_bliza_nula_b == -1) { printf("%d %d\n", m-1+br_jed_a, br_jed_a); continue; }
        
        int maks = br_jed_a + br_jed_b - 1;
        printf("%d ", maks);
        
        int mini = 0; // = a[0] == b[0] && a[0] == 1;
        // mini += a[n-1] == b[m-1] && a[n-1] == 1;
        
        if (prva_bliza_nula_a < prva_bliza_nula_b) {
            mini += prva_bliza_nula_a;
        } else {
            mini += prva_bliza_nula_b;
        }
        mini += min(m - zadnja_nula_b - 1, n - zadnja_nula_a - 1);
        printf("%d\n", mini);
    }
    
    return 0;
}
