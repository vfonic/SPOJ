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

#define MAXN 1000000000

using namespace std;

set<int> beehives;

void precalculate_beehives() {
    int sum = 1;
    int i = 0;
    while (sum < MAXN) {
        beehives.insert(sum);
        i += 6;
        sum += i;
    }
}

int main() {
    
    precalculate_beehives();
    
    int t;
    scanf("%d", &t);
    
    while (t != -1) {
        beehives.find(t) != beehives.end() ? printf("Y\n") : printf("N\n");
        scanf("%d", &t);
    }
    
    return 0;
}
