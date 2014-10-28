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

int tournament_tree[MAXN<<2];

int traverse_tournament(int i, int j, int left_t, int right_t, int pos = 1) {
    if (left_t >= j || right_t <= i) return 0;

    if (i <= left_t && right_t <= j) {
        return tournament_tree[pos];
    } else {
        int bound = left_t + (right_t-left_t)/2;
        int sol = max(traverse_tournament(i, j, left_t, bound, pos*2),
                   traverse_tournament(i, j, bound, right_t, pos*2+1));
        return sol;
    }
}

int main()
{
    int n,q;
    scanf("%d", &n);
    
    int a[MAXN];
    int right_qty[MAXN];
    int qty[MAXN<<1];
    while (n) {
        memset(qty, 0, sizeof qty);
        memset(tournament_tree, 0, sizeof tournament_tree);

        scanf("%d", &q);
        
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            ++qty[a[i]+MAXN];
            right_qty[i] = 1;
            if (i > 0 && a[i] == a[i-1]) right_qty[i] += right_qty[i-1];
        }

        // construct tournament tree
        int offset = 1;
        while (offset < n) {
            offset <<= 1;
        }

        for (int i = 0; i < n; i += qty[a[i]+MAXN]) {
            for (int j = 0; j < qty[a[i]+MAXN]; ++j) {
                tournament_tree[offset+i+j] = qty[a[i]+MAXN]-j;
            }
        }

        int pos = offset-1;
        while (pos) {
            tournament_tree[pos] = max(tournament_tree[pos*2], tournament_tree[pos*2+1]);
            --pos;
        }


        int i, j;
        for (int query = 0; query < q; ++query) {
            scanf("%d%d", &i, &j);
            --i, --j;

            int sol;
            if (right_qty[j] >= j-i+1) {
                sol = j-i+1;
            } else {
                sol = max(right_qty[j], traverse_tournament(i, j-right_qty[j]+1, 0, offset));
            }

            printf("%d\n", sol);
        }

        scanf("%d", &n);
    }
    
    return 0;
}
