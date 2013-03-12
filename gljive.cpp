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
    int array[10], sum = 0;
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &array[i]);
        sum += array[i];
        if (sum >= 100) {
            if (sum - 100 <= 100 - (sum-array[i])) printf("%d\n", sum);
            else printf("%d\n", sum-array[i]);
            return 0;
        }
    }
    printf("%d\n", sum);
    return 0;
}
