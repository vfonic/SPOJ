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

#define inf 2000000000
#define MAXN 100000

using namespace std;

struct node {
    int value, idx;
    node *left;
    node *right;
    node(int val, int i) { value = val; idx = i; left=right=NULL; }
};

node *insert(int elem, int i, node *current_node) {
    if (current_node == NULL) current_node = new node(elem, i);
    else if (elem < current_node->value) current_node->left = insert(elem, i, current_node->left);
    else current_node->right = insert(elem, i, current_node->right);
    return current_node;
}

node *floor(int val, node *current_node) {
    if (current_node == NULL) return NULL;
    if (current_node->value == val) return current_node;
    else if (val < current_node->value) {
        return floor(val, current_node->left);
    } else {
        node *right = floor(val, current_node->right);
        if (right != NULL) return right;
        return current_node;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        int N, K, P;
        scanf("%d%d%d", &N, &K, &P);
        
        int a[N];
        node *root = NULL;
        int sum = 0;
        int sol = inf;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &a[i]);
            if (a[i] >= P) a[i] %= P;
            sum += a[i];
            if (sum >= P) sum -= P;
            if (sum >= K && sum < sol) sol = sum;

            int pod = (sum - K + P)%P;
            node *florr = floor(pod, root);
            if (florr != NULL && (sum - florr->value + P)%P < sol && (sum - florr->value + P)%P >= K) {
                sol = (sum - florr->value + P)%P;
            }
            root = insert(sum, i, root);
        }
        printf("%d\n", sol);
    }
    
    return 0;
}
