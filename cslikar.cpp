#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#define inf 1000000000
#define MAXN 50

using namespace std;

bool bio_fire[MAXN][MAXN];
bool bio_slikar[MAXN][MAXN];
int r, c;
char map[MAXN+1][MAXN+1];
int len[MAXN][MAXN];

struct point_length {
    int first, second, length;
    point_length(int _first, int _second, int _length) { first = _first; second = _second; length = _length; }
};

int main()
{
    memset(len, -1, sizeof len);
    scanf("%d%d\n", &r, &c);
    
    queue<point_length> fire;
    pair<int, int> den;
    queue<point_length> slikari;
    int dx, dy;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf("%c", &map[i][j]);
            if (map[i][j] == '*') {
                fire.push(point_length(i, j, 0));
                bio_fire[i][j] = true;
            } else if (map[i][j] == 'D') {
                den = make_pair(i, j);
                dx = i; dy = j;
                bio_fire[i][j] = true; /* small hack to reduce code size in if-statements below */
            } else if (map[i][j] == 'S') { slikari.push(point_length(i, j, 0)); bio_slikar[i][j] = true; }
        }
        scanf("\n");
    }
    
    while (!fire.empty()) {
        point_length flame = fire.front(); fire.pop();
        int x = flame.first, y = flame.second, length = flame.length;
        
        len[x][y] = length;
        ++length;
        
        if (x > 0 && !bio_fire[x-1][y] && map[x-1][y] != 'X') {
            fire.push(point_length(x-1, y, length));
            bio_fire[x-1][y] = true;
        }
        if (x+1 < r && !bio_fire[x+1][y] && map[x+1][y] != 'X') {
            fire.push(point_length(x+1, y, length));
            bio_fire[x+1][y] = true;
        }
        if (y > 0 && !bio_fire[x][y-1] && map[x][y-1] != 'X') {
            fire.push(point_length(x, y-1, length));
            bio_fire[x][y-1] = true;
        }
        if (y+1 < c && !bio_fire[x][y+1] && map[x][y+1] != 'X') {
            fire.push(point_length(x, y+1, length));
            bio_fire[x][y+1] = true;
        }
    }
    
    while(!slikari.empty()) {
        point_length slikar = slikari.front(); slikari.pop();
        int x = slikar.first, y = slikar.second, length = slikar.length+1;
        
        if (abs(x-dx)+abs(y-dy) == 1) { printf("%d\n", length); return 0; }
        
        if (x > 0 && !bio_slikar[x-1][y] && map[x-1][y] != 'X' && (len[x-1][y] > length || len[x-1][y] == -1)) {
            slikari.push(point_length(x-1, y, length));
            bio_slikar[x-1][y] = true;
        }
        if (x+1 < r && !bio_slikar[x+1][y] && map[x+1][y] != 'X' && (len[x+1][y] > length || len[x+1][y] == -1)) {
            slikari.push(point_length(x+1, y, length));
            bio_slikar[x+1][y] = true;
        }
        if (y > 0 && !bio_slikar[x][y-1] && map[x][y-1] != 'X' && (len[x][y-1] > length || len[x][y-1] == -1)) {
            slikari.push(point_length(x, y-1, length));
            bio_slikar[x][y-1] = true;
        }
        if (y+1 < c && !bio_slikar[x][y+1] && map[x][y+1] != 'X' && (len[x][y+1] > length || len[x][y+1] == -1)) {
            slikari.push(point_length(x, y+1, length));
            bio_slikar[x][y+1] = true;
        }
    }
    
    printf("KAKTUS\n");
    return 0;
}
