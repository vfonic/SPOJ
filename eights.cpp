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
        long long k;
        cin >> k;
        cout << (k - 1) * 250 + 192 << endl;
    }
    
    return 0;
}
