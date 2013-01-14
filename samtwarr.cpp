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

struct cvor
{
    cvor *r, *l;
    int suma;
    cvor() { suma = 0; }
};

cvor *build(int l, int r) {
    cvor *root = new cvor();
    
    if (l == r) return root;
    
    root->l = build(l, (l+r)/2);
    root->r = build((l+r)/2 + 1, r);
    
    return root;
}

void update(cvor *root, int i, int l, int r, int v) {
    if (l > i || r < i) return;
    
    if (l == r) { root->suma = v; return; }
    
    update(root->l, i, l, (l+r)/2, v);
    update(root->r, i, (l+r)/2+1, r, v);
    
    root->suma = root->l->suma + root->r->suma;
}

void show(cvor *root, int i, int l, int r) {
    if (l > i || r < i) return;
    
    if (l == r) { printf("show(%d): %d\n", i, root->suma); return; }
    
    show(root->l, i, l, (l+r)/2);
    show(root->r, i, (l+r)/2+1, r);
}

int sum(cvor *root, int cvor_l, int cvor_r, int l, int r) {
    if (cvor_r < l || cvor_l > r) return 0;
    
    if (cvor_l >= l && cvor_r <= r) return root->suma;
    
    return sum(root->l, cvor_l, (cvor_l+cvor_r)/2, l, r) + sum(root->r, (cvor_l+cvor_r)/2 + 1, cvor_r, l, r);
}

void swap(cvor* &prvi, cvor* &drugi, int cvor_l, int cvor_r, int l, int r) {
    
    if (cvor_r < l || cvor_l > r) return;
    
    if (cvor_l >= l && cvor_r <= r) { swap(prvi, drugi); return; }
    
    swap(prvi->l, drugi->l, cvor_l, (cvor_l+cvor_r)/2, l, r);
    swap(prvi->r, drugi->r, (cvor_l+cvor_r)/2 + 1, cvor_r, l, r);
    
    prvi->suma = prvi->l->suma + prvi->r->suma;
    drugi->suma = drugi->l->suma + drugi->r->suma;
}

int main()
{
    int n, m;
    
    scanf("%d%d\n", &n, &m);
    
    cvor *left_root = build(0, n-1);
    cvor *right_root = build(0, n-1);
    
    for (int i = 0; i < m; ++i)
    {
        int action;
        scanf("%d\n", &action);
        
        if (action == 0) {
            // sum (arr, left, right)
            int arr, left, right;
            scanf("%d%d%d", &arr, &left, &right);
            cvor *root;
            if (arr == 0)
                root = left_root;
            else
                root = right_root;
            int suma = sum(root, 0, n-1, left, right);
            
            // output
            printf("%d\n", suma);
        } else if (action == 1) {
            // value (arr, idx, newValue)
            int arr, idx, newValue;
            scanf("%d%d%d", &arr, &idx, &newValue);
            cvor *root;
            if (arr == 0)
                root = left_root;
            else
                root = right_root;
            update(root, idx, 0, n-1, newValue);
        } else {
            // swap (left, right)
            int left, right;
            scanf("%d%d", &left, &right);
            swap(left_root, right_root, 0, n-1, left, right);
            // show(left_root, 0, 0, n-1);
        }
    }
    return 0;
}
