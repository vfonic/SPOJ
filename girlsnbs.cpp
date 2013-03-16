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
    int g, b;
    scanf("%d%d", &g, &b);
    
    while(g != -1) {
        int G, B;
        G = max(g,b);
        B = min(g,b);
        
        int sol = G / (B+1) + (G % (B+1) > 0);
        printf("%d\n", sol);
        
        scanf("%d%d", &g, &b);
    }
    
    
    return 0;
}
