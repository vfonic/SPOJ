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
#define MAXN 51

using namespace std;

int H, W;
char mat[MAXN][MAXN];
int sol_mat[MAXN][MAXN];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int dfs(int row, int col, char letter) {
    if (sol_mat[row][col] != -1) return sol_mat[row][col];

    int curr_pos_sol = 1;
    for (int i = 0; i < 8; ++i) {
        if (row+dx[i] < 0 || row+dx[i] >= H || col+dy[i] < 0 || col+dy[i] >= W) continue;

        if (mat[row+dx[i]][col+dy[i]] == letter) {
            curr_pos_sol = max(curr_pos_sol, 1+dfs(row+dx[i], col+dy[i], letter+1));
        }
    }

    sol_mat[row][col] = curr_pos_sol;
    return curr_pos_sol;
}

int main() {
    int _case = 0;
    while (true) {
        scanf("%d%d", &H, &W);
        if (!H && !W) return 0;

        int sol = 0;
        ++_case;
        memset(sol_mat, -1, sizeof sol_mat);
        for (int i = 0; i < H; ++i) {
            scanf("%s", mat[i]);
        }

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (mat[i][j] != 'A') continue;

                sol = max(sol, dfs(i, j, 'A'+1));
            }
        }

        printf("Case %d: %d\n", _case, sol);
    }
    
    return 0;
}
