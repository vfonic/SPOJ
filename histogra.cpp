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

using namespace std;

struct event {
    int position;
    long long height;
    event (int _position, long long _height) { position = _position; height = _height; }
};

bool operator<(event a, event b) {
    return a.height < b.height;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    while(n != 0) {
        vector<event> events;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            events.push_back(event(i, x));
        }
        sort(events.begin(), events.end());
      
        set<int> indexes;
        long long sol = events[0].height * n;
        indexes.insert(events[0].position);
      
        for (vector<event>::iterator it = events.begin()+1; it != events.end(); ++it) {
            long long tmp_sol;
            set<int>::iterator sit = indexes.lower_bound(it->position);
            if (sit == indexes.end()) {
                --sit;
                tmp_sol = (n - *sit - 1) * it->height;
            } else if (sit == indexes.begin()) {
                tmp_sol = *sit * it->height;
            } else {
                set<int>::iterator lower_bound = sit;
                --lower_bound;
                tmp_sol = (*sit - *lower_bound - 1) * it->height;
            }
            if (tmp_sol > sol) sol = tmp_sol;
            indexes.insert(it->position);
        }
        printf("%lld\n", sol);
        
        scanf("%d", &n);
    }
    
    return 0;
}
