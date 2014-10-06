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
#define MAXN 100000

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    int a[t];
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        scanf("%d", &a[qwertz]);
    }

    int max_elms = 1;

    for (int i = 1; i < 1 << t; ++i) {
      int pok = 0;
      int mask = i;
      int el = INT_MIN;
      bool increasing = true;
      int elms = 0;
      while (mask) {
        if (mask&1) {
          if(a[pok] <= el) { increasing = false; break; }
          el = a[pok];
          ++elms;
        }
        mask >>= 1;
        ++pok;
      }
      if (increasing && elms > max_elms) max_elms = elms;
    }

    printf("%d\n", max_elms);
    
    return 0;
}
