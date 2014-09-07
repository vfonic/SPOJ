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
#define MAXN 1000

using namespace std;

struct node {
    node *left;
    node *right;
    int left_cnt;
    int right_cnt;
    int val;
    node(int _v) { val = _v; left_cnt = 0; right_cnt = 0; left = NULL; right = NULL; }
};

struct person {
    int height;
    int nr_taller;
    person(int _height, int _nr_taller) { height = _height; nr_taller = _nr_taller; }
};

bool operator<(person a, person b) {
    return a.height < b.height;
}

int n;
int heights[MAXN];
int nr_tallers[MAXN];
vector<person> people;

node* dive(node *current_node, int count, int val) {
    if (current_node == NULL) return new node(val);

    if (count > current_node->left_cnt) {
        // go right
        current_node->right_cnt++;
        current_node->right = dive(current_node->right, count - current_node->left_cnt - 1, val);
    } else {
        // go left
        current_node->left_cnt++;
        current_node->left = dive(current_node->left, count, val);
    }

    return current_node;
}

void print_preorder(node *current_node) {
    if (current_node == NULL) return;
    print_preorder(current_node->left);
    printf("%d ", current_node->val);
    print_preorder(current_node->right);
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        scanf("%d", &n);
        
        people.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &heights[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nr_tallers[i]);
            people.push_back(person(heights[i], nr_tallers[i]));
        }

        sort(people.begin(), people.end());
        reverse(people.begin(), people.end());

        node *root = NULL;

        for (vector<person>::iterator it = people.begin(); it != people.end(); ++it) {
            root = dive(root, it->nr_taller, it->height);
        }

        print_preorder(root);
        printf("\n");
    }
    
    return 0;
}
