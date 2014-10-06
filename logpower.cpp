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

#define inf 2000000000

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    int t;
    
    cin >> t;
    
    for (int qwertz = 0; qwertz < t; ++qwertz)
    {
        long long N;
        long long A;
        int M;
        cin >> A >> N >> M;
        long long baza = A;
        
        --N;
        for ( ; N > 0; N >>= 1)
        {
            if (N & 1) A = (A * baza) % M;
            baza = (baza * baza) % M;
        }
        cout << A << endl;
    }
    
    return 0;
}
