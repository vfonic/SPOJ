#define _USE_MATH_DEFINES
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
#include <iomanip>

#define inf 1000000000

using namespace std;

int main()
{
    int l;
    
    while (true)
    {
        scanf("%d", &l);
        if (l == 0)
            break;
        
        double x = (l * l) / (2 * M_PI);
        printf("%.2lf\n", x);
    }
    
    return 0;
}
