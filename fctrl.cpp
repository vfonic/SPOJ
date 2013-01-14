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
    
    int potencije_broja_pet[13];
    int potencija = 1;
    for (int i = 0; i < 13; ++i)
    {
        potencija *= 5;
        potencije_broja_pet[i] = potencija;
    }
    
    for (int qwertz = 0; qwertz < t; ++qwertz)
    {
        long long n;
        cin >> n;
        
        int i = 0;
        while (potencije_broja_pet[i] <= n)
        {
            ++i;
        }
        
        int sol = 0;
        for (int j = 0; j < i; ++j)
        {
            sol += n/potencije_broja_pet[j];
        }
        cout << sol << endl;
    }
    
    return 0;
}
