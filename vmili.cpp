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

using namespace std;

typedef pair<int, int> point;

#define x first
#define y second

int ccw(point a, point b, point c) {
    return (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);
}

vector<point> points;
int n;

vector<point> envelope(int p) {
    vector<point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for (int i = 2; i < n; ++i) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), points[i]) * p > 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}

int main() {
    scanf("%d", &n);
    
    points.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &points[i].x, &points[i].y);
    }

    sort(points.begin(), points.end());

    int sol = 0;
    while(points.size() > 2) {
        ++sol;
        vector<point> upper_envelope = envelope(+1);
        vector<point> lower_envelope = envelope(-1);

        // points[0], points[n-1]
        // upper & lower_envelope
        vector<point> new_points;

        vector<point>::iterator l_it = lower_envelope.begin();
        vector<point>::iterator u_it = upper_envelope.begin() + 1;
        for (vector<point>::iterator it = points.begin(); it != points.end(); ++it) {
            if (l_it != lower_envelope.end() && *it == *l_it) { ++l_it; continue; }
            if (u_it != upper_envelope.end() && *it == *u_it) { ++u_it; continue; }
            new_points.push_back(*it);
        }

        points = new_points;
        // for (vector<point>::iterator it = points.begin(); it != points.end(); ++it) {
        //     printf("(%d, %d)\t", it->x, it->y);
        // }
        // printf("%d\n", points.empty());
    }

    printf("%d\n", sol);

    return 0;
}
