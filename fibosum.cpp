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
#define MOD 1000000007
#define fill(a,b) a[0][0] = b[0][0]; a[0][1] = b[0][1]; a[1][0] = b[1][0]; a[1][1] = b[1][1];

using namespace std;

void mul(long long fib[2][2], long long base[2][2]) {
    long long mat[2][2];
    fill(mat, fib);

    mat[0][0] = (fib[0][0]*base[0][0] + fib[0][1]*base[1][0]) % MOD;
    mat[0][1] = (fib[1][0]*base[0][0] + fib[1][1]*base[1][0]) % MOD;
    mat[1][0] = (fib[0][0]*base[0][1] + fib[0][1]*base[1][1]) % MOD;
    mat[1][1] = (fib[1][0]*base[0][1] + fib[1][1]*base[1][1]) % MOD;

    fill(fib, mat);
}

void calculate_fibonacci_matrix(long long fib[2][2], int n) {
    long long base[2][2] = {{1, 1}, {1, 0}};
    // fib = I
    // [1  0]
    // [0  1]
    fib[0][0] = 1; fib[0][1] = 0; fib[1][0] = 0; fib[1][1] = 1;

    while (n) {
        if (n&1) mul(fib, base);
        mul(base, base);
        n >>= 1;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    int n, m;
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        scanf("%d%d", &n, &m);
        
        long long fib[2][2];
        calculate_fibonacci_matrix(fib, n);
        long long fn = fib[0][1], fn_1 = fib[1][1];

        calculate_fibonacci_matrix(fib, m-n+2);

        int sum = ((fib[0][0]-1)*fn + (fib[0][1]-1)*fn_1) % MOD;

        printf("%d\n", sum);
    }
    
    return 0;
}
