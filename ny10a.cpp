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

int main()
{
    int t;
    
    scanf("%d", &t);
    
    string sequences[] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
    for (int qwertz = 1; qwertz <= t; ++qwertz) {
        int x;
        scanf("%d\n", &x);
        string coin_tosses_result;
        getline(cin, coin_tosses_result);
        printf("%d ", qwertz);
        for (int i = 0; i < 8; ++i) {
            int match = 0;
            size_t found = coin_tosses_result.find(sequences[i]);
            while (found != string::npos) {
                ++match;
                found = coin_tosses_result.find(sequences[i], found+1);
            }
            if (i < 7) printf("%d ", match);
            else printf("%d\n", match);
        }
    }
    
    return 0;
}
