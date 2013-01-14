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

vector<int> factoriel[100];

void izracunaj_faktorijele()
{
    int tmp = 0;
    int a[200] = {1};
    int m = 1;
    
    for (int i = 1; i <= 100; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            tmp = a[j] * i + tmp;
            a[j] = tmp % 10;
            tmp /= 10;
            
            factoriel[i-1].push_back(a[j]);
        }
        while (tmp > 0)
        {
            a[m] = tmp % 10;
            tmp /= 10;
            
            factoriel[i-1].push_back(a[m++]);
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    int t;
    
    cin >> t;
    
    izracunaj_faktorijele();
    
    for (int qwertz = 0; qwertz < t; ++qwertz)
    {
        int n;
        cin >> n;
        --n;
        for (vector<int>::reverse_iterator it = factoriel[n].rbegin(); it != factoriel[n].rend(); ++it)
        {
            cout << *it;
        }
        cout << "" << endl;
    }
    
    return 0;
}
