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
#define MAXN 251

using namespace std;

char mapa[MAXN][MAXN];
int koze, ukupno_koze, vukovi, ukupno_vukovi;
int n, m;

void dfs(int i, int j) {
    if (mapa[i][j] == 'k') ++koze;
    else if (mapa[i][j] == 'v') ++vukovi;
    
    mapa[i][j] = '#';
    
    if (i > 0 && mapa[i-1][j] != '#') dfs(i-1, j);
    if (i+1 < n && mapa[i+1][j] != '#') dfs(i+1, j);
    if (j > 0 && mapa[i][j-1] != '#') dfs(i, j-1);
    if (j+1 < m && mapa[i][j+1] != '#') dfs(i, j+1);
}
int main()
{
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s\n", mapa[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mapa[i][j] != '#') {
                dfs(i, j);
                if (koze > vukovi) ukupno_koze += koze;
                else ukupno_vukovi += vukovi;
                koze = vukovi = 0;
            }
        }
    }
    printf("%d %d\n", ukupno_koze, ukupno_vukovi);
    return 0;
}
