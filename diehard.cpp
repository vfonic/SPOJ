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

int main() {
    int t;
    scanf("%d", &t);
    
    int h, a;
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        scanf("%d%d", &h, &a);

        int sol = 1;
        while (h > 0 && a > 0) {
            while (a <= 8 && h > 17) {
                sol += 2;
                h -= 17;
                a += 7;
            }

            int mini = min((h-1)/2, (a-1)/8);
            if (!mini) break;
            sol += mini*2;
            h -= mini*2;
            a -= mini*8;
        }

        printf("%d\n", sol);
    }
    
    return 0;
}
