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
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        long long term3, lastTerm3, sum;

        scanf("%lld%lld%lld", &term3, &lastTerm3, &sum);
        

        long long n;
        if ((term3+lastTerm3) & 1) n = 2*sum/(term3+lastTerm3);
        else                     n = sum/((term3+lastTerm3)/2);
        long long d = (sum - n*term3)/((n-3)*(n-2)/2 -3);

        long long a = term3 - 2*d;
        printf("%lld\n", n);
        for (int i = 0; i < n; ++i) {
            printf("%lld ", a);
            a += d;
        }
    }
    
    return 0;
}
