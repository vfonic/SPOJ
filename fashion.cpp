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

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    int t;
    
    cin >> t;
    
    for (int qwertz = 0; qwertz < t; ++qwertz)
    {
        int n;
        cin >> n;
        
        int x[n], y[n];
        for (int j = 0; j < n; ++j)
        {
            cin >> x[j];
        }
        for (int j = 0; j < n; ++j)
        {
            cin >> y[j];
        }
        sort(x, x+n);
        sort(y, y+n);
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += x[i] * y[i];
        }
        cout << sum << endl;
    }
    
    return 0;
}
