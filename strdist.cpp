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
#define MAX 100001

using namespace std;

string a, b;
int dp[3][MAX];

int main()
{
    cin.sync_with_stdio(false);
    int l, k;
    
    cin >> l >> k;
    
    cin >> a >> b;
    
    for (int j = 1; j <= k; ++j)
    {
        dp[0][j] = j;
    }
    
    int tmp_min;
    for (int i = 1; i <= l; ++i)
    {
        dp[i%3][0] = i;
        int limit = min(k, i + 100);
        for (int j = max(i - 100, 1); j <= limit; ++j)
        {
            tmp_min = dp[(i+3-1)%3][j] + 1;
            
            if (tmp_min > dp[i%3][j-1] + 1)
                tmp_min = dp[i%3][j-1] + 1;
            
            if (a[i-1] == b[j-1]) // a[i] == b[j]
            {
                if (tmp_min > dp[(i+3-1)%3][j-1])
                    tmp_min = dp[(i+3-1)%3][j-1];
            }
            if (a[i-1] != b[j-1]) // a[i] != b[j]
            {
                if (tmp_min > dp[(i+3-1)%3][j-1] + 1)
                    tmp_min = dp[(i+3-1)%3][j-1] + 1;
            }
            
            if (i >= 2 && j >= 2 && a[i-2] == b[j-1] && a[i-1] == b[j-2])
            {
                if (tmp_min > dp[(i+3-2)%3][j-2] + 1)
                    tmp_min = dp[(i+3-2)%3][j-2] + 1;
            }
            
            dp[i%3][j] = tmp_min;
        }
    }
    
    cout << tmp_min << endl;
    return 0;
}
