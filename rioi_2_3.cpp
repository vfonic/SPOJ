#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>

#define MAX 51

using namespace std;

int n, sx, sy, ex, ey;
int a[MAX][MAX];
bool bio[MAX][MAX];
queue<pair<int, int> > red;
bool platio[11];

bool kreni()
{
    // bfs-om hodaj po matrici od (sx, sy) do (ex, ey)
    // while (!red.empty())
    //     red.pop();
    queue<pair<int, int> > red;
    red.push(make_pair(sx, sy));
    
    memset(bio, 0, sizeof bio);
    
    
    while (!red.empty())
    {
        pair<int, int> trenutni = red.front();
        red.pop();
        
        int x = trenutni.first, y = trenutni.second;
        
        if (x == ex && y == ey)
        {
            return true;
        }
        
        if (bio[x][y])
            continue;
        
        bio[x][y] = true;
        
        if (x - 1 >= 0 && !bio[x - 1][y])
        {
            if (platio[a[x - 1][y]])
            {
                red.push(make_pair(x - 1, y));
            }
        }
        if (y - 1 >= 0 && !bio[x][y - 1])
        {
            if (platio[a[x][y - 1]])
            {
                red.push(make_pair(x, y - 1));
            }
        }
        if (x + 1 < n && !bio[x + 1][y])
        {
            if (platio[a[x + 1][y]])
            {
                red.push(make_pair(x + 1, y));
            }
        }
        if (y + 1 < n && !bio[x][y + 1])
        {
            if (platio[a[x][y + 1]])
            {
                red.push(make_pair(x, y + 1));
            }
        }
    }
    
    return false;
}

int main(int argc, char *argv[])
{
    cin.sync_with_stdio(false);
    
    int t;
    
    cin >> t;
    
    int limit = 1 << 10;
    
    for (int asfklj = 0; asfklj < t; ++asfklj)
    {
        cin >> n;
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> a[i][j];
            }
        }
        
        cin >> sx >> sy >> ex >> ey;
        
        int sol = 11;
        int pocetna_banda = (1 << a[sx][sy]), krajnja_banda = (1 << a[ex][ey]);
        for (int bitmaska = 1; bitmaska < limit; ++bitmaska)
        {
            // je li a[sx][sy], a[ex][ey] u bit maski?
            if (bitmaska & pocetna_banda
                && bitmaska & krajnja_banda)
            {
                memset(platio, 0, sizeof platio);
                // rastavi bit masku
                int koji_gledamo = 1;
                int i = 0;
                int size = 0;
                while (koji_gledamo < limit)
                {
                    if (bitmaska & koji_gledamo)
                    {
                        ++size;
                        platio[i] = true;
                    }
                    koji_gledamo <<= 1;
                    ++i;
                }
                
                if (size < sol && kreni())
                    sol = size;
            }
        }
        
        cout << sol << endl;
    }
    
    return 0;
}