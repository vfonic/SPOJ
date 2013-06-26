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
#define MAXN 4000

using namespace std;

struct brick {
    int index, height, left;
    brick(int _index, int _height, int _left) { index = _index; height = _height; left = _left; }
    brick() {}
};

int main()
{
    cin.sync_with_stdio(false);
    int m,n,f;
    scanf("%d%d", &m, &n);
    if (m == n && m == 0) return 0;
    scanf("%d", &f);
    
    int height[MAXN];
    char farm[MAXN];
    do {
        memset(height, 0, sizeof height);
        
        stack<brick> stog;
        brick top;
        int sol = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%s", farm);
            for (int j = 0; j < n; ++j) {
                if (farm[j] == 'C') {
                    height[j] = 0;
                } else {
                    ++height[j];
                }
                
                while(!stog.empty() && (top = stog.top()).height > height[j]) {
                    if (sol < top.height * (j-top.left)) {
                        sol = top.height * (j-top.left);
                    }
                    stog.pop();
                }
                if (stog.empty()) stog.push(brick(j, height[j], 0));
                else stog.push(brick(j, height[j], top.index+1));
            }
            while (!stog.empty()) {
                brick last_element = stog.top();
                stog.pop();
                if (sol < last_element.height * (n-last_element.left)) {
                    sol = last_element.height * (n-last_element.left);
                }
            }
        }
        
        printf("%lld\n", (long long)sol*f);
        
        scanf("%d%d", &m, &n);
        if (m == n && m == 0) return 0;
        scanf("%d", &f);
    } while(m != 0);
    
    return 0;
}
