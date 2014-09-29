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
    
    double rr, rsc, rp, rl, rsp,
        sr, ssc, sp, sl, ssp;
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        scanf("%lf%lf%lf%lf%lf", &rr, &rsc, &rp, &rl, &rsp);
        scanf("%lf%lf%lf%lf%lf", &sr, &ssc, &sp, &sl, &ssp);

        rr /= 100; rsc /= 100; rp /= 100; rl /= 100; rsp /= 100; sr /= 100; ssc /= 100; sp /= 100; sl /= 100; ssp /= 100;

        double p_rajesh, p_tie, p_sheldon;
        p_tie = rr*sr + rsc*ssc + rp*sp + rl*sl + rsp*ssp;
        p_rajesh = rr*sl + rr*ssc + rsc*sp + rsc*sl + rp*sr + rp*ssp + rl*ssp + rl*sp + rsp*ssc + rsp*sr;
        p_sheldon = 1 - p_rajesh - p_tie;

        if (p_tie == 1 || p_sheldon == 1) {
            printf("0\n");
            continue;
        }

        double geometric_sum = 1/(1-p_tie);
        double sol = p_rajesh*p_rajesh*geometric_sum*geometric_sum + p_rajesh*p_sheldon*p_rajesh*2*geometric_sum*geometric_sum*geometric_sum;
        sol *= 100;

        printf("%.0lf\n", sol);
    }
    
    return 0;
}
