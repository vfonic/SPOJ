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
    double n;
    
    scanf("%lf", &n);
    while (n != 0.0) {
        double sol = 0;
        int br = 1;
        while (sol < n) {
            ++br;
            sol += 1./br;
        }
        printf("%d card(s)\n", br-1);
        scanf("%lf", &n);
    }
    
    return 0;
}
