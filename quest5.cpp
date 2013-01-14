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

int cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    int t;
    
    scanf("%d", &t);
    
    for (int qwertz = 0; qwertz < t; ++qwertz)
    {
        int n;
        scanf("%d", &n);
        vector<pair<int, int> > letve;
        
        for (int i = 0; i < n; ++i)
        {
            int poc, kraj;
            scanf("%d%d", &poc, &kraj);
            letve.push_back(make_pair(poc, kraj));
        }
        
        sort(letve.begin(), letve.end(), cmp);
        
        int sol = 1;
        int last = letve[0].second;
        for (vector<pair<int, int> >::iterator it = letve.begin(); it != letve.end(); ++it) {
            if ((*it).first > last) {
                ++sol;
                last = (*it).second;
            }
        }
        
        printf("%d\n", sol);
    }
    return 0;
}








