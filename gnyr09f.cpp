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
#define MAXN 100

using namespace std;

int dp[MAXN][MAXN][2];
int n, k;

int adjbc(int zadnja_je_bila_jedinica = 0, int broj_sparenih_jedinica = 0, int poz = 0) {
    
    if (poz == n) return broj_sparenih_jedinica == k;
    
    if (broj_sparenih_jedinica > k) return 0;
    
    int &ref = dp[poz][broj_sparenih_jedinica][zadnja_je_bila_jedinica];
    
    if (ref != -1) return ref;
    
    ref = 0;
    ref += adjbc(0, broj_sparenih_jedinica, poz+1);
    ref += adjbc(1, broj_sparenih_jedinica+zadnja_je_bila_jedinica, poz+1);
    
    return ref;
}

int main()
{
    int t;
    
    scanf("%d", &t);
    
    for (int qwertz = 1; qwertz <= t; ++qwertz) {
        memset(dp, -1, sizeof dp);
        int x;
        scanf("%d%d%d", &x, &n, &k);
        
        printf("%d %d\n", qwertz, adjbc());
    }
    
    return 0;
}
