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
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    
    while (a) {
        if (a*a == b*b + c*c) printf("right\n");
        else if (b*b == a*a + c*c) printf("right\n");
        else if (c*c == a*a + b*b) printf("right\n");
        else printf("wrong\n");
        
        scanf("%d%d%d", &a, &b, &c);
    }
    
    return 0;
}
