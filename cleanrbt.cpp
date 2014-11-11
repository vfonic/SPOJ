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
#define MAXN 21
#define MAXDIRT 10
#define x first
#define y second
#define node first
#define weight second

using namespace std;

struct point {
    int x, y, dist;
    point(int _x, int _y, int _dist) { x = _x; y = _y; dist = _dist; }
};

//          node dist
vector<pair<int, int> > graph[MAXDIRT];
int cookie;

int dp[1<<MAXDIRT][MAXDIRT];

int rec(int mask, int cur) {
    // printf("mask:%d cur:%d\n", mask, cur);
    if (mask == (1<<cookie)-1) return 0;

    if (dp[mask][cur] != -1) return dp[mask][cur];

    int mini = inf;
    for (vector<pair<int, int> >::iterator it = graph[cur].begin(); it != graph[cur].end(); ++it) {
        if ((mask & (1<<it->node)) == 0) {
            mini = min(mini, it->weight + rec(mask | (1<<it->node), it->node));
        }
    }

    return dp[mask][cur] = mini;
}

int main() {
    while (true) {
        int w, h;
        scanf("%d%d", &w, &h);

        if (!w && !h) break;

        char map[MAXN][MAXN];
        for (int i = 0; i < h; ++i) {
            scanf("%s", map[i]);
        }
        
        vector<pair<int, int> > points;
        // pair<int, int> beginning;
        int source = 0;
        int points_mapping[MAXN][MAXN];
        cookie = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (map[i][j] == 'o') {
                    // beginning = make_pair(i, j);
                    source = cookie;
                    map[i][j] = '*';
                }

                if (map[i][j] == '*') {
                    points.push_back(make_pair(i, j));
                    points_mapping[i][j] = cookie;
                    cookie++;
                }
            }
        }

        for (int i = 0; i < MAXDIRT; ++i) {
            graph[i].clear();
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for (vector<pair<int, int> >::iterator it = points.begin(); it != points.end(); ++it) {
            bool bio[h][w];
            memset(bio, 0, sizeof bio);

            queue<point> kju;
            kju.push(point(it->x, it->y, 0));
            bio[it->x][it->y] = true;
            while (!kju.empty()) {
                point p = kju.front(); kju.pop();

                for (int i = 0; i < 4; ++i) {
                    int x = p.x+dx[i], y = p.y+dy[i];
                    if (x >= 0 && x < h && y >= 0 && y < w
                          && map[x][y] != 'x'
                          && !bio[x][y]) {

                        bio[x][y] = true;
                        kju.push(point(x, y, p.dist+1));

                        if (map[x][y] == '*') {
                            graph[points_mapping[it->x][it->y]].push_back(make_pair(points_mapping[x][y], p.dist+1));
                        }
                    }
                }
            }
        }

        // int idx = beginning.x*MAXN+beginning.y;

        // mask
        memset(dp, -1, sizeof dp);
        
        int sol = rec(1<<source, source);
        if (sol == inf) printf("%d\n", -1);
        else printf("%d\n", sol);
    }
    
    return 0;
}
