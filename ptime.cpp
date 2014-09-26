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
#define MAXN 10001

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int a[MAXN];
    vector<pair<int, int> > primes;
    bool found;
    for (int i = 2; i <= n; ++i) {
        found = false;
        for (vector<pair<int, int> >::iterator it = primes.begin(); it != primes.end(); ++it) {
            --it->second;
            if (it->second == 0) {
                int nr = i;
                while (nr % it->first == 0) {
                    ++a[it->first];
                    nr /= it->first;
                }
                it->second = it->first;
                found = true;
            }
        }

        if (!found) {
            primes.push_back(make_pair(i, i));
            a[i] = 1;
        }
    }

    for (int i = 0; i < (int)primes.size(); ++i) {
        if (!i) printf("%d^%d", primes[i].first, a[primes[i].first]);
        else printf(" * %d^%d", primes[i].first, a[primes[i].first]);
    }
    printf("\n");
    
    return 0;
}
