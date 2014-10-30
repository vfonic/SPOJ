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
    int n;
    scanf("%d", &n);
    getchar();
    
    char x;
    int A = 0, B = 0;
    for (int i = 0; i < n; ++i) {
        x = getchar();
        
        if (x == 'A') {
            A = min(B+1, A);
            B = min(B+1, A+1);
        } else {
            B = min(B, A+1);
            A = min(B+1, A+1);
        }
    }

    printf("%d\n", min(A, B+1));
    
    return 0;
}
