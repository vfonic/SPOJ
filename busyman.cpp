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
#define EVENT_START 1
#define EVENT_END 0

using namespace std;

struct event {
    int type, time, id;
    event(int _time, int _type, int _id) { time = _time; type = _type; id = _id; }
};

bool operator<(event a, event b) {
    if (a.time != b.time) return a.time < b.time;
    return a.type < b.type;
}

int main()
{
    int t;
    
    scanf("%d", &t);
    
    for (int qwertz = 0; qwertz < t; ++qwertz) {
        int n;
        scanf("%d", &n);
        
        bool crossed_events[n];
        memset(crossed_events, 0, sizeof crossed_events);
        vector<event> eventovi;
        for (int i = 0; i < n; ++i) {
            int start, end;
            scanf("%d%d", &start, &end);
            
            eventovi.push_back(event(start, EVENT_START, i));
            eventovi.push_back(event(end, EVENT_END, i));
        }
        
        sort(eventovi.begin(), eventovi.end());
        
        vector<int> open_events;
        int sol = 0;
        for (vector<event>::iterator it = eventovi.begin(); it != eventovi.end(); ++it) {
            if (it->type == EVENT_START) open_events.push_back(it->id);
            else if (!crossed_events[it->id]) {
                for (vector<int>::iterator it2 = open_events.begin(); it2 != open_events.end(); ++it2) {
                    crossed_events[*it2] = true;
                }
                ++sol;
                open_events.clear();
            }
        }
        
        printf("%d\n", sol);
    }
    
    return 0;
}
