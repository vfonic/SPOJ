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

#define UP true
#define DOWN false

using namespace std;

int main()
{
    int n, k;
    
    scanf("%d %d\n", &n, &k);
    
    int i = 0, j = 0;
    long long sol = 1;
    long long cur = 1;
    bool dir = UP;
    for (int qwertz = 0; qwertz < k; ++qwertz) {
        char x;
        scanf("%c", &x);
        
        if (i+j < n) {
            if (x == 'R' && dir == UP) { // Right
                cur += 2*i+1;
                ++j;
            } else if (x == 'L' && dir == UP) { // Left
                cur -= 2*j;
                --j;
            } else if (x == 'U' && dir == UP) { // Up
                cur -= 2*j+1;
                --i;
            } else if (x == 'D' && dir == UP) { // Down
                cur += 2*i+2;
                ++i;
            } else if (x == 'R' && dir == DOWN) { // Right
                cur += 2*j+2;
                ++j;
            } else if (x == 'L' && dir == DOWN) { // Left
                cur -= 2*i+1;
                --j;
            } else if (x == 'U' && dir == DOWN) { // Up
                cur -= 2*i;
                --i;
            } else if (x == 'D' && dir == DOWN) { // Down
                cur += 2*j+1;
                ++i;
            }
            
            if (i+j == n) cur--;
        }
        
        else { // i+j >= n
            if (x == 'R' && dir == UP) { // Right
                cur += (n-1-j)*2;
                ++j;
            } else if (x == 'L' && dir == UP) { // Left
                cur -= (n-1-i)*2+1;
                --j;
            } else if (x == 'U' && dir == UP) { // Up
                cur -= (n-1-i)*2+2;
                --i;
            } else if (x == 'D' && dir == UP) { // Down
                cur += (n-1-j)*2+1;
                ++i;
            } else if (x == 'R' && dir == DOWN) { // Right
                cur += (n-1-i)*2+1;
                ++j;
            } else if (x == 'L' && dir == DOWN) { // Left
                cur -= (n-1-j)*2+2;
                --j;
            } else if (x == 'U' && dir == DOWN) { // Up
                cur -= (n-1-j)*2+1;
                --i;
            } else if (x == 'D' && dir == DOWN) { // Down
                cur += (n-1-i)*2;
                ++i;
            }
        }
        
        sol += cur;
        dir = !dir;
    }
    printf("%lld\n", sol);
    return 0;
}
