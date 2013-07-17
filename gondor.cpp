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
#define MAXN 101

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    vector<pair<double, int> > graph[MAXN]; // distance, to
    int arrows_nr[MAXN];
    pair<int, int> coordinates[MAXN];
    int order[MAXN][MAXN];
    for (int node = 0; node < t; ++node) {
        int x, y, arrws_nr;
        scanf("%d%d%d", &x, &y, &arrws_nr);
        coordinates[node] = make_pair(x, y);
        arrows_nr[node] = arrws_nr;

        for (int i = 0; i < t-1; ++i) {
            scanf("%d", &order[node][i]);
            --order[node][i];
        }
    }

    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t-1; ++j) {
        	pair<int, int> next = coordinates[order[i][j]];
        	pair<int, int> node = coordinates[i];
            double dist = sqrt((node.first-next.first)*(node.first-next.first)+(node.second-next.second)*(node.second-next.second));
            graph[i].push_back(make_pair(dist, order[i][j]));
        }
    }

    double distance[MAXN] = {0};

    set<pair<double, int> > priority_queue;
    bool zapalio[MAXN] = {false};
    priority_queue.insert(make_pair(0, 0));
    while (!priority_queue.empty()) {
        int node = priority_queue.begin()->second;
        priority_queue.erase(priority_queue.begin());
        zapalio[node] = true;

        for (int i = 0; i < (int)graph[node].size(); ++i) {
            int next = graph[node][i].second;
            if (arrows_nr[node] && !zapalio[next]) {
            	if (distance[next] == 0 || distance[node] + graph[node][i].first < distance[next]) {
	            	priority_queue.erase(make_pair(distance[next], next));
	                distance[next] = distance[node] + graph[node][i].first;
	                priority_queue.insert(make_pair(distance[next], next));
	            }
                --arrows_nr[node];
        	}
        }
    }

    for (int i = 0; i < t; ++i) {
        printf("%.6lf\n", distance[i]);
    }
    
    return 0;
}
