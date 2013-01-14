#include <iostream>
#include <queue>
#include <set>
#include <climits>

#define LIMIT 182
using namespace std;

struct xy_and_distance
{
    int x; int y; int distance;
    xy_and_distance(int _x, int _y, int _distance)
    {
        x = _x;
        y = _y;
        distance = _distance;
    }
};

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int main(int argc, char const *argv[])
{
    int t;
    
    cin >> t;
    
    int n, m;
    char y[LIMIT][LIMIT];
    for (int kl = 0; kl < t; ++kl)
    {
        cin >> n >> m;
        
        queue<xy_and_distance> kju;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> y[i][j];
                if (y[i][j] == '1')
                    kju.push(xy_and_distance(i, j, 0));
            }
        }
        
        int rjesenje[LIMIT][LIMIT] = {0};
        
        int bio[LIMIT][LIMIT] = {0};
        while(!kju.empty())
        {
            xy_and_distance par = kju.front();
            kju.pop();
            int i = par.x;
            int j = par.y;
            int distance = par.distance;
            
            if (bio[i][j])
                continue;
            
            rjesenje[i][j] = distance;
            bio[i][j] = 1;
            
            for (int k = 0; k < 4; ++k)
            {
                if (i + dx[k] >= 0 && j + dy[k] >= 0
                 && i + dx[k] < n && j + dy[k] < m
                 && !bio[i + dx[k]][j + dy[k]])
                    kju.push(xy_and_distance(i + dx[k], j + dy[k], distance + 1));
            }
        }
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << rjesenje[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
