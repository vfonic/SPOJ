#include <algorithm>
#include <bitset>
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
#define MAXN 1<<10

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    char num[20];
    int mat[MAXN] = {0};
    long long sol = 0;
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        scanf("%s", num);

        int mask = 0;
        for (int i = 0; num[i] != '\0'; ++i) {
            mask |= 1<<(num[i]-'0');
        }

        sol += mat[mask];
        ++mat[mask];
    }

    for (int i = 0; i < MAXN; ++i) {
        for (int j = i+1; j < MAXN; ++j) {
            if (i & j) {
              sol += (long long)mat[i] * mat[j];
            }
        }
    }
    
    printf("%lld\n", sol);
    return 0;
}
