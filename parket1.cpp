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
    int R, B;
    scanf("%d%d", &R, &B);
    int a = (2+R/2+sqrt((2+R/2)*(2+R/2)-4*(R+B)))/2;
    int b = (2+R/2-sqrt((2+R/2)*(2+R/2)-4*(R+B)))/2;
    printf("%d %d\n", a, b);
    
    return 0;
}
