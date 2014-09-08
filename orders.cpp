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
#define MAXN 200000

using namespace std;

struct node {
    node *left;
    node *right;
    int size;
    int val;
    node(int _v) { val = _v; size = 1; left = NULL; right = NULL; }
};

void construct_bst(vector<int> *nodes, int n) {
    int step = 2;
    int val = 1;

    while(val <= n) {
        while(val <= n) {
            nodes->push_back(val);
            val += step;
        }
        val = step;
        step <<= 1;
    }
}

node* insert(node *current_node, int val) {
    if (current_node == NULL) return new node(val);

    if (val < current_node->val) current_node->left = insert(current_node->left, val);
    else current_node->right = insert(current_node->right, val);

    current_node->size++;
    return current_node;
}

node* select(node *current_node, int k) {
    if (current_node == NULL) return NULL;
    int left_size = current_node->left != NULL ? current_node->left->size : 0;
    if (left_size > k) {
        return select(current_node->left, k);
    } else if (left_size < k) {
        return select(current_node->right, k - left_size - 1);
    } else {
        return current_node;
    }
}

int size(node* current_node) {
    if (current_node == NULL) return 0;
    return current_node->size;
}

node* deleteMin(node* current_node) {
    if (current_node == NULL) return NULL;
    if (current_node->left == NULL) return current_node->right;
    current_node->left = deleteMin(current_node->left);
    current_node->size--;
    return current_node;
}

node* remove(node *current_node, int val) {
    if (current_node == NULL) return NULL;
    if (val < current_node->val) {
        current_node->left = remove(current_node->left, val);
    } else if (val > current_node->val) {
        current_node->right = remove(current_node->right, val);
    } else {
        if (current_node->left == NULL) return current_node->right;
        if (current_node->right == NULL) return current_node->left;
        node *t = current_node;
        current_node = current_node->right;
        while (current_node->left != NULL) {
            current_node = current_node->left;
        }
        current_node->right = deleteMin(t->right);
        current_node->left = t->left;
    }
    current_node->size = 1 + size(current_node->left) + size(current_node->right);
    return current_node;
}

int main() {
    int t;
    scanf("%d", &t);

    int n;
    int soldiers[MAXN];
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        scanf("%d", &n);
        
        for (int i = 0; i < n; ++i) {
            scanf("%d", &soldiers[i]);
        }

        vector<int> nodes;
        construct_bst(&nodes, n);
        reverse(nodes.begin(), nodes.end());
        
        node *root = NULL;
        for (int i = 0; i < (int)nodes.size(); ++i) {
            root = insert(root, nodes[i]);
        }

        vector<int> sol;
        for (int i = n-1; i >= 0; --i) {
            node* kth_node = select(root, i-soldiers[i]);
            root = remove(root, kth_node->val);
            sol.push_back(kth_node->val);
        }
        reverse(sol.begin(), sol.end());

        for (int i = 0; i < (int)sol.size(); ++i) {
            printf("%d ", sol[i]);
        }
        printf("\n");
    }
    
    return 0;
}
