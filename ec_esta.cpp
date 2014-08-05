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
#define MAXN 100001

using namespace std;

int minPQ[MAXN], maxPQ[MAXN];
int minPQ_N = 0, maxPQ_N = 0;
int N;

void swap(int *a, int *b) {
  int tmp = *a; *a = *b; *b = tmp;
}

void add_to_minPQ(int x) {
  minPQ[++minPQ_N] = x;

  int pos = minPQ_N;
  while (pos > 1 && minPQ[pos>>1] > minPQ[pos]) {
    swap(&minPQ[pos>>1], &minPQ[pos]);
    pos >>= 1;
  }
}

void add_to_maxPQ(int x) {
  maxPQ[++maxPQ_N] = x;

  int pos = maxPQ_N;
  while (pos > 1 && maxPQ[pos>>1] < maxPQ[pos]) {
    swap(&maxPQ[pos>>1], &maxPQ[pos]);
    pos >>= 1;
  }
}

void sink_in_minPQ(int x) {
  int pos = 1;
  minPQ[pos] = x;
  while (pos<<1 <= minPQ_N) {
    int pos2 = pos<<1;
    if (pos2 < minPQ_N && minPQ[pos2] > minPQ[pos2+1]) ++pos2;
    if (minPQ[pos2] < minPQ[pos]) {
      swap(&minPQ[pos2], &minPQ[pos]);
      pos = pos2;
    } else break;
  }
}

void sink_in_maxPQ(int x) {
  int pos = 1;
  maxPQ[pos] = x;
  while (pos<<1 <= maxPQ_N) {
    int pos2 = pos<<1;
    if (pos2 < maxPQ_N && maxPQ[pos2] < maxPQ[pos2+1]) ++pos2;
    if (maxPQ[pos2] > maxPQ[pos]) {
      swap(&maxPQ[pos2], &maxPQ[pos]);
      pos = pos2;
    } else break;
  }
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
      scanf("%d", &N);
      minPQ_N = 0;
      maxPQ_N = 0;
      
      for (int i = 1; i <= N; ++i) {
        int x;
        scanf("%d", &x);

        if (i & 1) {
          if (maxPQ_N == 0 || x < minPQ[1])
            add_to_maxPQ(x);
          else {
            add_to_maxPQ(minPQ[1]);
            sink_in_minPQ(x);
          }
          printf("%d\n", maxPQ[1]);
        } else {
          if (x > maxPQ[1]) {
            add_to_minPQ(x);
          } else {
            add_to_minPQ(maxPQ[1]);
            sink_in_maxPQ(x);
          }
          unsigned int median_sum = minPQ[1] + maxPQ[1];
          if (median_sum & 1) {
              printf("%d.5\n", median_sum>>1);
          } else {
              printf("%d\n", median_sum>>1);
          }
        }
      }
    }

    return 0;
}
