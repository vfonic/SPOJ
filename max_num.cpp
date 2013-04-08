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
#define MAXN 100001

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        int number[MAXN];
        vector<int> digits[10];
        int n, k;
        char number_array[MAXN];
        scanf("%s%d", &number_array[0], &k);
        
        for (n = 0; number_array[n]; ++n) {
            number[n] = number_array[n] - '0';
            digits[number[n]].push_back(n);
        }
        
        if (n == k) { printf("\n"); continue; }
        
        int current[10] = {0};
        int last_index = -1, removed = 0, printed = 0, max_printed = n-k;
        for (int i = 9; i >= 0; --i) {
            while ((int)digits[i].size() > current[i] && digits[i][current[i]] < last_index) {
                ++current[i];
            }
            
            if ((int)digits[i].size() <= current[i]) continue;
            
            if (digits[i][current[i]] - removed - printed <= k) {
                last_index = digits[i][current[i]];
                k -= digits[i][current[i]] - printed - removed;
                removed = digits[i][current[i]] - printed;
                ++current[i];
                ++printed;
                printf("%d", i);
                if (printed == max_printed) {
                    break;
                }
                i = 10;
            }
        }
        printf("\n");
    }
    
    return 0;
}
