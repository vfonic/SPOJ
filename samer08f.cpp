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
#include <string>
#include <vector>

#define inf 1000000000
#define MAXN 100000

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    while(n) {
        int sol = 0;
        for (int i = 0; i < n; ++i) {
            sol += (n-i)*(n-i);
        }
        printf("%d\n", sol);
        
        scanf("%d", &n);
    }
    
    
    return 0;
}
