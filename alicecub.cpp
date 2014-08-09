#include <algorithm>
#include <bitset>
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
#define MAXN 1 << 16

using namespace std;

int a[MAXN];
int adjecency_matrix[16][16] =
{
 { 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
 { 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
 { 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
 { 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
 { 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
 { 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
 { 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
 { 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
 { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0 },
 { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0 },
 { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0 },
 { 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1 },
 { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0 },
 { 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1 },
 { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
 { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0 },
};

void preprocess_solution() {
	a[(1<<8)-1] = 0;

	queue<pair<int, int> > kju;
	kju.push(make_pair((1<<8)-1, 0));

	while (!kju.empty()) {
		pair<int, int> par = kju.front(); kju.pop();
		
    for (int i = 0; i < 16; ++i) {
      int bit = (1<<(16-i-1));
      if (bit & par.first) {
        for (int j = 0; j < 16; ++j) {
          if (adjecency_matrix[i][j]) {
            int idx = (par.first & ~bit) | (1<<(16-j-1));
            if (a[idx] == -1 && par.second < 3) {
              a[idx] = par.second+1;
              kju.push(make_pair(idx, par.second+1));
            }
          }
        }
      }
    }
	}
}

int main() {
    int t;
    scanf("%d", &t);

    memset(a, -1, sizeof a);
    
    preprocess_solution();
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
      int idx = 0;
      for (int i = 0; i < 16; ++i) {
        int x;
        scanf("%d", &x);
        if (x)
          idx |= (1<<(16-i-1));
      }

      if (a[idx] == -1)
        printf("Case #%d: more\n", qwertz+1);
      else
        printf("Case #%d: %d\n", qwertz+1, a[idx]);
    }

    return 0;
}
