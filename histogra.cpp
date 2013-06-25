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

struct brick {
    int index, left;
    long long height;
    brick(int _index, long long _height, int _left) { index = _index; height = _height; left = _left; }
    brick() {}
};

int main()
{
    cin.sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    
    brick top;
    do {
        long long x;
        long long sol = 0;
        stack<brick> stog; // index, height, left
        
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &x);
            
            while (!stog.empty() && (top = stog.top()).height > x) {
                if (sol < top.height * (i-top.left)) sol = top.height * (i-top.left);
                stog.pop();
            }
            if (stog.empty())
                stog.push(brick(i, x, 0));
            else stog.push(brick(i, x, top.index+1));
        }
        
        brick last_pair;
        while (!stog.empty()) {
            last_pair = stog.top();
            if (sol < last_pair.height * (n-last_pair.left)) sol = last_pair.height * (n-last_pair.left);
            stog.pop();
            if (stog.empty() && sol < last_pair.height * n) sol = last_pair.height * n;
        }
        
        printf("%lld\n", sol);
        
        scanf("%d", &n);
    } while(n);
    
    return 0;
}
