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
#define swap(a,b) a^=b; b^=a; a^=b;

using namespace std;

int max_a,max_b,cap;
int pos;
bool found, breaking;

int up(int b = 0, int moves = 0) {
    if (b == cap) {
        found = true;
        breaking = true;
        pos = moves-2;
    }

    else if ((cap-b)%max_a == 0) {
        found = true;
        pos = moves + ((cap-b)/max_a)*2; //+2
    }

    if ((max_b-b)%max_a == 0) {
        moves += ((max_b-b)/max_a)*2;
        if (found) return min(moves-pos-2*breaking, pos);
        return -1;
    }

    int tmp = (max_b-b)/max_a + 1;
    b += tmp*max_a - max_b;
    moves += tmp*2 + 2;

    return up(b, moves);
}

int main() {
    int t;
    scanf("%d", &t);
    
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        scanf("%d%d%d", &max_a,&max_b,&cap);
        if (max_a > max_b) { swap(max_a, max_b); }

        if (cap == max_a || cap == max_b) { printf("1\n"); continue; }
        if (cap > max_b) { printf("-1\n"); continue; }

        found = breaking = false;

        printf("%d\n", up());
    }
    
    return 0;
}
