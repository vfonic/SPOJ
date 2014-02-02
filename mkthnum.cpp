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

#define MAXNUM 1000000000
#define MAXN 100000

using namespace std;

struct cvor {
    int a[MAXN];
};

int n;
vector<cvor> tournament_tree;
int offset;
int ttre_rows;

int how_many_smaller_numbers(int broj, int lo, int hi, int from = 0, int to = offset, int idx = 0) {
    if (from >= hi || to <= lo) return 0;
    if (lo <= from && to <= hi) {
        int l = from, h = to;
        int mid;
        while (l < h) {
            mid = l + (h - l)/2;
            if (tournament_tree[idx].a[mid] <= broj) {
                l = mid+1;
            } else
                h = mid;
        }
        return l - from;
    }

    int x = how_many_smaller_numbers(broj, lo, hi, from, (from+to)/2, idx+1) + how_many_smaller_numbers(broj, lo, hi, (from+to)/2, to, idx+1);
    return x;
}

void merge(int idx, int lo, int mid, int hi) {
    for (int k = lo; k <= hi && k < n; k++) {
        tournament_tree[idx].a[k] = tournament_tree[idx+1].a[k];
    }

    int i = lo, j = mid+1;
    for (int k = lo; k <= hi && k < n; k++) {
        if      (i > mid)         tournament_tree[idx].a[k] = tournament_tree[idx+1].a[j++];
        else if (j > hi || j >= n)          tournament_tree[idx].a[k] = tournament_tree[idx+1].a[i++];
        else if (tournament_tree[idx+1].a[j] < tournament_tree[idx+1].a[i]) tournament_tree[idx].a[k] = tournament_tree[idx+1].a[j++];
        else                      tournament_tree[idx].a[k] = tournament_tree[idx+1].a[i++];
    }
}

void sort(int i, int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    sort(i+1, lo, mid);
    sort(i+1, mid+1, hi);
    merge(i, lo, mid, hi);
}

void merge_sort() {
    sort(0, 0, offset-1);
}

int main() {
    int m;
    scanf("%d%d", &n, &m);

    ttre_rows = ceil(log2(n))+1;
    tournament_tree = vector<cvor>(ttre_rows, cvor());

    offset = 1;
    while (offset < n)
        offset <<= 1;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &tournament_tree[ttre_rows-1].a[i]);
    }

    merge_sort();

    int i, j, k;
    for (int qwe = 0; qwe < m; ++qwe) {
        scanf("%d%d%d", &i, &j, &k);
        --i;

        int lo = -MAXNUM, hi = MAXNUM;
        int mid;
        int br = 0;
        while (br++ < 35) {
            mid = lo + (hi - lo) / 2;
            int x = how_many_smaller_numbers(mid, i, j);
            if (x < k) {
                lo = mid+1;
            } else if (x >= k) {
                hi = mid-1;
            }
        }
        printf("%d\n", mid);
    }
    return 0;
}
