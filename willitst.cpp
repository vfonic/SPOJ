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
    long long n;
    scanf("%lld", &n);
    long long n2 = n&-n;
    printf("%s\n", n == n2 ? "TAK" : "NIE");
    
    return 0;
}
